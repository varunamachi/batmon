#include <Arduino.h>

int analogInput = 2;
float Vout = 0.00;
float Vin = 0.00;
float R1 = 22000.00; // resistance of R1 (100K)
float R2 = 10000.00;  // resistance of R2 (10K)
int val = 0;
int OFFSET = 100;

void setup()
{
    pinMode(analogInput, INPUT); //assigning the input port
    Serial.begin(9600);          //BaudRate
}

void loop() {
    val = analogRead(analogInput);
    //Some wiered extra 100 points that need be removed
    val = val - OFFSET;
    Vout = (val * 5) / 1024.00;
    Vin = Vout / (R2 / (R1 + R2)); 
    if (Vin < 0.09) {
        Vin = 0.00;
    }
    Serial.println("{");
    Serial.print("\tvoltage: ");
    Serial.println(Vin);
    Serial.println("}");
    delay(1000); 
}