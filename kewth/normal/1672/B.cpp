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

const int maxn = 200005;
char s[maxn];
int main () {
	int T = read;
	while (T --) {
		scanf("%s", s + 1);
		int n = int(strlen(s + 1));
		bool ans = 1;
		int a = 0, b = 0;
		for (int i = 1; i <= n; i ++) {
			if (s[i] == 'A') ++ a;
			if (s[i] == 'B') {
				++ b;
				if (a < b)
					ans = 0;
			}
		}
		if (s[n] == 'A') ans = 0;
		/* for (int k = n; k; ) { */
		/* 	if (s[k] == 'A' or k == 1) { */
		/* 		ans = 0; */
		/* 		break; */
		/* 	} */
		/* 	k -= 2; */
		/* 	while (k and s[k] == 'A') */
		/* 		-- k; */
		/* } */
		puts(ans ? "YES" : "NO");
	}
}