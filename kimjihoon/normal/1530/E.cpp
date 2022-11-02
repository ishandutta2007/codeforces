#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int c[26], ans[100009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		string s; cin >> s;
		int n = s.length(), cc = 0, mn = 26;
		for (int i = 0; i < 26; i++)
			c[i] = 0;
		for (int i = 0; i < n; i++) {
			int t = (int)(s[i] - 'a');
			mn = min(mn, t);
			c[t]++;
			if (c[t] == 1) cc++;
			ans[i] = -1;
		}
		if (cc == 1) {
			cout << s << '\n';
			continue;
		}
		int ttp = -1;
		for (int i = 0; i < 26; i++)
			if (c[i] == 1) {
				ttp = i;
				break;
			}
		if (ttp != -1) {
			int p = 0;
			cout << (char)(ttp + 'a');
			c[ttp]--;
			while (p < 26) {
				while (p < 26 && !c[p]) p++;
				if (p >= 26) break;
				cout << (char)(p + 'a');
				c[p]--;
			}
			cout << '\n';
			continue;
		}
		if (c[mn] <= n / 2 + 1) {
			ans[0] = mn; c[mn]--;
			for (int i = 1; i < n && c[mn]; i += 2) {
				ans[i] = mn;
				c[mn]--;
			}
			int p = 0;
			for (int i = 0; i < n; i++) {
				while (!c[p]) p++;
				if (ans[i] == -1) {
					ans[i] = p; c[p]--;
				}
			}
			for (int i = 0; i < n; i++)
				cout << (char)(ans[i] + 'a');
			cout << '\n';
			continue;
		}
		if (cc == 2) {
			cout << (char)(mn + 'a');
			c[mn]--;
			int p = 25;
			while (p >= 0) {
				while (p >= 0 && !c[p]) p--;
				if (p < 0) break;
				cout << (char)(p + 'a');
				c[p]--;
			}
			cout << '\n';
			continue;
		}
		ans[0] = mn;
		int mn1 = mn + 1;
		while (!c[mn1]) mn1++;
		int mn2 = mn1 + 1;
		while (!c[mn2]) mn2++;
		cout << (char)(mn + 'a');
		cout << (char)(mn1 + 'a');
		c[mn]--; c[mn1]--;
		while (c[mn]) {
			cout << (char)(mn + 'a');
			c[mn]--;
		}
		cout << (char)(mn2 + 'a');
		c[mn2]--;
		int p = 0;
		while (p < 26) {
			while (p < 26 && !c[p]) p++;
			if (p >= 26) break;
			cout << (char)(p + 'a');
			c[p]--;
		}
		cout << '\n';
	}
	return 0;
}