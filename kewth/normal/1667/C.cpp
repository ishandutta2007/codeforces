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

/* const int maxn */ 

int main () {
	int n = read;
	int k = 1;
	while (k + (k + 1) / 2 < n) ++ k;
	int m = n - k;
	printf("%d\n", k);
	for (int i = 1; i <= k; i ++) {
		/* i, k - i + 1; */
		int a = i / 2, b = (i + 1) / 2;
		printf("%d %d\n",
				i + std::min(m, a),
				k - i + 1 + (m - std::min(m, b)));
	}
}