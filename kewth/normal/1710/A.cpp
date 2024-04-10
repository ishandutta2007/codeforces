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
#include <functional>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

static struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator () (a...); }
} read;

const int maxn = 100005;
int a[maxn];

bool check (int n, int m, int k) {
	ll sum = 0;
	for (int i = 1; i <= k; i ++)
		if (a[i] / n >= 2) {
			if (sum == m - 1) {
				if (a[1] / n >= 3) return 1;
				else return 0;
			}
			sum += a[i] / n;
			if (sum >= m) return 1;
		}
	return 0;
}

int main () {
	int T = read;
	while (T --) {
		int n = read, m = read, k = read;
		for (int i = 1 ; i <= k; i ++) read(a[i]);
		std::sort(a + 1, a + k + 1, std::greater<int>());
		if (check(n, m, k) or check(m, n, k)) puts("Yes");
		else puts("No");
	}
}