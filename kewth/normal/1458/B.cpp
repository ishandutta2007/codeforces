/*
 * Author: Kewth

 * Date:
  echo -n '  ' && date +%Y.%m.%d # Type "!!sh" in Vim.

 * Solution:
  To be updated after "Accept".

 * Digression:

 * CopyRight:
   __  __                  __   __
  |  |/  |.-----.--.--.--.|  |_|  |--.
  |     < |  -__|  |  |  ||   _|     |
  |__|\__||_____|________||____|__|__|

 */

#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

static struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator () (a...); }
} read;

const int maxn = 105;
int f[2][maxn][maxn * maxn];
int a[maxn], b[maxn];

int main () {
	int n = read, X = 100, S = 0;
	for (int i = 1; i <= n; i ++)
		read(a[i], b[i]);
	for (int i = 1; i <= n; i ++)
		S += b[i];
	for (int i = 0; i < 2; i ++)
		for (int j = 0; j <= n; j ++)
			for (int s = 0; s <= n * X; s ++)
				f[i][j][s] = - 1000000000;
	f[0][0][0] = 0;
	for (int i = 1; i <= n; i ++) {
		int o = i & 1;
		for (int j = 0; j <= i; j ++)
			for (int s = 0; s <= j * X; s ++)
				f[o][j][s] = f[!o][j][s];
		for (int j = 1; j <= i; j ++)
			for (int s = a[i]; s <= j * X; s ++)
				f[o][j][s] = std::max(f[o][j][s], f[!o][j - 1][s - a[i]] + b[i]);
	}
	for (int i = 1; i <= n; i ++) {
		int ans = 0;
		for (int s = 0; s <= i * X; s ++)
			ans = std::max(ans, std::min(s * 2, S + f[n & 1][i][s]));
		printf("%d.%d000000000 ", ans >> 1, ans & 1 ? 5 : 0);
	}
	puts("");
}