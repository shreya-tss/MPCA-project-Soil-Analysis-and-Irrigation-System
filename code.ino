
#include <DHT.h>
#include <DHT_U.h>
#define DHTPIN 8 // Pin connected to the DHT sensor
#define DHTTYPE DHT11 // DHT 11

DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor

int soilSensorPin = 6; // Pin connected to the soil moisture sensor
int waterSensorPin = A0; // Pin connected to the water sensor
int soilMoistureValue; // Variable to store soil moisture value
int waterLevelValue; // Variable to store water level value

void setup() {
  Serial.begin(9600); // Initialize serial communication
  pinMode(soilSensorPin, INPUT); // Set soil moisture sensor pin as input
  pinMode(waterSensorPin, INPUT); // Set water sensor pin as input
  pinMode(7, OUTPUT); // Pin connected to the water pump
  dht.begin(); // Start DHT sensor
}

void loop() { 
  // Read the soil moisture value from the sensor
  soilMoistureValue = digitalRead(soilSensorPin);
  //digitalWrite(7, LOW); 

  // Read the water level value from the sensor
  waterLevelValue = digitalRead(waterSensorPin);

  // Read temperature from DHT sensor
  float temperature = dht.readTemperature();
  float humidity=dht.readHumidity();
  
  // Print the soil moisture, water level, and temperature values to the Serial Monitor
  Serial.print("Soil Moisture Value: ");
  Serial.println(soilMoistureValue);
  Serial.print("Water Level Value: ");
  Serial.println(waterLevelValue);
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
  Serial.println("Humidity:");
  Serial.print(humidity);
  

  // Check soil moisture level and activate water pump if needed
  if (soilMoistureValue == 1 ) {  
    //Serial.println("Pump on");
    digitalWrite(7, LOW); // Activate the water pump
    delay(100); // Allow time for water to be pumped (adjust as needed)
  } else {
    Serial.println("Pump off");
    digitalWrite(7, HIGH); // Deactivate the water pump
    delay(100); // Wait before checking again
  }

  delay(2000); // Delay between sensor readings
