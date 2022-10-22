#if 0
date +%Y.%m.%d


#endif
#include <cstdio>
#include <algorithm>
#include <vector>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator () (a...); }
} read;

const int maxn = 2020, mod = 1000000007;
char s[maxn][maxn];
int f[maxn][maxn], g[maxn][maxn];
int sf[maxn][maxn], sg[maxn][maxn];
int down[maxn][maxn], right[maxn][maxn];

int main () {
	int n = read, m = read;
	for (int i = 1; i <= n; i ++)
		scanf("%s", s[i] + 1);

	for (int i = n; i; i --)
		for (int j = m; j; j --) {
			down[i][j] = down[i + 1][j] + (s[i][j] == 'R');
			right[i][j] = right[i][j + 1] + (s[i][j] == 'R');
		}

	sf[1][1] = 1;
	sf[1][m - right[1][1] + 1] = mod - 1;
	sg[1][1] = 1;
	sg[n - down[1][1] + 1][1] = mod - 1;

	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++) {
			(sg[i + 1][j] += sg[i][j]) %= mod;
			(sf[i][j + 1] += sf[i][j]) %= mod;

			f[i][j] = sf[i][j];
			g[i][j] = sg[i][j];

			(sg[i + 1][j] += f[i][j]) %= mod;
			(sg[n - down[i + 1][j] + 1][j] += mod - f[i][j]) %= mod;
			(sf[i][j + 1] += g[i][j]) %= mod;
			(sf[i][m - right[i][j + 1] + 1] += mod - g[i][j]) %= mod;
		}

	printf("%lld\n", 1ll * (mod + 1) / 2 * (f[n][m] + g[n][m]) % mod);
}