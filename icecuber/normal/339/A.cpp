#include <iostream>

using namespace std;

int c[3];
int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i += 2)
		c[s[i]-'1']++;
	int plus = 0;
	for (int j = 0; j < 3; j++) {
		while (c[j]--) {
			if (plus++) cout << '+';
			cout << char('1'+j);
		}
	}
	cout << endl;
	return 0;
}