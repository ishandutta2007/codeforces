#include <bits/stdc++.h>
#define y0 fdjsoioijfdjioas
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll n, m, x, y, vx, vy;

vector<int> filters;

void ans(int x, int y = -1) {
	if (y == -1)
		cout << x << '\n';
	else {
		for (int f : filters) {
			if (f == 0) {
				x = n-x;
			} else {
				y = m-y;
			}
		}

		cout << x << ' ' << y << '\n';
	}
	exit(0);
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

// mod1 * mod2 < 2**61
struct crt {

	ll i1, i2, mm;
	ll mod1, mod2;

	crt(ll m1, ll m2) : mod1(m1), mod2(m2) {
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

	cin >> n >> m >> x >> y >> vx >> vy;

	if (vx == 0) {
		if (x > 0 && x < n)
			ans(-1);
		if (x == 0)
			vy < 0 ? ans(0, 0) : ans(0, m);
		else if (x == n)
			vy < 0 ? ans(n, 0) : ans(n, m);
	}

	if (vy == 0) {
		if (y > 0 && y < m)
			ans(-1);
		if (y == 0)
			vx < 0 ? ans(0, 0) : ans(n, 0);
		else if (y == m)
			vx < 0 ? ans(0, m) : ans(n, m);
	}

	// oba su nenula
	if (vx < 0) {
		x = n-x;
		vx = -vx;
		filters.push_back(0);
	}

	if (vy < 0) {
		y = m-y;
		vy = -vy;
		filters.push_back(1);
	}

	{
		ll g = gcd(n, m);
		ll x0 = (n-x) % n;
		ll y0 = (m-y) % m;

		if (x0 % g != y0 % g)
			ans(-1);

		ll ostatak = x0 % g;
		x0 -= ostatak;
		y0 -= ostatak;

		x0 /= g;
		y0 /= g;
		ll m0 = m / g;
		ll n0 = n / g;

		crt c1(n0, m0);
		ll t = c1(x0, y0);

		t = t*g + ostatak;

		ll xf = x + t;
		ll yf = y + t;

		xf %= 2*n;
		yf %= 2*m;

		ans(xf, yf);
	}





}