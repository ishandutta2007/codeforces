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

const int maxn = 300005;
int a[maxn], at[maxn], tot[maxn];

int main () {
	int T = read;
	while (T --) {
		int n = read;
		std::fill(tot, tot + n + 2, 0);
		for (int i = 1; i <= n; i ++) {
			int x = read;
			at[x] = i;
			++ tot[x];
		}
		bool ok = 1;
		for (int x = 1; x <= n; x ++)
			ok &= tot[x] == 1;
		putchar(ok ? '1' : '0');
		int l = 1, r = n, x = 1;
		while (x <= n and tot[x] == 1) {
			if (at[x] == l) ++ l;
			else if (at[x] == r) -- r;
			else break;
			++ x;
		}
		if (tot[x]) ++ x;
		for (int i = 2; i <= n - x + 1; i ++)
			putchar('0');
		for (int i = std::max(2, n - x + 2); i <= n; i ++)
			putchar('1');
		puts("");
	}
}