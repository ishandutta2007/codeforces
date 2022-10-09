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
struct crt {
	ll mod1, mod2;
	ll i1, i2, mm;

	crt(ll mod1, ll mod2) : mod1(mod1), mod2(mod2) {
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

ll diofant(ll x, ll n, ll y, ll m) {
	// najmanji broj x (mod n) i y ( mod m), neneg

	ll g = gcd(n, m);

	ll mn = min(x, y);
	x -= mn;
	y -= mn;

	if (max(x, y) % g) {
		return 123123123123123123ll;
	}

	crt c(n / g, m / g);

	ll tmp = g * c(x / g, y / g) + mn;
	return tmp;
}

int n, m, k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k;
	while (k--) {
		int x, y;
		cin >> x >> y;

		ll r = 123123123123123123ll;

		// x + u2n == y + v2m
		r = min(r, diofant(x, 2*n, y, 2*m));
		r = min(r, diofant(x, 2*n, 2*m-y, 2*m));
		r = min(r, diofant(2*n-x, 2*n, 2*m-y, 2*m));
		r = min(r, diofant(2*n-x, 2*n, y, 2*m));

		if (r == 123123123123123123ll)
			r = -1;
		cout << r << '\n';
	}
}