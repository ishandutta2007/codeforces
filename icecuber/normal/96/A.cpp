#include <iostream>

using namespace std;

int main() {
	string s;
	cin >> s;
	char last = ' ';
	int c = 0, d = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == last) c++;
		else c = 0;
		if (c == 6) d = 1;
		last = s[i];
	}
	cout << (d?"YES":"NO") << endl;
	return 0;
}