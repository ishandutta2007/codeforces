#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int is = 0;
	vector<int> arr = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47 };
	for (int i = 0; i < 15; i++) {
		cout << arr[i] << endl;
		string s;
		cin >> s;
		if (s == "yes") { is++; arr[i] = arr[i] * arr[i]; }
	}
	if (is > 1) { cout << "composite" << endl; return 0; }
	if (is == 0) { cout << "prime" << endl; return 0; }
	for (int i = 0; i < 4; i++) {
		cout << arr[i] << endl;
		string s;
		cin >> s;
		if (s == "yes") { is++; }
	}
	if (is > 1) { cout << "composite" << endl; }
	else { cout << "prime" << endl; }
	return 0;
}