#include <bits/stdc++.h>
#define ll long long
using namespace std;
template <typename T>
void read(T &x) {
	x = 0; char c = getchar(); int f = 0;
	for (; !isdigit(c); c = getchar())
		f |= c == '-';
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

template <typename T>
void write(T x, char ed = '\n') {
	static short st[30], tp; 
	if (x < 0) putchar('-'), x = -x;
	do st[++tp] = x % 10, x /= 10; while (x);
	while (tp) putchar(st[tp--] | '0');
	putchar(ed);
}

const int N = 100005;
struct com {
	double x, y;
	com(double a = 0, double b = 0): x(a), y(b) {}
	com operator + (com b) { return com(x + b.x, y + b.y); }
	com operator - (com b) { return com(x - b.x, y - b.y); }
	com operator * (com b) { return com(x * b.x - y * b.y, x * b.y + y * b.x); }
}E[N<<2];
double h[105][N], g[55][N], f[105][N];
int lim, r[N<<2];
void FFT(com *A, int fl = 0) {
	for (int i = 0;i < lim; ++i)
		 if (r[i] > i) swap(A[i], A[r[i]]);
	for (int i = 1;i < lim; i <<= 1)
		for (int j = 0; j < lim; j += i << 1) {
			com *e = E + i, *f = A + j, *g = f + i;
			for (int k = 0;k < i; ++k) {
				com x = f[k], y = g[k] * e[k];
				f[k] = x + y, g[k] = x - y;
			}
		}
	if (fl) reverse(A + 1, A + lim);
}

void prework(int lim) {
	const double Pi = acos(-1.0);
	E[1] = com(1, 0);
	for (int i = 2;i < lim; i <<= 1) {
		com w(cos(Pi / i), sin(Pi / i));
		com *e0 = E + (i >> 1), *e1 = E + i;
		for (int j = 0;j < i; j += 2)
			e1[j] = e0[j >> 1], e1[j | 1] = e1[j] * w;
	}
}

const double inv = 1.0 / 100000.0;
int x[555], y[555], z[555], m, n, t, v;
void solve(int l, int r) {
	if (l > t) return;
	if (l == r) {
		for (int i = 1;i <= m; ++i) 
			g[x[i]][l] = min(g[x[i]][l], h[i][l] + z[i]);
		return;
	}
	int mid = (l + r) >> 1;
	solve(mid + 1, r);
	auto MulT = [&](double *g, double *f, double *h) {
		if (r - l <= 800) {
			for (int i = mid + 1;i <= r; ++i) 
				for (int j = i - mid;j + l <= i; ++j)
					h[i - j] += g[i] * f[j];
			return;
		}
		static com A[N<<2], B[N<<2];
		lim = 1;
		while (lim <= 2 * (r - l)) lim <<= 1;
		int len = lim >> 1;
		for (int i = 1;i < lim; ++i) ::r[i] = (::r[i >> 1] >> 1) | ((i & 1) ? len : 0);
		for (int i = 0;i < lim; ++i) A[i] = B[i] = 0;
		for (int i = mid + 1;i <= r; ++i) A[i - l].x = g[i];
		for (int i = 1;i <= r - l; ++i) B[i].x = f[i];
		FFT(A, 1), FFT(B);
		for (int i = 0;i < lim; ++i) A[i] = A[i] * B[i];
		FFT(A);
		for (int i = l;i <= mid; ++i) h[i] += A[i - l].x / lim;
	};
	for (int i = 1;i <= m; ++i) MulT(g[y[i]], f[i], h[i]);
	solve(l, mid);
}

ll d[114];
int main() {
	read(n), read(m), read(t), read(v);
	for (int i = 1;i <= m; ++i) {
		read(x[i]), read(y[i]), read(z[i]);
		for (int j = 1, v;j <= t; ++j) 
			read(v), f[i][j] = (double)v / 100000.0;
	}
	memset(d, 0x3f, sizeof(d)), d[n] = v;
	//printf ("v = %d\n", v);
	for (int T = 1;T <= n; ++T) {
		for (int i = 1;i <= m; ++i)
			d[x[i]] = min(d[x[i]], d[y[i]] + z[i]);
	}
	//for (int i = 1;i <= n; ++i) printf ("d[%d] = %lld\n", i, d[i]);
	for (int i = 1;i <= n; ++i) {
		for (int j = 0;j <= t; ++j) g[i][j] = 1e15;
		for (int j = t + 1;j <= 2 * t; ++j) g[i][j] = d[i];
	}
	for (int j = 0;j <= t; ++j) g[n][j] = 0;
	prework(1 << 18), solve(0, 2 * t);
	//for (int i = 1;i <= n; ++i)
		//for (int j = 0;j < t; ++j) assert(g[i][j] <= g[i][j + 1]);
	printf ("%.10lf\n", g[1][0]);
	return 0;
}