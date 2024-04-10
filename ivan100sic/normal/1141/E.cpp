#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll n, h;
ll a[200005], z[200005];

ll safemul(ll x, ll y) {
	ld t = x * 1.0 * y;
	if (t < -2e18)
		return -2e18;
	if (t > 2e18)
		return 2e18;
	return x*y;
}

bool moze(ll steps) {
	ll hh = h + safemul(z[n], steps);
	if (hh <= 0)
		return true;
	for (int i=1; i<=n; i++) {
		if (hh + z[i] <= 0) {
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> h >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		z[i] = z[i-1] + a[i];
		if (h + z[i] <= 0) {
			cout << i << '\n';
			return 0;
		}
	}

	ll l = 0, r = 1e18, o = -1;
	while (l <= r) {
		ll m = (l+r) >> 1;
		if (moze(m)) {
			o = m;
			r = m - 1;
		} else {
			l = m + 1;
		}
	}

	if (o == -1) {
		cout << "-1\n";
		return 0;
	}

	cerr << "found o = " << o << '\n';

	for (int i=1; i<=n; i++) {
		if (h + z[n]*o + z[i] <= 0) {
			cout << n*o+i << '\n';
			return 0;
		}
	}
}