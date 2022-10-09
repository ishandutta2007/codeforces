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

template<class T>
T eea(T a, T b, T& x, T& y) {
	if (!b) {
		x = 1;
		y = 0;
		return a;
	}

	T x1, y1;
	T g = eea(b, a % b, x1, y1);
	x = y1;
	y = x1 - (a / b) * y1;
	return g;
}

ll bigmod(ll x, ll y, ll m) {
	ll z = 0;
	for (int i=60; i>=0; i--) {
		z += z;
		if (z >= m)
			z -= m;
		if (x & (1ll << i)) {
			z += y;
			if (z >= m)
				z -= m;
		}
	}
	return z;
}

// mod1 * mod2 < 2**61
template<ll mod1, ll mod2>
struct crt {

	ll i1, i2, mm;

	crt() {
		eea(mod1, mod2, i1, i2);
		mm = mod1 * mod2;
		i1 = (i1 % mm + mm) % mm;
		i2 = (i2 % mm + mm) % mm;
	}

	ll operator() (ll x, ll y) const {
		x = bigmod(x, i2, mm);
		y = bigmod(y, i1, mm);
		return (bigmod(x, mod2, mm) + bigmod(y, mod1, mm)) % mm;
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll a, b, c;
	cin >> a >> b >> c;
	ll fx = -1, fy = -1;
	if (a < 0) {
		a *= -1;
		fx *= -1;
	}
	if (b < 0) {
		b *= -1;
		fy *= -1;
	}
	ll g = gcd(a, b);
	if (c % g)
		return cout << -1, 0;
	ll x, y;
	eea(a, b, x, y);
	cout << fx*x*c/g << ' ' << fy*y*c/g << '\n';
}