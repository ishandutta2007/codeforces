#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll fib(ll x, ll m) {
	ll a = 0, b = 1;

	for (ll i=50; i>=0; i--) {
		// kvadriraj
		ll c = a*b + a*(b-a);
		ll d = a*a + b*b;
		a = c % m;
		if (a < 0)
			a += m;
		b = d % m;

		if (x & (1ll << i)) {
			// pomeri
			ll c = a + b;
			if (c >= m)
				c -= m;
			a = b;
			b = c;
		}
	}
	return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll m, l, r, k;
	cin >> m >> l >> r >> k;

	ll x = (r-l+1) / (k-1) + 1;

	cerr << "p: " << x << '\n';

	while (r / x - (l-1) / x < k) {
		x = min(x-1, max(r / (r / x + 1), (l-1) / ((l-1) / x + 1)));
	}

	cerr << "x: " << x << '\n';

	cout << fib(x, m) << '\n';
}