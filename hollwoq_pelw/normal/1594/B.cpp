#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

signed main() {
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);

	int n, k, t;
	for (cin >> t; t --; ) {
		cin >> n >> k;
		int res = 0;
		for (int v = 1; k; v = 1ll * v * n % mod, k >>= 1)
			if (k & 1) res = (res + v) % mod;
		cout << res << '\n';
	}
}