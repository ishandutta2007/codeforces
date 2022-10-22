#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

struct num {
	double a, b;

	num(): a(), b() {}
	num(double _a): a(_a), b() {}
	num(double _a, double _b): a(_a), b(_b) {}

	inline num &operator += (const num &oth) { a += oth.a, b += oth.b; return *this; }
	inline num &operator -= (const num &oth) { a -= oth.a, b -= oth.b; return *this; }
	inline num &operator *= (const num &oth) { return *this = num(a * oth.a - b * oth.b, a * oth.b + b * oth.a); }

	inline num operator + (const num &oth) const { return num(*this) += oth; }
	inline num operator - (const num &oth) const { return num(*this) -= oth; }
	inline num operator * (const num &oth) const { return num(*this) *= oth; }

	num &operator /= (const double &x) { a /= x, b /= x; return *this; }

	inline double real() { return a; }
	inline double imag() { return b; }
};

constexpr double pi = std::acos(-1);

const int mxn = 1 << 16;
int r[mxn];
num w[mxn];

void fft(num a[], int n, bool flag = false) {
	for (int h = 1; h < n; h <<= 1)
		for (int i = 0; i < h; ++ i)
			w[h + i] = num(std::cos(pi / h * i), std::sin(pi / h * i));
	for (int i = 1; i < n - 1; ++ i) {
		r[i] = r[i >> 1] >> 1 | (i & 1 ? n >> 1 : 0);
		if (i < r[i]) std::swap(a[i], a[r[i]]);
	}
	for (int h = 1; h < n; h <<= 1)
		for (int i = 0; i < n; i += h << 1) {
			auto A0 = a + i, A1 = a + i + h;
			auto W = w + h;
			for (int j = 0; j < h; ++ j) {
				num v = *A1 * *W;
				*A1 = *A0 - v;
				*A0 += v;
				++ A0, ++ A1, ++ W;
			}
		}
	if (flag) {
		std::reverse(a + 1, a + n);
		rep(i, n) a[i] /= n;
	}
}

struct poly : std::vector <double> {
	poly(int n, double x = 0) { assign(n, x); }
	poly(std::initializer_list <double> l) { clear(); for (double x : l) push_back(x); }

	friend inline double get(const poly &v, int k) { return k < (int) v.size() ? v[k] : 0; }

	friend inline poly operator * (const poly &a, const poly &b) {
		poly c(a.size() + b.size() - 1);
		if (1LL * a.size() * b.size() <= 128LL * c.size()) {
			rep(i, a.size()) rep(j, b.size()) c[i + j] += a[i] * b[j];
			return c;
		}
		int sz = 1;
		while (sz < (int) c.size()) sz <<= 1;
		static num A[mxn], B[mxn];
		rep(i, sz) A[i] = get(a, i);
		rep(i, sz) B[i] = get(b, i);
		fft(A, sz); fft(B, sz);
		rep(i, sz) A[i] *= B[i];
		fft(A, sz, true);
		rep(i, c.size()) c[i] = A[i].real();
		return c;
	}
};

int n, m, t, x;
int U[105], V[105], W[105];
std::vector <int> P[105];
std::vector <double> dp[55];
std::vector <double> rem[105];

void solve(int l, int r) {
	if (l > r) return ;
	if (l == r) {
		rep(i, m) {
			int u = U[i], v = V[i], w = W[i];
			dp[u][l] = std::min(dp[u][l], rem[i][l] + w);
		}
		return ;
	}
	int md = (l + r) >> 1;
	solve(md + 1, r);
	rep(i, m) {
		int u = U[i], v = V[i], w = W[i];
		/*
		for (int a = l; a <= md; ++ a) for (int b = 1; b <= t; ++ b) {
			int c = a + b;
			if (c > md && c <= r) {
				rem[i][a] += dp[v][c] * P[i][b];
			}
		}
		*/
		// [md + 1, r]
		// [-t, -1] --> [0, t - 1] (+t)
		int mx = std::min(t, r - l);
		poly A(r - (md + 1) + 1), B(mx);
		for (int a = md + 1; a <= r; ++ a) A[a - md - 1] = dp[v][a];
		bool ok = false;
		for (int b = 1; b <= t && b <= r - l; ++ b) {
			B[mx - b] = P[i][b] / 1e5;
			ok |= P[i][b];
		}
		if (!ok) continue;
		poly C = A * B;
		for (int a = l; a <= md; ++ a) rem[i][a] += get(C, a + mx - md - 1);
	}
	solve(l, md);
}

namespace FIO {
    const int mxsz = 1 << 23;
    char ibuf[mxsz], *iend = ibuf + mxsz, *ipos = iend;
    char get_char() {
        if (ipos == iend) iend = (ipos = ibuf) + fread(ibuf, 1, mxsz, stdin);
        return ipos == iend ? EOF : *ipos ++;
    }
}

using FIO::get_char;

inline void read(int &x) {
    x = 0; char c = get_char();
    while (c <= 32) c = get_char();
    while (c > 32) x = x * 10 + c - 48, c = get_char();
}

int main() {
	read(n); read(m); read(t); read(x);
	rep(i, m) {
		read(U[i]); read(V[i]); read(W[i]);
		-- U[i], -- V[i];
		P[i].resize(t + 1);
		for (int k = 1; k <= t; ++ k) read(P[i][k]);
	}
	rep(i, n) dp[i].assign(t + 2, 1e9);
	for (int i = 0; i <= t + 1; ++ i) dp[n - 1][i] = (i > t) * x;
	rep(_, n) rep(i, m) {
		int u = U[i], v = V[i], w = W[i];
		dp[u][t + 1] = std::min(dp[u][t + 1], dp[v][t + 1] + w);
	}
	rep(i, m) {
		rem[i].resize(t + 1);
		int u = U[i], v = V[i], w = W[i];
		static double sum[20005];
		sum[t + 1] = 0;
		for (int j = t; j; -- j) sum[j] = sum[j + 1] + P[i][j] / 1e5;
		for (int a = 0; a <= t; ++ a) {
			int minb = t + 1 - a;
			rem[i][a] = dp[v][t + 1] * sum[minb];
		}
	}
	solve(0, t);
	printf("%.10f\n", dp[0][0]);
	return 0;
}