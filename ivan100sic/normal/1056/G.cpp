#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, s;
ll t;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

gp_hash_table<ll, int> mp; // ako ne radi ce ga optimizujemo

static inline ll hh(int s, int r) {
	return s * 123123123ll + r;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> s >> t;

	ll r = t % n;
	mp[hh(s, r)] = 0;

	bool use_map = true;

	for (ll i=1; i<=t; i++) {
		if (s <= m) {
			s += r;
			if (s > n)
				s -= n;
		} else {
			s -= r;
			if (s < 1)
				s += n;
		}
		r--;
		if (r == -1)
			r = n-1;

		if (use_map) {
			auto it = mp.find(hh(s, r));
			if (it != mp.end()) {
				ll period = i - it->second;
				ll jump = (t - i) / period * period;
				// cerr << "period: " << period << '\n';
				i += jump;
				r -= jump;
				r = ((r % n) + n) % n;
				use_map = false;
			} else {
				mp[hh(s, r)] = i;
			}
		}
	}

	cout << s << '\n';
}