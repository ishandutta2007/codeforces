#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll krnjenistepen(ll n) {
	return n > 60 ? 1e17 : (1ll << n) - 1;
}

pair<ll, ll> zapocni(ll n) {
	ll lo = n*(n+1) / 2;
	ll hi = 4e18;
	return {lo, hi};
}

ll mul(ll x, ll y) {
	if (x * 1.0 * y > 4e18)
		return 4e18;
	return x*y;
}

pair<ll, ll> nastavi(ll last, ll n) {
	ll lo = (n + 2*last*n + n*n) / 2;
	ll hi = mul(2*last, krnjenistepen(n));
	return {lo, hi};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll s, n;
	cin >> s >> n;

	if (n == 1) {
		cout << "YES\n" << s << '\n';
		return 0;
	} else if (n == 2) {
		if (s == 4) {
			cout << "NO\n";
			return 0;
		}
	} else if (n == 3) {
		if (s == 8) {
			cout << "NO\n";
			return 0;
		}
	}


	auto poc = zapocni(n);
	if (s < poc.first || s > poc.second) {
		cout << "NO\n";
		return 0;
	}

	basic_string<ll> z;
	ll last = -1;
	for (ll i=1; i<=n; i++) {
		ll l, r;
		if (last == -1) {
			l = 1;
			r = s;
		} else {
			l = last + 1;
			r = 2 * last;
		}

		ll o = -1;
		while (l <= r) {
			ll m = (l+r) >> 1;
			auto p = nastavi(m, n-i);

			// cerr << i << ' ' << l << ' ' << r << ' ' << m << ' ';
			// cerr << p.first << ' ' << p.second << '\n';

			if (s-m < p.first) {
				r = m-1;
			} else if (s-m > p.second) {
				l = m+1;
			} else {
				o = m;
				break;
			}
		}

		z += o;
		s -= o;
		last = o;
	}

	cout << "YES\n";
	for (ll x : z)
		cout << x << ' ';
	cout << '\n';
}