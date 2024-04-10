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

const int maxn = 202;
char s[maxn], t[maxn];

int main () {
	int T = read;
	while (T --) {
		int n = read, p = 0;
		scanf("%s", s + 1);
		for (int i = 1; i <= n; i ++)
			if (s[i] != 't')
				t[++ p] = s[i];
		for (int i = p + 1; i <= n; i ++)
			t[i] = 't';
		t[n + 1] = 0;
		puts(t + 1);
	}
}