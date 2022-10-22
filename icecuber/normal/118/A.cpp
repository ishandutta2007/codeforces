#include <iostream>

using namespace std;

string vow = "aeiouyAEIOUY";

int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		int ok = 1;
		for (int j = 0; j < 12; j++) 
			if (s[i] == vow[j]) ok = 0;
		if (ok) {
			if (s[i] < 'a')
				s[i] += 'a'-'A';
			cout << "." << s[i];
		}
	}
	cout << endl;
	return 0;
}