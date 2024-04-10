#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int q; cin >> q; while(q--) {
		int k, n, a, b;
		cin >> k >> n >> a >> b;
		if(b * n >= k) {
			cout << -1 << endl;
			continue;
		}
		int l = 0, r = n + 1;
		while(l + 1 < r) {
			int m = (l + r) / 2;
			int x = a * m + b * (n - m);
			if(x >= k) {
				r = m;
			}
			else {
				l = m;
			}
		}
		cout << l << endl;
	}
}