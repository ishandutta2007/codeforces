#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll safe_mul(ll a, ll b) {
	if (a * 1.0 * b > 2.1e18) {
		return 2e18;
	} else {
		return a*b;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll x, y, l, r;
	cin >> x >> y >> l >> r;

	vector<ll> a, b;
	for (ll p=1; p<=r; p=safe_mul(p, x)) {
		a.push_back(p);
	}
	for (ll p=1; p<=r; p=safe_mul(p, y)) {
		b.push_back(p);
	}

	vector<ll> bad;

	for (ll u : a) {
		for (ll v : b) {
			bad.push_back(u+v);
		}
	}

	bad.push_back(l-1);
	bad.push_back(r+1);

	sort(bad.begin(), bad.end());
	bad.resize(unique(bad.begin(), bad.end()) - bad.begin());

	ll sol = 0;

	for (ll i=1; i<(ll)bad.size(); i++) {
		ll u = bad[i-1]+1, v = bad[i]-1;
		u = max(u, l);
		v = min(v, r);

		sol = max(sol, v-u+1);
	}

	cout << sol;

}