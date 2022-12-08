#include <iostream>
#include <string>
using namespace std;

char toUpper(char ch)
{
	if (ch >= 'a'&&ch <= 'z')
		return (char)(ch - 32);
	return ch;
}
void main() {
	string s;
	string t;
	int n;
	int i;
	cin >> s;
	cin >> n;
	bool fl = true;
	for (i = 0; i < n; i++) {
		cin >> t;
		if (t.length() != s.length()) {
			fl = true;
		}
		else {
			int last = -1;
			int count = 0;
			for (int j = 0; j < s.length(); j++) {
				if (s[j] == 'l' || s[j] == 'I'	|| s[j] == 'L' || s[j] == 'i' || s[j] == '1') {
					if (!(t[j] == 'l' || t[j] == 'I' || t[j] == 'L' || t[j] == 'i' || t[j] == '1')) {
						break;
					}
				}
				else if (s[j] == 'O' || s[j] == 'o' || s[j] == '0') {
					if (!(t[j] == 'O' || t[j] == 'o' || t[j] == '0')) {
						break;
					}
				}				
				else if (!(toUpper(s[j]) == toUpper(t[j]))) {
					break;
				}
				count++;
			}
			if (count == s.length()) {
				fl = false;
				break;
			}
		}
		if (!fl) {
			break;
		}
	}
	if (fl) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}