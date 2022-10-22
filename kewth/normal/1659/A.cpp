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

int main () {
	int T = read;
	while (T --) {
		int n = read, r = read, b = read;
		int Q = r / (b + 1), R = r % (b + 1);
		for (int i = 1; i <= R; i ++) {
			for (int j = 1; j <= Q + 1; j ++)
				putchar('R');
			putchar('B');
		}
		for (int i = R + 1; i <= b + 1; i ++) {
			for (int j = 1; j <= Q; j ++)
				putchar('R');
			if (i <= b) putchar('B');
		}
		puts("");
	}
}