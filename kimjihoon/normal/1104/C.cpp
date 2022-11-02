#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string s; cin >> s;
	int f1 = 1, f2 = 1;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '0') {
			cout << f1 << " " << 1 << '\n';
			f1 = (f1 + 2) % 4;
		}
		else {
			cout << f2 << " " << 2 << '\n';
			f2 = (f2 % 4) + 1;
		}
	}
	return 0;
}