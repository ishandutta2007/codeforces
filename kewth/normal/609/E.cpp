#if 0
date +%Y.%m.%d


 (u, v)  u-v 

#endif
#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long lolong;

inline int input() { int x; scanf("%d", &x); return x; }

const int maxn = 200005, maxk = 20;

struct Edge {
	int x, y, w, id;
};
int head[maxn], nxt[maxn << 1], to[maxn << 1], val[maxn << 1], hp = 1;
int fa[maxn][maxk], famax[maxn][maxk], deep[maxn];
int setfa[maxn];
Edge e[maxn];
lolong ans[maxn];
bool intree[maxn];

int find(int x) {
	if(setfa[x] == x)
		return x;
	return setfa[x] = find(setfa[x]);
}

inline void add(int u, int v, int w) {
	nxt[++ hp] = head[u];
	head[u] = hp;
	to[hp] = v;
	val[hp] = w;
}

inline bool cmp(Edge a, Edge b) {
	return a.w < b.w;
}

void dfs(int u) {
	for(int i = head[u]; i; i = nxt[i])
		if(to[i] != fa[u][0]) {
			deep[to[i]] = deep[u] + 1;
			fa[to[i]][0] = u;
			famax[to[i]][0] = val[i];
			for(int k = 1; k < maxk; k ++) {
				fa[to[i]][k] = fa[fa[to[i]][k - 1]][k - 1];
				famax[to[i]][k] = std::max(famax[to[i]][k - 1],
						famax[fa[to[i]][k - 1]][k - 1]);
			}
			dfs(to[i]);
		}
}

int query(int x, int y) {
	/* debug("qu %d %d\n", x, y); */

	if(deep[x] < deep[y])
		std::swap(x, y);

	int res = 0;

	for(int k = maxk - 1; k >= 0; k --)
		if(deep[fa[x][k]] >= deep[y]) {
			res = std::max(res, famax[x][k]);
			/* debug("%d -> %d : %d\n", x, fa[x][k], famax[x][k]); */
			x = fa[x][k];
		}

	for(int k = maxk - 1; k >= 0; k --)
		if(fa[x][k] != fa[y][k]) {
			res = std::max(res, famax[x][k]);
			/* debug("%d -> %d : %d\n", x, fa[x][k], famax[x][k]); */
			x = fa[x][k];
			res = std::max(res, famax[y][k]);
			/* debug("%d -> %d : %d\n", y, fa[y][k], famax[y][k]); */
			y = fa[y][k];
		}

	if(x != y) {
		res = std::max(res, famax[x][0]);
		res = std::max(res, famax[y][0]);
		/* debug("%d -> %d : %d\n", x, fa[x][0], famax[x][0]); */
		/* debug("%d -> %d : %d\n", y, fa[y][0], famax[y][0]); */
	}

	/* debug("=%d\n", res); */

	return res;
}

int main() {
	int n = input(), m = input();

	for(int i = 1; i <= m; i ++) {
		e[i].x = input();
		e[i].y = input();
		e[i].w = input();
		e[i].id = i;
	}

	for(int i = 1; i <= n; i ++)
		setfa[i] = i;

	std::sort(e + 1, e + m + 1, cmp);

	lolong sum = 0;

	for(int i = 1; i <= m; i ++) {
		int x = e[i].x, y = e[i].y;
		if(find(x) != find(y)) {
			setfa[find(x)] = find(y);
			add(x, y, e[i].w);
			add(y, x, e[i].w);
			/* debug("%d %d %d\n", x, y, e[i].w); */
			intree[i] = true;
			sum += e[i].w;
		}
	}

	dfs(1);

	for(int i = 1; i <= m; i ++)
		if(intree[i])
			ans[e[i].id] = sum;
		else
			ans[e[i].id] = sum + e[i].w - query(e[i].x, e[i].y);

	for(int i = 1; i <= m; i ++)
		printf("%lld\n", ans[i]);
}