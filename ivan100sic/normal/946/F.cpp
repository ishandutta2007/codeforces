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

const int mod = 1'000'000'007;
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

	template<class U>
	matrix operator^= (U arg) {
		return *this = *this ^ arg;
	}

	matrix T() const {
		matrix b(m, n);
		for (int i=0; i<n; i++)
			for (int j=0; j<m; j++)
				b[j][i] = a[i][j];
		return b;
	}
};

typedef matrix<mint> mat;

int n, m;
string s;

int lsp(string p) {
  for (int l=p.size(); l; l--) {
    if (l <= (int)s.size() && p.substr(p.size()-l) == s.substr(0, l)) {
      return l;
    }
  }
  return 0;
}

int q[2][105];

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  cin >> n >> m >> s;
  for (int i=0; i<=n; i++) {
    q[0][i] = lsp(s.substr(0, i) + '0');
    q[1][i] = lsp(s.substr(0, i) + '1');
  }

	mat m0(n+2), m1(n+2);
	for (int i=0; i<=n; i++) {
		m0[i][q[0][i]] += 1;
		m1[i][q[1][i]] += 1;
	}

	for (int i=0; i<=n; i++) {
		m0[i][n+1] = m0[i][n];
		m1[i][n+1] = m1[i][n];
	}

	m0[n+1][n+1] = m1[n+1][n+1] = 1;

	vector<mat> f = {m0 + mat::eye(n+2), m1 + mat::eye(n+2)};
	for (int i=2; i<=m; i++)
		f.push_back(f[i-1] * f[i-2]);

	cout << f[m][0][n+1]() << '\n';
}