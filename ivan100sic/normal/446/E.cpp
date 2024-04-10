#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<int m>
struct modint {

	unsigned x;

	modint() : x(0) {}

	modint(long long arg) {
		arg %= m;
		if (arg < 0) {
			x = arg + m;
		} else {
			x = arg;
		}
	}	

	modint& operator+= (const modint& other) {
		x += other.x;
		if (x >= m) {
			x -= m;
		}
		return *this;
	}

	modint& operator*= (const modint& other) {
		x = (x * 1ll * other.x) % m;
		return *this;
	}

	modint& operator-= (const modint& other) {
		x += m - other.x;
		if (x >= m) {
			x -= m;
		}
		return *this;
	}

	modint operator+ (const modint& other) const {
		modint tmp = *this;
		tmp += other;
		return tmp;
	}

	modint operator- (const modint& other) const {
		modint tmp = *this;
		tmp -= other;
		return tmp;
	}

	modint operator* (const modint& other) const {
		modint tmp = *this;
		tmp *= other;
		return tmp;
	}

	explicit operator int () const {
		return x;
	}

	modint& operator++ () {
		++x;
		if (x == m) {
			x = 0;
		}
		return *this;
	}

	modint& operator-- () {
		if (x == 0) {
			x = m-1;
		} else {
			--x;
		}
		return *this;
	}

	modint operator++ (int) {
		modint tmp = *this;
		++*this;
		return tmp;
	}

	modint operator-- (int) {
		modint tmp = *this;
		--*this;
		return tmp;
	}

	bool operator== (const modint& other) const {
		return x == other.x;
	}

	bool operator!= (const modint& other) const {
		return x != other.x;
	}

	template<class T>
	modint operator^ (T arg) const {
		if (arg == 0) {
			return 1;
		}
		if (arg == 1) {
			return x;
		}
		auto t = *this ^ (arg >> 1);
		t *= t;
		if (arg & 1) {
			t *= *this;
		}
		return t;
	}

	template<class T>
	modint operator^= (T arg) {
		return *this = *this ^ arg;
	}
};

const int MOD = 1051131;
const int TOT = 700752;
typedef modint<MOD> mint;

int m, s, n;
ll t;
valarray<mint> a;

void em_inv(int m, int n, valarray<mint>& a) {
	int k = 0;
	valarray<ll> bll(n);
	for (int i=0; i<m; i++) {
		const int w = 1 << (m-i-1);
		ll mult = (int)(mint(2) ^ (TOT-i-1));
		for (int j0=0; j0<n; j0+=w+w) {
			for (int j=0; j<w; j++)
				bll[j+j0] -= (int)a[k+j] * mult;
			for (int j=0; j<w; j++)
				bll[j+j0+w] += (int)a[k+j] * mult;
		}
		k += w;
	}
	mint t = (mint(2) ^ (TOT-m)) * a[n-1];
	for (int i=0; i<n; i++)
		a[i] = bll[i];
	a += t;
}

valarray<mint> em(int m, int n, const valarray<mint>& a) {
	int k = 0;
	valarray<mint> b(n);
	for (int i=0; i<m; i++) {
		const int w = 1 << (m-i-1);
		for (int j0=0; j0<n; j0+=w+w) {
			for (int j=0; j<w; j++)
				b[k+j] -= a[j+j0];
			for (int j=0; j<w; j++)
				b[k+j] += a[j+j0+w];
		}
		k += w;
	}
	b[k++] += a.sum();
	return b;
}

valarray<mint> eigenvals(int m, int n, ll t) {
	int k = 0;
	valarray<mint> b(n);
	for (int i=0; i<m; i++) {
		int w = 1 << (m-i-1);
		mint x = 1+(i-1)*(n/2);
		b[slice(k, w, 1)] = x ^ t;
		k += w;
	}
	b[k++] = mint(1+(n/2)*m) ^ t;
	return b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> m >> t >> s;
	n = 1 << m;
	a.resize(n);
	for (int i=0; i<s; i++) {
		int x;
		cin >> x;
		a[i] = x;
	}
	for (int i=s; i<n; i++)
		a[i] = a[i-s] * 101 + 10007;
	a = em(m, n, a);
	{
		valarray<mint> b = eigenvals(m, n, t);
		for (int i=0; i<n; i++)
			a[i] = a[i] * b[i];
	}
	em_inv(m, n, a);
	int xr = 0;
	for (mint x : a)
		xr ^= (int)x;
	cout << xr << '\n';
}