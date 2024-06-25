// Pin definitions
const int gasSensorPin = A1;      // Gas sensor connected to A0
const int tempSensorPin = A0;     // Temperature sensor connected to A1
const int ledPin = 13;             // LED connected to digital pin 8
const int buzzerPin = 7;          // Buzzer connected to digital pin 9

// Threshold values
const int gasThreshold = 300;     // Example gas threshold value (adjust based on your sensor)
const float tempThreshold = 50.0; // Example temperature threshold in Celsius (adjust as needed)

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Initialize LED and buzzer pins as outputs
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  // Initialize the sensors
  pinMode(gasSensorPin, INPUT);
  pinMode(tempSensorPin, INPUT);
}

void loop() {
  // Read gas sensor value
  int gasValue = analogRead(gasSensorPin);
  
  // Read temperature sensor value (LM35 gives 10mV per degree Celsius)
  int tempValue = analogRead(tempSensorPin);
  float temperature = tempValue * (5.0 / 1023.0) * 100.0;
  
  // Print sensor values to the serial monitor
  Serial.print("Gas Value: ");
  Serial.print(gasValue);
  Serial.print("\t Temperature: ");
  Serial.println(temperature);
  
  // Check if gas value exceeds threshold
  if (gasValue > gasThreshold || temperature > tempThreshold) {
    // Turn on LED and buzzer if threshold is exceeded
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
  } else {
    // Turn off LED and buzzer if threshold is not exceeded
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
  }
  
  // Wait for a short period before repeating the loop
  delay(500);
}