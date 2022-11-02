#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

char r[300009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n, k; cin >> n >> k;
		string s; cin >> s;
		int mx = 0, mn = 0;
		bool f = true;
		for (int i = 0; i < k; i++)
			r[i] = '?';
		for (int i = 0; i < n; i++) {
			int t = i % k;
			if (s[i] != '?' && r[t] == '?') r[t] = s[i];
			if (r[t] != '?' && s[i] != '?' && s[i] != r[t]) {
				f = false;
				break;
			}
		}
		if (!f) {
			cout << "NO" << '\n';
			continue;
		}
		for (int i = 0; i < k; i++) {
			if (r[i] != '?') s[i] = r[i];
			if (s[i] == '0') {
				mx--; mn--;
			}
			else if (s[i] == '1') {
				mx++; mn++;
			}
			else {
				mx++; mn--;
			}
		}
		if (0 < mn || mx < 0) {
			cout << "NO" << '\n';
			continue;
		}
		cout << "YES" << '\n';
	}
	return 0;
}