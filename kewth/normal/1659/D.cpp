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

const int maxn = 200005;
int a[maxn], c[maxn], L[maxn];

int main () {
	int T = read;
	while (T --) {
		int n = read, j = 0;
		for (int i = 1; i <= n; i ++) {
			read(c[i]);
			if (L[j] + j - 1 < i) {
				++ j;
				if (j == i) {
					if (L[i - 1] == 0)
						a[i] = c[i] > 0 ? 1 : 0;
					else
						a[i] = 0;
				}
				else
					a[i] = 0;
			}
			else
				a[i] = 1;
			/* while (j < i and L[j] + j - 1 < i) */
			/* 	++ j; */
			/* if (j == i) a[i] = c[i] > 0 ? 1 : 0; */
			/* else a[i] = 1; */
			L[i] = c[i] - a[i] * (i - 1);
			printf("%d ", a[i]);
		}
		puts("");
	}
}