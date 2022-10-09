#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1'000'000'007;

ll sm(ll x) {
	return x*(x-1) / 2 % MOD;
}

ll sumar(ll lo, ll hi) {
	return (sm(hi) - sm(lo) + MOD) % MOD;
}

ll solve(ll x0, ll y0, ll k) {
	/*
	ll sum = 0;
	for (ll bit=33; bit>=0; bit--) {
		ll e = 1ll << bit;
		if (e & k) {
			ll em = e % MOD;
			sum += em*em%MOD*(em+MOD-1)%MOD * 500'000'004 % MOD;


		}
	}
	return (sum + x*y) % MOD;
	*/
	ll z = 0;
	ll pojav = 0;

	ll x = x0;
	for (ll u=0; u<=30; u++) {
		if ((1ll << u) & x0) {
			x -= (1ll << u);

			ll y = y0;

			for (ll v=0; v<=30; v++) {
				if ((1ll << v) & y0) {

					y -= (1ll << v);

					ll a = y;
					ll c = x;

					ll baza = a ^ c;
					baza >>= max(u, v);
					baza <<= max(u, v);

					ll granica = baza + max(1ll << u, 1ll << v);

					ll kolicina = min(1ll << u, 1ll << v);

					//cerr << u << ' ' << v << ' ' << k << ' ' <<
					//	baza << ' ' << kolicina << ' ' << granica << '\n';

					// suma svih koji su MANJI od k
					if (k <= baza) {
						z += 0;
					} else if (baza <= k && k < granica) {
						z += sumar(baza, k) * kolicina % MOD;
						pojav += (k - baza) * kolicina % MOD;
					} else {
						z += sumar(baza, granica) * kolicina % MOD;
						pojav += (granica - baza) * kolicina % MOD;
					}
					z %= MOD;
				}
			}
		}
	}
	return (z + pojav) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int q;
	cin >> q;
	while (q--) {
		ll x1, y1, x2, y2, k;
		cin >> x1 >> y1 >> x2 >> y2 >> k;
		x1--;
		y1--;

		ll sol = solve(x2, y2, k) + solve(x1, y1, k) -
			solve(x1, y2, k) - solve(x2, y1, k);

		cout << (sol + 2*MOD) % MOD << '\n';
	}
}