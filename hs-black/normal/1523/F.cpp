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
	if (x < 0) putchar('-'), x = -x;
	static short st[30], tp;
	do st[++tp] = x % 10, x /= 10; while (x);
	while (tp) putchar(st[tp--] | '0');
	putchar(ed);
}

const int N = 14, M = 105;
int f[M][(1 << N) + 5], g[M][(1 << N) + 5], m, n;
int md[N + 5][(1 << N) + 5], mmd[M][(1 << N) + 5];
struct node {
	int x, y, tim;
	bool operator < (const node &i) const { return tim < i.tim; }
}poi[M];
int X[N+5], Y[N+5];
int main() {
	read(n), read(m);
	for (int i = 0;i < n; ++i) read(X[i]), read(Y[i]);
	for (int i = 0;i < m; ++i)
		read(poi[i].x), read(poi[i].y), read(poi[i].tim);
	sort(poi, poi + m), memset(g, 0x3f, sizeof(g)), memset(f, -1, sizeof(f));
	for (int i = 0;i < n; ++i) g[0][1 << i] = 0;
	for (int i = 0;i < m; ++i) f[i][0] = 1;
	int all = 1 << n;
	for (int i = 0;i < n; ++i) {
		for (int j = 0;j < all; ++j) {
			int v = g[0][0];
			for (int k = 0;k < n; ++k) if (j >> k & 1) 
				v = min(v, abs(X[k] - X[i]) + abs(Y[k] - Y[i]));
			md[i][j] = v;
		}
	}
	for (int i = 0;i < m; ++i) {
		for (int j = 0;j < all; ++j) {
			int v = g[0][0];
			for (int k = 0;k < n; ++k) if (j >> k & 1)
				v = min(v, abs(poi[i].x - X[k]) + abs(poi[i].y - Y[k]));
			mmd[i][j] = v;
		}
	}
	for (int i = 0;i < m; ++i) {
		for (int j = 0;j < all; ++j) {
			for (int k = 0;k < n; ++k) if (~j >> k & 1) 
				g[i][j | 1 << k] = min(g[i][j | 1 << k], g[i][j] + md[k][j]);
			for (int k = 0;k < m; ++k) 
				if (g[i][j] + mmd[k][j] <= poi[k].tim) f[k][j] = i + 1;
			for (int k = 0;k < m; ++k) if (f[k][j] == i) {
				for (int t = k + 1;t < m; ++t) 
					if (abs(poi[t].x - poi[k].x) + abs(poi[t].y - poi[k].y) + poi[k].tim <= poi[t].tim)
						f[t][j] = i + 1;
				for (int t = 0;t < n; ++t) if (~j >> t & 1) 
					g[i][j | 1 << t] = min(g[i][j | 1 << t], poi[k].tim + mmd[k][1 << t]);
			}
		}
		for (int j = 0;j < all; ++j)
			for (int k = 0;k < m; ++k) if (f[k][j] == i + 1) 
				g[i + 1][j] = min(g[i + 1][j], poi[k].tim);
	}
	int ans = 0;
	for (int i = 0;i < m; ++i) 
		for (int j = 0;j < all; ++j)
			ans = max(ans, f[i][j]);
	write(ans);
	return 0;
}