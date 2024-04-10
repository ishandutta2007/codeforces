#include <iostream>

using namespace std;

int main() {
	string s;
	cin >> s;
	int caps = 1;
	for (int i = 1; i < s.length(); i++) {
		if (s[i] > 'Z') caps = 0;
	}
	if (caps) 
		for (int i = 0; i < s.length(); i++)
			s[i] ^= 32;
	cout << s << endl;
	return 0;
}