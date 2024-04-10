#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll cnt(ll n, ll k) {
	ll z = 0, p = 1;
	ll w = n*k;
	for (ll i=0;; i++) {
		ll amt = min(p, i ? w/i : ll(1e18));
		if (amt == 0 || z > 1e9)
			return z;
		z += amt;
		w -= i*amt;
		// of check
		ld of = (ld)p*(n-i)/(i+1);
		if (of > 2e9)
			p = 2e9;
		else
			p = p*(n-i)/(i+1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int q;
	cin >> q;
	while (q--) {
		ll n, m;
		cin >> n >> m;
		ll l = 0, r = 1e9, o = -1;
		while (l <= r) {
			ll mid = (l+r) >> 1;
			if (cnt(mid, m) >= n) {
				o = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		cout << o << '\n';
	}
}