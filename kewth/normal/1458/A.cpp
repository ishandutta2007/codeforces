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
} read;

const int maxn = 200005;
ll a[maxn], b[maxn];

int main () {
	int n = read, m = read;
	for (int i = 1; i <= n; i ++) read(a[i]);
	for (int i = 1; i <= m; i ++) read(b[i]);
	ll g = 0;
	for (int i = 2; i <= n; i ++) g = std::__gcd(g, std::abs(a[i] - a[1]));
	for (int i = 1; i <= m; i ++)
		printf("%lld ", std::__gcd(g, a[1] + b[i]));
	puts("");
}