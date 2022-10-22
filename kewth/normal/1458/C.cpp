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

const int maxn = 1005, maxm = 100005;
int a[maxn][maxn], b[maxn][maxn];
char s[maxm];

int main () {
	int T = read;
	while (T --) {
		int n = read, m = read;
		auto f = [n] (int x) {
			x %= n;
			return x < 1 ? x + n : x;
		};
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
				read(a[i][j]);
		scanf("%s", s + 1);
		int to[3] = {0, 1, 2}, tx[3] = {0, 0, 0};
		for (int i = 1; i <= m; i ++) {
			if (s[i] == 'R') tx[1] += 1;
			if (s[i] == 'L') tx[1] -= 1;
			if (s[i] == 'D') tx[0] += 1;
			if (s[i] == 'U') tx[0] -= 1;
			if (s[i] == 'I') std::swap(to[1], to[2]), std::swap(tx[1], tx[2]);
			if (s[i] == 'C') std::swap(to[0], to[2]), std::swap(tx[0], tx[2]);
		}
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++) {
				int t[3] = {i, j, a[i][j]};
				b[f(t[to[0]] + tx[0])][f(t[to[1]] + tx[1])] = f(t[to[2]] + tx[2]);
			}
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
				printf("%d%c", b[i][j], " \n"[j == n]);
		if (T) puts("");
	}
}