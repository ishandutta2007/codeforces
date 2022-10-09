#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll init_rank(ll rank, ll a) {
	ll x = (a >> rank) << rank;
	if (x < a)
		x += 1ll << rank;
	if (((x >> rank) & 1) == 0)
		x += 1ll << rank;
	return x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll l, r, a, b, sol = 0;
	cin >> l >> r >> a >> b;

	for (ll rank=0; rank<32; rank++) {
		ll w = 1ll << rank;

		for (ll p = init_rank(rank, a); p <= min(b, a+12*w); p += 2*w) {
			ll lw = min(w-1, p-a);
			ll rw = min(w-1, b-p);

			for (ll q = init_rank(rank, l); q <= min(r, l+12*w); q += 2*w) {
				ll aw = min(w-1, q-l);
				ll bw = min(w-1, r-q);
				sol = max(sol, min(aw, lw) + min(bw, rw) + 1);
			}
		}
	}

	cout << sol << '\n';
}