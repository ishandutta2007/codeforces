#include <iostream>

using namespace std;
int main() {
	string s;
	cin >> s;
	int c = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '4' or s[i] == '7') c++;
	}
	cout << ((c == 4 or c == 7)?"YES\n":"NO\n");
	return 0;
}