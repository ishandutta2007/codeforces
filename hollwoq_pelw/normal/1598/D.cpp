#include <bits/stdc++.h>
using namespace std;

inline void solve() {
	int n; cin >> n;
	vector<int> a(n), b(n);
	vector<pair<int, int>> v(n);
	for (auto &[x, y] : v)
		cin >> x >> y, a[-- x] ++, b[-- y] ++;
	int64_t res = 1ll * n * (n - 1) * (n - 2) / 6;
	for (auto [x, y] : v)
		res -= 1ll * (a[x] - 1) * (b[y] - 1);
	cout << res << '\n';
}

signed main() {
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
	int t;
	for (cin >> t; t --; )
		solve();
}