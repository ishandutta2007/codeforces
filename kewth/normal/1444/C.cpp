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
#include <map>
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
int col[maxn];
bool ban_c[maxn];

std::map<par, int> eid;
int eip = 0;
std::vector<par> es[maxn];

std::vector<int> G[maxn];
int dfscol[maxn];
int bel[maxn], bp;
void dfs (int u) {
	bel[u] = bp;
	for (int v : G[u])
		if (!bel[v])
			dfscol[v] = dfscol[u] ^ 1, dfs(v);
		else if (dfscol[v] == dfscol[u])
			ban_c[col[u]] = 1;
}

std::vector<par> B[maxn];
int bcol[maxn];
bool shit = 0;
void dfs2 (int x) {
	for (par e : B[x]) {
		int y = e.first, c = e.second;
		if (bcol[y] == -1)
			bcol[y] = bcol[x] ^ c, dfs2(y);
		else if ((bcol[y] ^ bcol[x]) != c)
			shit = 1;
	}
}

int main () {
	int n = read, m = read, cmax = read;
	for (int i = 1; i <= n; i ++) read(col[i]);
	for (int i = 1; i <= m; i ++) {
		int u = read, v = read;
		if (col[u] == col[v]) {
			G[u].push_back(v);
			G[v].push_back(u);
		} else {
			if (col[u] > col[v]) std::swap(u, v);
			int &E = eid[par(col[u], col[v])];
			if (!E) E = ++ eip;
			es[E].push_back(par(u, v));
		}
	}

	for (int u = 1; u <= n; u ++)
		if (!bel[u])
			++ bp, dfs(u);

	int tot = 0;
	for (int c = 1; c <= cmax; c ++)
		if (!ban_c[c])
			++ tot;
	ll ans = ll(tot - 1) * tot / 2;

	for (int E = 1; E <= eip; E ++) {
		par tmp = es[E][0];
		if (ban_c[col[tmp.first]] or ban_c[col[tmp.second]])
			continue;
		std::vector<int> xlist;
		for (par p : es[E]) {
			int u = p.first, v = p.second, c = dfscol[u] ^ dfscol[v];
			int x = bel[u], y = bel[v];
			xlist.push_back(x);
			xlist.push_back(y);
			B[x].push_back(par(y, c));
			B[y].push_back(par(x, c));
		}
		shit = 0;
		for (int x : xlist) bcol[x] = -1;
		for (int x : xlist)
			if (bcol[x] == -1)
				bcol[x] = 0, dfs2(x);
		if (shit) -- ans;
		/* if (shit) debug("%d %d\n", col[tmp.first], col[tmp.second]); */
		for (int x : xlist) B[x].clear();
	}

	printf("%lld\n", ans);
}