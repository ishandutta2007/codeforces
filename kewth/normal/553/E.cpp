#if 0
date

(cf553e)
solution
#endif
#include <cstdio>
#include <algorithm>
#include <cmath>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
typedef long double ld;
struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	inline operator char () { char x[3]; return scanf("%s", x), *x; }
} read;

struct complex {
	ld real, imag;
};
complex operator + (complex x, complex y) {
	return {x.real + y.real, x.imag + y.imag};
}
complex operator - (complex x, complex y) {
	return {x.real - y.real, x.imag - y.imag};
}
complex operator * (complex x, complex y) {
	return {x.real * y.real - x.imag * y.imag,
		x.real * y.imag + x.imag * y.real};
}
void operator /= (complex &x, int y) {
	x.real /= y;
	x.imag /= y;
}

const int maxl = 1 << 17;
int ra[maxl];
complex W[maxl];

void init() {
	ld pi = std::acos(ld(-1));
	for(int m = 1; m < maxl; m <<= 1) {
		ld a = pi / m;
		for(int i = 0; i < m; i ++)
			W[m + i] = {std::cos(a * i), std::sin(a * i)};
	}
	for(int i = 1; i < maxl; i ++)
		ra[i] = (ra[i >> 1] >> 1) | (i & 1) * (maxl >> 1);
}

void DFT(complex *a, int n) {
	int k = maxl / n;
	for(int i = 0; i < n; i ++)
		if(i < ra[i] / k)
			std::swap(a[i], a[ra[i] / k]);
	for(int m = 1; m < n; m <<= 1)
		for(int i = 0; i < n; i += m << 1)
			for(int k = i; k < i + m; k ++) {
				complex a0 = a[k], a1 = a[k + m] * W[m + k - i];
				a[k] = a0 + a1;
				a[k + m] = a0 - a1;
			}
}

void IDFT(complex *a, int n) {
	std::reverse(a + 1, a + n);
	DFT(a, n);
	for(int i = 0; i < n; i ++)
		a[i] /= n;
}

inline int getlen(int n) {
	int len = 1;
	while(len < n) len <<= 1;
	return len;
}

const int maxn = 105, maxt = 20005;
int head[maxn], nxt[maxn], to[maxn], w[maxn];
ld p[maxn][maxt], f[maxn][maxt], g[maxn][maxt];
int dis[maxn][maxn];

complex a[maxl], b[maxl];
void solve(int n, int m, int l, int r) {
	if(l == r) {
		// debug("t=%d:\n", l);
		for(int u = 1; u < n; u ++) {
			f[u][l] = 1e300;
			for(int i = head[u]; i; i = nxt[i])
				f[u][l] = std::min(f[u][l], g[i][l] + w[i]);
			// debug("f[%d] = %.3Lf\n", u, f[u][l]);
		}
		return;
	}

	int mid = (l + r) >> 1;
	solve(n, m, l, mid);

	for(int i = 1; i <= m; i ++) {
		int len = getlen(r - l + mid - l + 1);
		std::fill(a, a + len, complex({0, 0}));
		std::fill(b, b + len, complex({0, 0}));
		for(int k = l; k <= mid; k ++)
			a[k - l] = {f[to[i]][k], 0};
		for(int k = l; k <= r; k ++)
			b[k - l] = {p[i][k - l], 0};
		DFT(a, len);
		DFT(b, len);
		for(int k = 0; k < len; k ++)
			a[k] = a[k] * b[k];
		IDFT(a, len);
		for(int k = mid + 1; k <= r; k ++)
			g[i][k] += a[k - l].real;
	}

	solve(n, m, mid + 1, r);
}

int main() {
	init();

	int n = read, m = read, t = read, x = read;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
			dis[i][j] =	i == j ? 0 : 1000000000;

	for(int i = 1; i <= m; i ++) {
		int u = read;
		to[i] = read;
		w[i] = read;
		nxt[i] = head[u];
		head[u] = i;
		dis[u][to[i]] = std::min(dis[u][to[i]], w[i]);
		for(int k = 1; k <= t; k ++)
			p[i][k] = int(read) / ld(1e5);
	}

	for(int k = 1; k <= n; k ++)
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j ++)
				dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);

	for(int i = 1; i <= n; i ++)
		f[i][0] = dis[i][n] + x;
	for(int i = 1; i <= m; i ++) {
		g[i][0] = f[to[i]][0];
		for(int k = 1; k <= t + 1; k ++)
			g[i][k] = g[i][k - 1] - p[i][k - 1] * f[to[i]][0];
	}

	// for(int i = 1; i <= n; i ++)
		// debug("%.1Lf\n", f[i][0]);

	solve(n, m, 1, t + 1);
	printf("%.7lf\n", double(f[1][t + 1]));
}