#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	
	int sum = 0, state = 0;
	
	for (char x : s) {
		if (state == 1) {
			sum += 10;
			state = 0;
		} else {
			if (x == '1') {
				state = 1;
			} else if (x == 'J') {
				sum += 12;
			} else if (x == 'Q') {
				sum += 13;
			} else if (x == 'K') {
				sum += 14;
			} else if (x == 'A') {
				sum += 1;
			} else {
				sum += x - '0';
			}
		}
	}
	
	cout << sum;
}