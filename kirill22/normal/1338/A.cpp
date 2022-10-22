#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	int ans = 0, tmp = a[0];
	for (int i = 1; i < n; i++) {
	    int z = max(0ll, tmp - a[i]);
		for (int j = 0; j < 35; j++) {
			if (z & (1ll << j)) ans = max(ans, j + 1);
		}
		a[i] += z;
		tmp = a[i];
	}
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int q; cin >> q; while (q--) solve();
}