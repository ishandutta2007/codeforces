#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("avx,tune=native")
using namespace std;

int q, a[100005], b[100005], c[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> q;
	while (q--) {
		int t, l, r, k;
		cin >> t >> l >> r;
		if (t == 1) {
			cin >> k;
			if (k > 0) {
				for (int i=l; i<r; i++) {
					if (a[i]) {
						a[i] = min(a[i], k);
					} else {
						a[i] = k;
					}
					if (b[i]) {
						c[i] = a[i] + b[i];
					}
				}
			} else {
				k = -k;
				for (int i=l; i<r; i++) {
					if (b[i]) {
						b[i] = min(b[i], k);
					} else {
						b[i] = k;
					}
					if (a[i]) {
						c[i] = a[i] + b[i];
					}
				}
			}
		} else {
			long long sol = 0;
			for (int i=l; i<r; i++) {
				sol += c[i];
			}
			cout << sol << '\n';
		}

	}

}