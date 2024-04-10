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
	/* inline operator ll () { ll x; return scanf("%lld", &x), x; } */
	/* template<class T> inline void operator () (T &x) { x = *this; } */
	/* template<class T, class ...A> inline void operator () (T &x, A &...a) */
	/* { x = *this; this -> operator () (a...); } */
} read;

const int maxn = 1000005;
char s[maxn], t[maxn];
int ans[maxn << 1], ap;

int main () {
	int T = read;
	while (T --) {
		int n = read;
		scanf("%s", s + 1);
		scanf("%s", t + 1);
		ap = 0;

		for (int i = 1; i <= n; i ++) s[i] -= '0', t[i] -= '0';

		int rev = 0, l = 1, r = n;
		for (int i = n; i; i --) {
			int p = rev ? r : l;
			if ((s[p] ^ rev) == t[i]) {
				ans[++ ap] = 1;
				s[p] ^= 1;
			}
			ans[++ ap] = i;
			rev ? -- r : ++ l;
			rev ^= 1;
		}

		printf("%d", ap);
		for (int i = 1; i <= ap; i ++) printf(" %d", ans[i]);
		puts("");
	}
}