#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	if (n % 2) {
		cout << ":(" << '\n';
		return 0;
	}
	int c = 0;
	for (int i = 0; i < n; i++) 
		if (s[i] == '(') c++;
	c = n / 2 - c;
	int p = 0;
	string ans = "";
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') {
			p++; ans += '(';
		}
		else if (s[i] == ')') {
			p--; ans += ')';
		}
		else {
			if (c) { p++; c--; ans += '('; }
			else { p--; ans += ')'; }
		}
		if (i != n - 1 && p <= 0) {
			cout << ":(" << '\n';
			return 0;
		}
	}
	if (p != 0) {
		cout << ":(" << '\n';
		return 0;
	}
	cout << ans << '\n';
	return 0;
}