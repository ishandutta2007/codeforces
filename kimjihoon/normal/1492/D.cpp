#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int a, b, k; cin >> a >> b >> k;
	int n = a + b;
	if (n == k || (a == 0 && k != 0)) {
		cout << "No" << '\n';
		return 0;
	}
	string s0 = "", s1 = "";
	for (int i = 0; i < n; i++) s0 += "0";
	s1 = s0;
	if (k == 0) {
		cout << "Yes" << '\n';
		for (int i = 0; i < b; i++) {
			s0[i] = s1[i] = '1';
		}
		cout << s1 << '\n' << s0 << '\n';
		return 0;
	}
	int c = 0;
	for (int i = n - 1; i >= 0 && c < b; i--) {
		if (n - i - 1 == k) i--;
		s0[i] = '1'; c++;
	}
	c = 0;
	for (int i = n - 2; i >= 0 && c < b; i--) {
		if (n - i - 1 == k || s0[i] == '1') {
			s1[i] = '1';
			c++;
		}
	}
	if (s0[0] != s1[0]) {
		cout << "No" << '\n';
		return 0;
	}
	if (s0[0] == '0') {
		for (int i = 1; i < n; i++) {
			if (s0[i] == '1' && s1[i] == '1') {
				s0[i] = s1[i] = '0';
				s0[0] = s1[0] = '1';
				break;
			}
		}
	}
	if (s0[0] == '0') {
		cout << "No" << '\n';
		return 0;
	}
	cout << "Yes" << '\n';
	cout << s1 << '\n' << s0 << '\n';
	return 0;
}