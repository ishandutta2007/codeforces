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
#include <cstring>
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

const int maxn = 500005;
char s[maxn];
int a[maxn << 1];

int main () {
	int T = read;
	while (T --) {
		scanf("%s", s + 1);
		int n = int(strlen(s + 1)), p = maxn, l = maxn, r = maxn;
		/* for (int i = 0; i <= n; i ++) */
		/* 	a[maxn - i] = a[maxn + i] = 0; */
		for (int i = 1; i <= n; i ++) {
			if (s[i] == '0')
				++ a[-- p];
			else
				++ a[p ++];
			l = std::min(l, p);
			r = std::max(r, p);
		}
		int q = maxn;
		for (int i = 1; i <= n; i ++) {
			if (q == r) {
				putchar('0'), -- a[-- q];
				if (!a[q]) -- r;
			}
			else if (q == l) {
				putchar('1'), -- a[q ++];
				if (!a[q - 1]) ++ l;
			}
			else if (a[q - 1] > 1)
				putchar('0'), -- a[-- q];
			else
				putchar('1'), -- a[q ++];
		}
		puts("");
	}
}