#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 2e3 + 5;
const int mod = 1e9 + 7;

inline void uadd(int &x, int y) {
	x += y - mod;
	x += x >> 31 & mod;
}

int n;
char s[mxn], t[mxn];
int f[mxn][mxn][2], g[mxn][mxn][2];

inline bool cans(int p, int c) { return s[p] != '0' + (c ^ 1); }
inline bool cant(int p, int c) { return t[p] != '0' + (c ^ 1); }

void Main() {
	scanf("%d", &n);
	scanf("%s", s);
	scanf("%s", t);
	rep(i, n + 1) rep(j, n + 1) rep(last, 2)
		f[i][j][last] = g[i][j][last] = 0;
	f[0][0][0] = 1;
	g[0][0][0] = 0;
	rep(i, n) {
		rep(j, n + 1) {
			rep(last, 2) {
				rep(x, 2) rep(y, 2) if (cans(i, x) && cant(i, y)) {
					int nx = x, ny = y, nj = j;
					if (i && j && x == last) -- nj, nx ^= 1;
					if (nx != ny) ++ nj;
					uadd(f[i + 1][nj][nx], f[i][j][last]);
					uadd(g[i + 1][nj][nx], g[i][j][last]);
					uadd(g[i + 1][nj][nx], 1LL * f[i][j][last] * nj % mod);
				}
			}
		}
	}
	int ans = (g[n][0][0] + g[n][0][1]) % mod;
	printf("%d\n", ans);
}

int main() {
	int T; scanf("%d", &T);
	while (T --) Main();
	return 0;
}