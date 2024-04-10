#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		string s; cin >> s;
		int c0 = 0, c1 = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') c0++;
			else c1++;
		}
		if (s[0] == '0' || s[n - 1] == '0' || (c0 & 1)) {
			cout << "NO" << '\n';
			continue;
		}
		cout << "YES" << '\n';
		c1 /= 2;
		int t = 0;
		string ans0 = "", ans1 = "";
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') {
				if (c1 > 0) {
					ans0 += "(";
					ans1 += "(";
					c1--;
				}
				else {
					ans0 += ")";
					ans1 += ")";
				}
			}
			else {
				if (t) {
					ans0 += "(";
					ans1 += ")";
				}
				else {
					ans1 += "(";
					ans0 += ")";
				}
				t = 1 - t;
			}
		}
		cout << ans0 << '\n' << ans1 << '\n';
	}
	return 0;
}