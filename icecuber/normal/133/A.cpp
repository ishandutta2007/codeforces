#include <iostream>

using namespace std;

int main() {
	string s;
	cin >> s;
	int p = 0;
	for (int i = 0; i < s.length(); i++) 
		if (s[i] == 'H' or s[i] == 'Q' or s[i] == '9') p = 1;
	cout << (p?"YES":"NO") << endl;
	return 0;
}