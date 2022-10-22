#include <bits/stdc++.h>
using namespace std;

inline void solve() {
	int n; cin >> n;
	vector<int> a(n);
	int64_t tot = 0;
	for (auto &v : a)
		cin >> v, tot += v;
	// tot * 2 / n = (i + j)
	tot <<= 1;
	if (tot % n) {
		cout << "0\n";
	} else {
		tot /= n;
		int64_t res = 0;
		map<int, int> mp;
		for (auto &v : a)
			res += mp[tot - v], mp[v] ++;
		cout << res << '\n';
	}
}

signed main() {
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
	int t;
	for (cin >> t; t --; )
		solve();
}