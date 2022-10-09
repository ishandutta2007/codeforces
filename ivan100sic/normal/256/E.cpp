// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

template<int m>
struct modint {
	unsigned x;

	modint() : x(0) {}
	modint(long long arg) : x((arg %= m) < 0 ? arg + m : arg) {}

	modint operator+ (const modint& b) const {
		auto t = *this; t.x = (t.x += b.x) >= m ? t.x-m : t.x; return t;
	}

	modint operator- (const modint& b) const {
		auto t = *this; t.x = (t.x += m-b.x) >= m ? t.x-m : t.x; return t;
	}

	modint operator* (const modint& b) const {
		auto t = *this; t.x = ll(t.x) * b.x % m; return t;
	}

	template<class T> modint operator^ (T n) const {
		modint t;
		if (n == 0) return t.x = 1, t;
		if (n == 1) return t.x = x, t;
		t = *this ^ (n >> 1); t *= t;
		return n & 1 ? *this * t : t;
	}

	modint& operator+= (const modint& b) { return *this = *this + b; }
	modint& operator-= (const modint& b) { return *this = *this - b; }
	modint& operator*= (const modint& b) { return *this = *this * b; }
	modint& operator++ () { if (++x == m) x = 0; return *this; }
	modint& operator-- () { if (x-- == 0) x = m-1; return *this; }
	modint operator++ (int) { modint tmp = *this; ++*this; return tmp; }
	modint operator-- (int) { modint tmp = *this; --*this; return tmp; }
	bool operator== (const modint& other) const { return x == other.x; }
	bool operator!= (const modint& other) const {	return x != other.x; }
	int operator() () const { return x; }
	template<class T> modint operator^= (T n) { return *this = *this ^ n; }
	modint inv() const { return *this ^ (m-2); }
};

const int mod = 777777777;
typedef modint<mod> mint;

template<class R>
struct matrix {
	vector<R> a;
	int n, m;

	matrix(int _n, int _m = -1) : n(_n) {
		m = _m == -1 ? n : _m;
		a.resize(n*m);
	}

	static matrix eye(int n) {
		matrix t(n);
		for (int i=0; i<n; i++)
			t[i][i] = 1;
		return t;
	}

	matrix operator* (const matrix& b) const {
		matrix c(n, b.m);
		for (int i=0; i<n; i++)
			for (int j=0; j<m; j++)
				for (int k=0; k<b.m; k++)
					c[i][k] += a[m*i+j] * b[j][k];
		return c;
	}

	matrix& operator+= (const matrix& b) {
		for (int i=0; i<n*m; i++)
			a[i] += b.a[i];
		return *this;
	}

	matrix& operator-= (const matrix& b) {
		for (int i=0; i<n*m; i++)
			a[i] += b.a[i];
		return *this;
	}

	R* operator[] (int x) { return a.data() + m*x; }
	const R* operator[] (int x) const { return a.data() + m*x; }
	matrix operator+ (const matrix& b) const { auto t = *this; t += b; return t; }
	matrix operator- (const matrix& b) const { auto t = *this; t -= b; return t; }
	matrix& operator*= (const matrix& b) { return *this = *this * b; }
	template<class U> matrix operator^= (U arg) { return *this = *this ^ arg; }

	template<class U>
	matrix operator^ (U arg) const {
		if (arg == 0)
			return matrix::eye(n);
		if (arg == 1)
			return *this;
		auto t = *this ^ (arg >> 1);
		t *= t;
		if (arg & 1)
			t *= *this;
		return t;
	}

	matrix T() const {
		matrix b(m, n);
		for (int i=0; i<n; i++)
			for (int j=0; j<m; j++)
				b[j][i] = a[i][j];
		return b;
	}
};

using mat = matrix<mint>;

template<class T = int, class F = plus<T>>
struct segtree {
	int maxn;
	vector<T> a;
	T e;
	F f;

	segtree(int n, T e = T(), F f = F(), T v = T()) : e(e), f(f) {
		maxn = 1;
		while (maxn < n)
			maxn <<= 1;
		a.assign(2*maxn, v);
		for (int i=maxn-1; i; i--)
			a[i] = f(a[2*i], a[2*i+1]);
	}

	void add(int p, const T& v) {
		p += maxn;
		a[p] = f(a[p], v);
		for (p >>= 1; p; p >>= 1)
			a[p] = f(a[2*p], a[2*p+1]);
	}

	void update(int p, const T& v) {
		p += maxn;
		a[p] = v;
		for (p >>= 1; p; p >>= 1)
			a[p] = f(a[2*p], a[2*p+1]);
	}

	T get(int l, int r, int x, int xl, int xr) const {
		if (r <= xl || xr <= l)
			return e;
		if (l <= xl && xr <= r)
			return a[x];
		int xm = (xl+xr) >> 1;
		return f(get(l, r, 2*x, xl, xm), get(l, r, 2*x+1, xm, xr));
	}

	T operator() (int l, int r) const {
		return get(l, r, 1, 0, maxn);
	}
};

int main() {
  ios::sync_with_stdio(!cin.tie(0));

	int n, m;
	cin >> n >> m;

	mat w[4] = {mat(3), mat(3), mat(3), mat(3)};

	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			int x;
			cin >> x;
			w[3][i][j] += x;
			w[j][i][j] += x;
		}
	}

	vector<int> a(n, 3);

	segtree st(n, mat::eye(3), multiplies<mat>(), w[3]);
	while (m--) {
		int x, v;
		cin >> x >> v;
		x--;
		v = (v+3)%4;
		a[x] = v;
		if (x > 0) {
			st.update(x-1, w[v]);
		}

		auto p = st(0, n-1);

		mint ans;
		for (int i=0; i<3; i++) {
			for (int j=0; j<3; j++) {
				if (a[0] == 3) {
					ans += p[i][j];
				} else if (a[0] == i) {
					ans += p[i][j];
				}
			}
		}

		cout << ans() << '\n';
	}
}