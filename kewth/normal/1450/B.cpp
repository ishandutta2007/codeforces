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
int px[maxn], py[maxn];

int main () {
	int T = read;
	while (T --) {
		int n = read, m = read;
		for (int i = 1; i <= n; i ++)
			read(px[i], py[i]);
		int ans = -1;
		for (int i = 1; i <= n; i ++) {
			bool ok = 1;
			for (int j = 1; j <= n; j ++)
				ok &= std::abs(px[i] - px[j]) + std::abs(py[i] - py[j]) <= m;
			if (ok)
				ans = 1;
		}
		printf("%d\n", ans);
	}
}