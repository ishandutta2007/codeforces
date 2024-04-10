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

typedef matrix<ld, 101> mat;
typedef valarray<ld> vec;

int n, m, k;
int e[505][505], deg[505];
int a[505];

vec g[505], h[505], cv[505], cv2[505];

void gadd(vec b, vec c) {
	for (int i=0; i<n; i++) {
		if (abs(g[i][i]) < 1e-12) {
			g[i] = b;
			h[i] = c;
			return;
		} else {
			ld q = b[i] / g[i][i];
			b -= g[i] * q;
			c -= h[i] * q;
		}
	}
}

vec gtest(vec b) {
	vec c(n);
	for (int i=0; i<n; i++) {
		if (abs(g[i][i]) < 1e-12) {
			// whatever
		} else {
			ld q = b[i] / g[i][i];
			b -= g[i] * q;
			c += h[i] * q;
		}
	}
	return c;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=0; i<n; i++)
		g[i].resize(n), h[i].resize(n), cv2[i].resize(n);
	for (int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		e[u][v] += 1;
		e[v][u] += 1;
		deg[u] += 1;
		deg[v] += 1;
	}

	for (int i=0; i<n; i++) {
		vec b(n), c(n);
		if (a[i]) {
			b[i] = 1;
			c[i] = 1;
		} else {
			for (int j=0; j<n; j++)
				b[j] = e[i][j];
			b[i] = -deg[i];
		}
		gadd(b, c);
	}

	for (int i=0; i<n; i++) {
		vec b(n);
		b[i] = 1;
		cv[i] = gtest(b);
	}

	int kamen = count(a, a+n, 1);

	for (int i=0; i<n; i++) {
		if (a[i]) {
			for (int j=0; j<n; j++) {
				cv2[i] += cv[j] * ((ld)e[i][j] / deg[i]);
			}
		} else {
			cv2[i] = cv[i];
		}
	}

	mat z(kamen);

	int ii = 0;
	for (int i=0; i<n; i++) {
		if (!a[i])
			continue;
		int jj = 0;
		for (int j=0; j<n; j++) {
			if (!a[j])
				continue;
			z[ii][jj] = cv2[i][j];
			jj++;
		}
		ii++;
	}

	z ^= k-2;

	ld sol = 0;
	ii = 0;
	for (int i=0; i<n; i++) {
		if (!a[i])
			continue;
		sol += cv[0][i] * z[ii][kamen-1];
		ii++;
	}
	cout << setprecision(20) << fixed << sol << '\n'; // sto tolka picka si
}