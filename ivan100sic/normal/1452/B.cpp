// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

ll n, a[100005], b[100005];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i=0; i<n; i++) cin >> a[i];
		sort(a, a+n);

		ll l=0, r=2e9, sol=1e18;
		while (l <= r) {
			ll m = (l+r) / 2;
			copy(a, a+n, b);
			for (int i=0; i<n; i++) {
				if (b[i] < m) {
					b[i] = m;
				}
			}

			ll rem = accumulate(b, b+n, 0ll) % (n-1);
			if (rem) {
				rem = (n-1) - rem;
			}

			for (int i=1; i<n; i++) {
				if (rem > 0) {
					rem--;
					b[i]++;
				}
			}

			if (b[0] >= b[n-1] * (n-2) - accumulate(b+1, b+n-1, 0ll)) {
				r = m - 1;
				sol = accumulate(b, b+n, 0ll) - accumulate(a, a+n, 0ll);
			} else {
				l = m + 1;
			}
		}

		cout << sol << '\n';
	}
}