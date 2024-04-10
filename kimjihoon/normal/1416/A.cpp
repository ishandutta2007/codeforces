#include <iostream>
#include <algorithm>
using namespace std;

int a[300009], r[300009], c[300009], ans[300009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) {
			r[i] = 0; c[i] = -1;
			ans[i] = n + 1;
		}
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			c[a[i]] = max(c[a[i]], i - r[a[i]]);
			r[a[i]] = i;
		}
		for (int i = 1; i <= n; i++) {
			if (c[i] == -1) continue;
			c[i] = max(c[i], n + 1 - r[i]);
			ans[c[i]] = min(ans[c[i]], i);
		}
		int p = n + 1;
		for (int i = 1; i <= n; i++) {
			p = min(p, ans[i]);
			if (p > n) cout << -1 << " ";
			else cout << p << " ";
		}
		cout << '\n';
	}
	return 0;
}