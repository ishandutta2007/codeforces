#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll l, r, k, w;
	cin >> l >> r >> k;
	w = r-l+1;
	ll sol = 1e18;
	vector<ll> ans;
	if (w <= 12) {
		for (ll mask=1; mask<(1<<w); mask++) {
			if ((ll)__builtin_popcountll(mask) <= k) {
				ll t = 0;
				for (ll i=0; i<w; i++)
					if (mask & (1ll << i))
						t ^= l+i;
				if (t < sol) {
					sol = t;
					ans = {};
					for (ll i=0; i<w; i++)
						if (mask & (1ll << i))
							ans.push_back(l+i);
				}
			}
		}
	} else if (k >= 4) {
		ll u = l;
		while (u % 4)
			u++;
		sol = 0;
		ans = {u, u+1, u+2, u+3};
	} else if (k == 1) {
		sol = l;
		ans = {l};
	} else if (k == 2) {
		ll u = l;
		while (u % 2)
			u++;
		sol = 1;
		ans = {u, u+1};
	} else {
		ll d = __builtin_clzll(l) - __builtin_clzll(r);
		if (d >= 2) {
			ll x = 1ll << (63 - __builtin_clzll(l));
			sol = 0;
			ans = {2*x-1, 2*x, 4*x-1};
		} else if (d == 0) {
			ll u = l;
			while (u % 2)
				u++;
			sol = 1;
			ans = {u, u+1};
		} else {
			ll b = 64 - __builtin_clzll(l);
			ll x = 1ll << b;

			ll y = r-x;
			ll z = (1ll << (64 - __builtin_clzll(y))) - 1;

			ll i = r, j = r ^ z;
			if (z >= l) {
				sol = 0;
				ans = {i, j, z};
			}

			// ako ne
			if (sol > 1) {
				ll u = l;
				while (u % 2)
					u++;
				sol = 1;
				ans = {u, u+1};
			}
		}
	}

	cout << sol << '\n' << ans.size() << '\n';
	for (ll x : ans)
		cout << x << ' ';
	cout << '\n';
}