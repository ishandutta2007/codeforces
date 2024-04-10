// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

ll n, a, R, m;
ll h[100005], sol = 4e18;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> a >> R >> m;
	for (int i=0; i<n; i++)
		cin >> h[i];

	sort(h, h+n);
	ll z = accumulate(h, h+n, 0ll);
	ll zl = 0, zr = z;

	for (int i=0; i<n; i++) {
		zr -= h[i];
		zl += h[i];

		ll l = i+1;
		ll r = n-i-1;

		auto over = [&](ll x) { return zr - r * x; };
		auto undr = [&](ll x) { return l * x - zl; };

		auto enlist = [&](ll x) {
			ll o = over(x);
			ll u = undr(x);
			ll z;
			if (m < a+R) {
				if (o >= u) {
					z = u * m + (o-u) * R;
				} else {
					z = o * m + (u-o) * a;
				}
			} else {
				z = o * R + u * a;
			}

			sol = min(sol, z);
		};

		enlist(h[i]);

		if (i+1 < n) {
			ll xl = h[i], xr = h[i+1], o = xl;

			while (xl <= xr) {
				ll xm = (xl + xr) / 2;
				if ((over(xm) < undr(xm)) == (over(o) < undr(o))) {
					o = xm;
					xl = xm + 1;
				} else {
					xr = xm - 1;
				}
			}

			enlist(o);

			for (ll x=o-2; x<=o+2; x++) {
				if (clamp(x, h[i], h[i+1]) == x) {
					enlist(x);
				}
			}
		}
	}

	cout << sol << '\n';
}