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
typedef std::pair<int, int> par;

static struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator () (a...); }
} read;

const int maxn = 100005, maxc = 30;
/* std::vector<int> G[maxc][maxn]; */
struct dsu {
	int fa[maxn];
	int find (int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
	inline void link (int x, int y) { x = find(x), y = find(y), fa[x] = y; }
	inline void init (int n) { for (int i = 1; i <= n; i ++) fa[i] = i; }
} g[maxc], odd[maxc];
bool link_even[maxn], LinkEven[maxc][maxn];

int main () {
	int n = read, m = read;
	for (int k = 0; k < maxc; k ++)
		g[k].init(n), odd[k].init(n);
	std::fill(link_even, link_even + n + 1, 0);
	for (int k = 0; k < maxc; k ++)
		std::fill(LinkEven[k], LinkEven[k] + n + 1, 0);
	for (int i = 1; i <= m; i ++) {
		int u = read, v = read, w = read;
		for (int k = 0; k < maxc; k ++)
			if (w >> k & 1)
				g[k].link(u, v);
		if (w & 1) {
			for (int k = 1; k < maxc; k ++)
				if (w >> k & 1)
					odd[k].link(u, v);
		} else
			link_even[u] = link_even[v] = 1;
	}
	for (int i = 1; i <= n; i ++)
		if (link_even[i])
			for (int k = 1; k < maxc; k ++)
				LinkEven[k][odd[k].find(i)] = 1;
	int q = read;
	while (q --) {
		int u = read, v = read, get = 0;
		for (int k = 0; k < maxc; k ++)
			if (g[k].find(u) == g[k].find(v))
				++ get;
		if (get) puts("0");
		else {
			bool fuck = 0;
			for (int k = 1; k < maxc; k ++)
				fuck |= LinkEven[k][odd[k].find(u)];
			if (fuck) puts("1");
			else puts("2");
			/* if (get == 1 and find(0, u) == find(0, v)) */
		}
	}
}