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
		ll x = read;
		int y = read;
		if (x % y == 0) {
			ll z = x;
			ll min = x;
			for (int d = 2; d * d <= y; d ++) {
				if (y % d == 0) {
					int kx = 0, ky = 0;
					while (y % d == 0) y /= d, ++ ky;
					while (x % d == 0) x /= d, ++ kx;
					/* debug("%d %d\n", kx, ky); */
					ll t = 1;
					for (int k = 0; k < kx - ky + 1; k ++)
						t *= d;
					min = std::min(min, t);
				}
			}
			if (y > 1) {
				ll t = 1;
				while (x % y == 0) x /= y, t *= y;
				min = std::min(min, t);
			}
			printf("%lld\n", z / min);
		}
		else
			printf("%lld\n", x);
	}
}