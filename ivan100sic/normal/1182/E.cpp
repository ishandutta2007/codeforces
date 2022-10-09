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
		x = (x * 1ull * other.x) % m;
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

const int MOD1 = 1'000'000'007;
const int MOD2 = 1'000'000'006;
typedef modint<MOD2> mint;

const int W = 65536;
pair<int, int> pows5[W];

int pw(int x, int y) {
	if (y == 0)
		return 1;
	int z = pw(x, y >> 1);
	z = z * 1ll * z % MOD1;
	if (y & 1)
		z = z * 1ll * x % MOD1;
	return z;
}

int dlog(int x) {
	int px = x, dodao = 0;
	int step = pw(5, 65536);
	step = pw(step, MOD1 - 2); // inverz
	while (1) {
		// px * pows5[nesto] = x
		// pows5[nesto] = x / px
		auto it = lower_bound(pows5, pows5+W, pair<int, int>{px, -1});

		// cerr << px << ' ' << it->first << ' ' << it->second << '\n';

		if (it != pows5+W && it->first == px) {
			return dodao + it->second;
		}

		px = px * 1ll * step % MOD1;
		dodao += 65536;
	}
}

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

typedef matrix<mint, 5> mat;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	pows5[0] = {1, 0};
	for (int i=1; i<W; i++)
		pows5[i] = {pows5[i-1].first * 5ll % MOD1, i};
	sort(pows5, pows5+W);

	mat a;
	for (int i=0; i<4; i++)
		a[i+1][i] += 1;
	a[4][4] += 3;
	a[3][4] -= 2;
	a[1][4] -= 1;
	a[0][4] += 1;

	ll n, f1, f2, f3, c;
	cin >> n >> f1 >> f2 >> f3 >> c;

	mint d = dlog(c);
	mint g1 = dlog(f1);
	mint g2 = dlog(f2);
	mint g3 = dlog(f3);
	mint g4 = d*2 + g1 + g2 + g3;
	mint g5 = d*4 + g2 + g3 + g4;
	// mint g6 = d*6 + g3 + g4 + g5;
	
	// cerr << pw(5, (int)g4) << '\n';
	// cerr << pw(5, (int)g5) << '\n';
	// cerr << pw(5, (int)g6) << '\n';

	mint gg[5] = {g1, g2, g3, g4, g5};
	// mint gg[5] = {g1, g2, g3, g4, g5};
	// mint gg[5] = {g2, g3, g4, g5, ...};
	mint rez;

	if (n == 4) {
		rez = g4;
	} else if (n == 5) {
		rez = g5;
	} else {
		a ^= n - 5;

		// for (int i=0; i<5; i++) {
		// 	mint tmp = 0;
		// 	for (int j=0; j<5; j++)
		// 		tmp += gg[j] * a[j][i];
		// 	cerr << pw(5, (int)tmp) << '\n';
		// }

		for (int i=0; i<5; i++)
			rez += gg[i] * a[i][4];
	}
	cout << pw(5, (int)rez) << '\n';
}