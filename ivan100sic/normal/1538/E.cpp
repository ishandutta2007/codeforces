// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

template<class R>
struct matrix {
	vector<R> a;
	int n, m;

	matrix(int _n = 1, int _m = -1) : n(_n) {
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

typedef matrix<ll> mat;

mat H(5, 5), A(5, 5), X(5, 5);

void init() {
	H.a = {
		0, 1, 0, 0, 0,
		0, 1, 0, 0, 0,
		0, 0, 0, 1, 0,
		0, 1, 0, 0, 0,
		0, 0, 0, 0, 1,
	};

	A.a = {
		1, 0, 0, 0, 0,
		0, 0, 1, 0, 0,
		1, 0, 0, 0, 0,
		0, 0, 1, 0, 1,
		0, 0, 0, 0, 1,
	};

	X.a = {
		1, 0, 0, 0, 0,
		1, 0, 0, 0, 0,
		1, 0, 0, 0, 0,
		1, 0, 0, 0, 0,
		0, 0, 0, 0, 1,
	};
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

	init();

	int t;
	cin >> t;
	while (t--) {
		map<string, mat> mp;
		int n;
		ll last = 0;
		cin >> n;
		while (n--) {
			string var, com;
			cin >> var >> com;
			if (com == "=") {
				string l, pl, r;
				cin >> l >> pl >> r;
				mp[var] = mp[l] * mp[r];
			} else {
				mat t = mat::eye(5);
				string s;
				cin >> s;
				for (char c : s) {
					if (c == 'h') t *= H;
					else if (c == 'a') t *= A;
					else t *= X;
				}
				mp[var] = t;
			}
			last = mp[var][0][4];
		}
		cout << last << '\n';
	}
}