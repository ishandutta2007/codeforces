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

typedef matrix<mint, 32> mat;

mat dp[66][32];
int k;

mat special(int sm, int fr) {
	return dp[fr][sm];
}

void make_special(int steps) {
	// len = 0
	for (int i=0; i<k; i++) {
		mat& a = dp[0][i] = mat(k+1);
		for (int p=0; p<k; p++)
			for (int q=0; q<k; q++)
				a[p][q] = q == i || p == q;
		a[k][k] = 1;
		a[k][i] = 1;
	}

	// len > 0
	for (int l=1; l<steps+2; l++) {
		vector<mat> pref(k+1), suff(k+1);
		pref[0] = mat::eye(k+1);
		suff[0] = mat::eye(k+1);
		for (int i=0; i<k; i++) {
			pref[i+1] = pref[i] * dp[l-1][i];
			suff[i+1] = dp[l-1][k-1-i] * suff[i];
		}

		for (int i=0; i<k; i++) {
			dp[l][i] = suff[k-i] * pref[i];
		}
	}
}

mat solve(int k, ll l, ll r, ll xl, ll xr, int sm, int fr) {
	if (r <= xl || xr <= l)
		return mat::eye(k+1);
	if (l <= xl && xr <= r)
		return special(sm, fr);
	ll w = (xr-xl) / k;
	mat z = mat::eye(k+1);
	for (int i=0; i<k; i++)
		z *= solve(k, l, r, xl+i*w, xl+(i+1)*w, (sm+i)%k, fr-1);
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll n;
	cin >> n >> k;

	ll g = 1;
	int steps = 0;
	while (g*1.0*k < 3e18)
		g *= k, steps++;

	make_special(steps);

	mat sol = mat::eye(k+1);
	ll lo = 0, hi = g;
	for (int i=0; i<k; i++) {
		if (lo >= n+1)
			break;
		sol *= solve(k, 0, n, lo, hi, i, steps);
		lo += g;
		hi += g;
	}

	mint z = 0;
	for (int i=0; i<=k; i++)
		z += sol[k][i];
	cout << (int)z << '\n';
}