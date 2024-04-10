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
bool a[maxn];
int at[maxn];
int pre[maxn];

int main () {
	int n = read, q = read, m = 0;
	scanf("%s", s + 1);
	for (int i = 1; i < n; i ++) {
		if (s[i] == s[i + 1]) {
			a[++ m] = s[i] == '1';
		}
		at[i] = m;
	}
	for (int i = 1; i <= n; i ++)
		pre[i] = pre[i - 1] + a[i];
	while (q --) {
		int l = read, r = read;
		l = at[l - 1] + 1;
		r = at[r - 1];
		if (l > r) puts("1");
		else {
			int x = pre[r] - pre[l - 1], y = r - l + 1 - x;
			if (x > y) std::swap(x, y);
			printf("%d\n", 1 + x + (y - x));
		}
	}
}