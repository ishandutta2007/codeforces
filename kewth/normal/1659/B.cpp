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
char s[maxn];
int f[maxn];

int main () {
	int T = read;
	while (T --) {
		int n = read, k = read;
		scanf("%s", s + 1);
		std::fill(f, f + n + 1, 0);
		if (k & 1)
			for (int i = 1; i <= n; i ++)
				s[i] = s[i] == '1' ? '0' : '1';
		for (int i = 1; i <= n; i ++)
			if (s[i] == '0' and k) {
				f[i] += 1;
				k -= 1;
				s[i] = '1';
			}
		if (k & 1)
			s[n] = '0';
		f[n] += k;
		puts(s + 1);
		for (int i = 1; i <= n; i ++)
			printf("%d ", f[i]);
		puts("");
	}
}