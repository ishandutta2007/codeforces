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
#include <vector>
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
int a[maxn];
int tot[maxn], ntot[maxn];
int val[maxn];
std::vector<int> G[maxn];

int main () {
	int T = read;
	while (T --) {
		int n = read;
		for (int i = 1; i <= n; i ++) {
			ntot[i] = tot[i] = 0;
			val[i] = i;
			G[i].clear();
		}
		for (int i = 1; i <= n; i ++) ++ tot[a[i] = read], val[i] = i;
		std::sort(val + 1, val + n + 1,
				[] (int x, int y) { return tot[x] < tot[y]; });

		int l = 1;
		while (1) {
			while (l <= n and ntot[val[l]] == tot[val[l]]) ++ l;
			if (l > n) break;
			val[n + 1] = val[l];
			for (int i = l; i <= n; i ++) {
				G[val[i]].push_back(val[i + 1]);
				++ ntot[val[i]];
			}
		}

		for (int i = 1; i <= n; i ++) {
			printf("%d ", G[a[i]].back());
			G[a[i]].pop_back();
		}
		puts("");
	}
}