// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

ll n, x;
ll a[400005];

ll f(ll x) {
	return x * (x+1) / 2;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> x;
	for (ll i=0; i<n; i++) {
		cin >> a[i];
		a[i+n] = a[i];
	}

	ll l = 0, s = accumulate(a, a+n, 0ll);
	ll z = 0;
	for (ll i=0; i<n; i++)
		z += f(a[i]);
	ll sol = 0;

	for (ll r=n; r<2*n; r++) {
		while (s > x) {
			z -= f(a[l]);
			s -= a[l++];
		}
		ll w = z;
		if (s < x) {
			w += f(a[l-1]) - f(a[l-1] - (x-s));
		}
		sol = max(sol, w);
		s += a[r];
		z += f(a[r]);
	}

	ll r = 0;
	s = 0, z = 0;
	for (ll l=0; l<n; l++) {
		while (s + a[r] < x) {
			z += f(a[r]);
			s += a[r++];
		}

		ll w = z;
		if (s < x) {
			w += f(x-s);
		}
		sol = max(sol, w);
		s -= a[l];
		z -= f(a[l]);
	}

	cout << sol << "\n";
}