// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

ll n, p1, p2, p3, t1, t2;

ll l[105], r[105];

ll resi(ll u) {
	ll w = 0;

	ll g1 = min(u, t1);
	ll g2 = max(0ll, min(u-t1, t2));
	ll g3 = max(0ll, u-t1-t2);
	// cerr << g1 << '\n';
	// cerr << g2 << '\n';
	// cerr << g3 << '\n';

	w += g1 * p1;
	w += g2 * p2;
	w += g3 * p3;
	return w;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;
	ll w = 0;
	for (int i=0; i<n; i++) {
		cin >> l[i] >> r[i];
		w += (r[i] - l[i]) * p1;

		if (i > 0) {
			w += resi(l[i] - r[i-1]);
		}
	}

	cout << w << '\n';


}