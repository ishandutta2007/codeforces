// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
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

const int MOD = 998'244'353;
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

typedef matrix<mint, 3> mat;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll n, m, l, r;
	cin >> n >> m >> l >> r;

	ll w = n*m;
	ll h = r-l+1;

	mint sol = -1;

	if (w % 2 == 0) {
		if (h % 2 == 0) {
			sol = (mint(2) ^ (w-1)) * (mint(h / 2) ^ w);
		} else {
			mat a;
			a[0][1] = -h;
			a[1][1] = h+1;
			a[0][0] = 0;
			a[1][0] = 1;

			a ^= w;
			sol = (a[1][1] - a[1][0] + 1) * mint(2).inv();
		}
	} else {
		if (h % 2 == 0) {
			sol = (mint(h) ^ w);
		} else {
			mat a;
			a[0][2] = -h;
			a[1][2] = 1;
			a[2][2] = h;
			a[1][0] = 1;
			a[2][1] = 1;
			sol = (a ^ (w + 2))[2][0] - (a ^ w)[2][0];
		}
	}

	cout << (int)sol << '\n';
}

// I will still practice daily...