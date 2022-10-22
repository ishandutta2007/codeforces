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

const int maxn = 305;
char s[maxn][maxn];

int main () {
	int T = read;
	while (T --) {
		int n = read;
		for (int i = 1; i <= n; i ++)
			scanf("%s", s[i] + 1);
		int t[3] = {0, 0, 0};
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
				if (s[i][j] == 'X')
					++ t[(i + j) % 3];
		int min = std::min({t[0], t[1], t[2]});
		for (int x = 0; x < 3; x ++)
			if (t[x] == min) {
				for (int i = 1; i <= n; i ++) {
					for (int j = 1; j <= n; j ++)
						if (s[i][j] == 'X' and (i + j) % 3 == x)
							s[i][j] = 'O';
					s[i][n + 1] = 0;
					puts(s[i] + 1);
				}
				break;
			}
	}
}