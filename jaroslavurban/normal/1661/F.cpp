#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;


void ProGamerMove() {
	int n; cin >> n;
	vector<int> a(n), dists(n);
	for (int& v : a) cin >> v;
	dists[0] = a[0];
	for (int i = 1; i < n; ++i) dists[i] = a[i] - a[i - 1];
	ll k; cin >> k;
	auto calc = [&] (ll d, ll x) {
		ll ds = d / (x + 1);
		ll cntb = d % (x + 1);
		return cntb * (ds + 1) * (ds + 1) + (x + 1 - cntb) * ds * ds;
	};
	auto tr = [&] (int mx) {
		ll res = 0;
		for (int d : dists) res += calc(d, (d + mx - 1) / mx - 1);
		return res;
	};
	int l = 1, r = 1e9 + 1;
	while (l < r) {
		int m = (l + r) / 2;
		if (tr(m) < k) l = m + 1;
		else r = m;
	}
	l = int(l * 1.5);
	ll price = 0, tels = 0;
	priority_queue<tuple<ll, ll, ll>> q;
	for (int d : dists) {
		ll x = ((ll)d + l - 1) / l - 1;
		tels += x;
		price += calc(d, x);
		q.push({calc(d, x) - calc(d, x + 1), (ll)d, x});
	}
	while (q.size() && price > k) {
		auto [diff, d, x] = q.top(); q.pop();
//		cerr << diff << ' ' << d << ' ' << x << endl;
		ll l = 1, r = d - x;
		while (l < r) {
			ll m = (l + r) / 2;
			if (price - (m - 1) * diff > k && calc(d, x + m - 1) - calc(d, x + m) == diff) l = m + 1;
			else r = m;
		}
		--l;
//		cerr << l << endl;
		price -= l * diff;
		tels += l;
		q.push({calc(d, x + l) - calc(d, x + l + 1), d, x + l});
	}
	assert(price <= k);
	cout << tels << "\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
//	cin >> tc;
	while (tc--) ProGamerMove();
}