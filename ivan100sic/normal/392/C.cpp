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

	modint inv() const {
		return *this ^ (m-2);
	}
};

const int MOD = 1'000'000'007;
typedef modint<MOD> mint;

template<class T, int N>
struct matrix {
	T a[N][N];
	int n;

	matrix(int _n = N) : n(_n) {
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				a[i][j] = T();
	}

	T* operator[] (int x) {
		return a[x];
	}

	const T* operator[] (int x) const {
		return a[x];
	}

	static matrix eye(int n = N) {
		matrix t(n);
		for (int i=0; i<n; i++)
			t[i][i] = 1;
		return t;
	}

	matrix operator* (const matrix& b) const {
#ifdef LOCAL
		if (n != b.n)
			throw "matrix size mismatch";	
#endif
		matrix c(n);
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				for (int k=0; k<n; k++)
					c[i][k] += a[i][j] * b[j][k];
		return c;
	}

	matrix& operator*= (const matrix& b) {
		return *this = *this * b;
	}

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
};

typedef matrix<mint, 100> mat;

ll n;
int k;

valarray<mint> fib, a, g[100], h[100], sol, bb[100];
bool found;

void generate_some() {
	fib.resize(205);
	a.resize(205);
	fib[1] = 1;
	fib[2] = 2;
	for (int i=3; i<205; i++)
		fib[i] = fib[i-1] + fib[i-2];
	for (int i=1; i<205; i++) {
		a[i] = fib[i] * (mint(i) ^ k);
		a[i] += a[i-1];
	}
}

bool prazan(valarray<mint>& c) {
	for (int i=0; i<100; i++)
		if (c[i] != 0)
			return false;
	return true;
}

void gadd(valarray<mint> b, valarray<mint> c) {
	for (int i=0; i<100; i++) {
		if (g[i][i] == 0) {
			g[i] = b;
			h[i] = c;
			return;
		}
		mint coef = b[i] * g[i][i].inv();
		b -= g[i] * coef;
		c -= h[i] * coef;
		if (prazan(b)) {
			sol = c;
			found = 1;
			return;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	generate_some();
	int cnt = -1;

	if (n <= 200) {
		cout << (int)a[n] << "\n";
		return 0;
	}
	
	for (int i=0; i<100; i++)
		g[i].resize(100);

	for (int i=0; i<100; i++) {
		bb[i].resize(100);
		bb[i] = a[slice(i+1, 100, 1)];
		valarray<mint> tmp(100);
		tmp[i] = 1;
		gadd(bb[i], tmp);
		if (found) {
			cnt = i+1;
			break;
		}
	}
	cerr << "cnt = " << cnt << '\n';
	for (int i=0; i<cnt; i++)
		cerr << (int)sol[i] << ' ';
	cerr << '\n';

	mat mt(cnt-1);
	for (int i=0; i<cnt-1; i++) {
		if (i < cnt-2)
			mt[i][i+1] += 1;
		mt[i][0] -= sol[cnt-2-i];
	}
	mt ^= n-cnt;
	mint ans;
	for (int i=0; i<cnt; i++) {
		cerr << (int)a[cnt-i] << ' ' << (int)mt[i][0] << '\n';
		ans += a[cnt-i] * mt[i][0];
	}
	cout << (int)ans << '\n';
}