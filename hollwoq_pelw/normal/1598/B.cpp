#include <bits/stdc++.h>
using namespace std;

inline bool solve() {
	int n; cin >> n;
	vector<vector<int>> a(n, vector<int>(5));
	for (auto &v : a) for (auto &x : v) cin >> x;

	for (int i = 0; i < 5; i++) for (int j = 0; j < i; j++) {
		int cnt[4] = {0, 0, 0, 0};
		for (auto &v : a)
			cnt[v[i] << 1 | v[j]] ++;
		if (cnt[0]) continue ;
		if (cnt[1] + cnt[3] >= n / 2 && cnt[2] + cnt[3] >= n / 2) return 1; 
	}
	return 0;
}

signed main() {
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
	int t;
	for (cin >> t; t --; ) {
		cout << (solve() ? "YES\n" : "NO\n");
	}
}