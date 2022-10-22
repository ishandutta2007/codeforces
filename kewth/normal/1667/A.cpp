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

const int maxn = 5050, maxs = 64000;
int a[maxn];
ll b[maxn];
int f[maxs];

int main () {
	int n = read;
	for (int i = 1; i <= n; i ++) read(a[i]);
	ll ans = 1000000000000000000;
	for (int k = 1; k <= n; k ++) {
		ll sum = 0;
		b[k] = 0;
		for (int i = k + 1; i <= n; i ++) {
			ll x = (b[i - 1] + a[i]) / a[i];
			sum += x;
			b[i] = a[i] * x;
		}
		for (int i = k - 1; i; i --) {
			ll x = (b[i + 1] + a[i]) / a[i];
			sum += x;
			b[i] = a[i] * x;
		}
		ans = std::min(ans, sum);
	}
	printf("%lld\n", ans);
}