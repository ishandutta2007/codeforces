#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
ll c[35];
ll l, x;

ll maske(ll mask) {
	ll val = 0;
	for (int i=0; i<n; i++) {
		if ((1ll << i) & mask) {
			val += c[i];
		}
	}

	return val;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> l;
	for (ll i=0; i<n; i++) {
		cin >> c[i];
		if (i) {
			c[i] = min(c[i], 2*c[i-1]);
		}
	}
	for (ll i=n; i<31; i++) {
		c[i] = 2*c[i-1];
	}
	n = 31;

	// sad ne kupujem dva ista

	ll sol = 4e18;

	while (l < (1ll << n)) {
		sol = min(sol, maske(l));
		l += l & -l;
	}

	cout << sol;




}