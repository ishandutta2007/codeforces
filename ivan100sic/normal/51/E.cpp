#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

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

#ifdef LOCAL
const int N = 10;
#else
const int N = 700;
#endif

typedef matrix<ll, N> mat;
int n, m;
mat a1, a2, a3, a5;
int deg[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		a1[x][y] = 1;
		a1[y][x] = 1;
		deg[x]++;
		deg[y]++;
	}

	a2 = a1 * a1;
	a3 = a2 * a1;
	a5 = a3 * a2;

	ll sol = 0, q3 = 0, q4 = 0;
	for (int i=0; i<n; i++) {
		sol += a5[i][i];
		for (int j=0; j<n; j++) {
			if (a1[i][j]) {
				// svi susedi
				q4 += a3[j][j];
			}
		}
		// jos
		q3 += (deg[i] - 2) * a3[i][i];
	}

	cerr << sol << '\n';
	cerr << q3 << '\n';
	cerr << q4 << '\n';

	cout << (sol - 5*q3/2 - 5*q4/2)/10 << '\n';
}