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
#include <queue>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
typedef std::pair<int, int> par;

static struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator () (a...); }
} read;

const int maxn = 500005;
int a[maxn], f[maxn];
ll pre[maxn], tmp[maxn];
int bit[maxn];

int query (int x) {
	int ans = -1000000000;
	for (int k = x; k; k -= k &-k)
		ans = std::max(ans, bit[k]);
	return ans;
}

void modify (int x, int w, int n) {
	for (int k = x; k <= n; k += k &-k)
		bit[k] = std::max(bit[k], w);
}

int main () {
	std::priority_queue<par> q;
	int T = read;
	while (T --) {
		int n = read;
		for (int i = 1; i <= n; i ++)
			tmp[i] = pre[i] = pre[i - 1] + (a[i] = read);
		std::fill(bit, bit + n + 1, -1000000000);
		std::sort(tmp + 1, tmp + n + 1);
		for (int i = 1; i <= n; i ++) {
			int x = int(std::lower_bound(tmp + 1, tmp + n + 1, pre[i]) - tmp);
			if (pre[i] > 0) f[i] = i;
			else {
				if (a[i] > 0) f[i] = f[i - 1] + 1;
				if (a[i] == 0) f[i] = f[i - 1];
				if (a[i] < 0) f[i] = f[i - 1] - 1;
				f[i] = std::max(f[i], query(x - 1) + i);
			}
			modify(x, f[i] - i, n);
			/* debug("%d %d\n", x, f[i]); */
		}
		printf("%d\n", f[n]);
	}
}