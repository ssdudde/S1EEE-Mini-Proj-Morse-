// Define the PWM pin
const int pwmPin = 9; // PWM output pin connected to the transistor base

void setup() {
  Serial.begin(9600);         // Start serial communication for optional user input
  pinMode(pwmPin, OUTPUT);    // Set PWM pin as output
  Serial.println("DC Motor Speed Controller Initialized");
  Serial.println("Enter speed (0 to 255):");
}

void loop() {
  // Example 1: User Input Speed Control
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n'); // Read input as a string
    int pwmValue = input.toInt();               // Convert to integer

    // Ensure the value is in the valid range
    if (pwmValue >= 0 && pwmValue <= 255) {
      analogWrite(pwmPin, pwmValue);            // Set motor speed
      Serial.print("Motor speed set to: ");
      Serial.println(pwmValue);
    } else {
      Serial.println("Invalid input. Enter a value between 0 and 255.");
    }
  }

  // Example 2: Predefined Speed Pattern (Uncomment to use)
  /*
  for (int speed = 0; speed <= 255; speed++) {
    analogWrite(pwmPin, speed);  // Ramp up speed
    delay(10);                   // Delay to see the effect
  }
  for (int speed = 255; speed >= 0; speed--) {
    analogWrite(pwmPin, speed);  // Ramp down speed
    delay(10);
  }
  */
}
