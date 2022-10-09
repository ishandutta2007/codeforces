#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll br(ll g, ll b, ll x) {
	ll q = x / (b+g);
	ll z = q * g;
	return z + min(g, x % (b+g));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		ll n, g, b;
		cin >> n >> g >> b;
		ll t = n % 2 ? n/2 + 1 : n/2;

		ll l = 0, r = 1e18, o = 1e18;
		while (l <= r) {
			ll m = (l+r) / 2;
			if (br(g, b, m) >= t) {
				o = m;
				r = m - 1;
			} else {
				l = m + 1;
			}
		}
		cout << max(o, n) << '\n';
	}
}