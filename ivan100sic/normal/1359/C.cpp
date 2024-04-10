// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

struct rac {
	__int128 p, q;

	rac(ll p, ll q) : p(p), q(q) {}

	bool operator< (const rac& b) const {
		return p*b.q < q*b.p;
	}
};

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		ll h, c, t;
		cin >> h >> c >> t;

		ll l = 0, r = 1e9, o = 0;
		while (l <= r) {
			ll m = (l+r) / 2;
			if ((m+1) * h + m * c >= t * (2*m + 1)) {
				o = m;
				l = m + 1;
			} else {
				r = m - 1;
			}
		}

		pair<rac, ll> sol = {rac(h-t, 1), 1ll};
		sol = min(sol, pair(rac(abs(h+c-t-t), 2), 2ll));

		auto probaj = [&](ll n) {
			ll p = h + c*n + h*n - t - 2*n*t;
			p = abs(p);
			ll q = 2*n + 1;

			sol = min(sol, pair(rac(p, q), 2*n+1));
		};

		probaj(o);
		probaj(o+1);

		cout << sol.second << '\n';
	}
}