#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n, m; cin >> n >> m;
		string s; cin >> s;
		string ans = s;
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') continue;
			int l = 0, r = 0;
			while (i - l > 0 && s[i - l - 1] == '0') l++;
			while (i + r < n - 1 && s[i + r + 1] == '0') r++;
			if (i - l == 0) l = 1000000009;
			if (i + r == n - 1) r = 10000000009;
			if (l == r) continue;
			if (min(l, r) < m) ans[i] = '1';
		}
		cout << ans << '\n';
	}
	return 0;
}