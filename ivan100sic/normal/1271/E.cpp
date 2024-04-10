#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll n, k;

ll st(ll x) {
	ll xl = x, xr = x, z = 0;
	while (xl <= n) {
		z += min(n, xr) - xl + 1;
		xl = 2*xl;
		xr = 2*xr + 1;
	}
	return z;
}

ll racunaj(ll x) {
	ll z = st(x);
	if (x % 2 == 0)
		z += st(x+1);
	return z;
}

ll naj(ll y) {
	ll s2 = 1;
	while (s2 < y)
		s2 *= y;
	return max({racunaj(s2), racunaj(y), racunaj(y+1)});
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;

	ll l = 2, r = n, o = 1;
	while (l <= r) {
		ll m = (l+r) >> 1;
		if (naj(m) >= k) {
			o = m;
			l = m + 1;
		} else {
			r = m - 1;
		}
	}
	cout << o << '\n';
}