#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<class T>
T gcd(T a, T b) {
	T t;
	while (a) {
		t = a;
		a = b % a;
		b = t;
	}
	return b;
}

basic_string<ll> divs(ll x) {
	basic_string<ll> z;
	for (ll y=1; y*y<=x; y++) {
		if (x % y == 0) {
			z += y;
			if (y*y < x)
				z += x/y;
		}
	}
	sort(z.begin(), z.end());
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll a, b;
	cin >> a >> b;
	ll z = 8e18, w = 0;
	for (ll g : divs(abs(a-b))) {
		ll ww = a % g == 0 ? 0 : g - a%g;
		ll zz = (a+ww)*(b+ww) / gcd(a+ww, b+ww);
		if (zz < z) {
			z = zz;
			w = ww;
		}
	}
	cout << w << '\n';
}