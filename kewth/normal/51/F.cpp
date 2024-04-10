#if 0
2020.01.10


 1 


cnt  cnt - 1 
#endif
#include <cstdio>
#include <algorithm>
#include <vector>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator ()(a...); }
} read;

const int maxn = 20005;
std::vector<int> G[maxn], T[maxn];

int dfn[maxn], low[maxn], belong[maxn], ip, bp;
int stack[maxn], sp;
std::vector<int> con[maxn];
void dfs(int u, int from) {
	low[u] = dfn[u] = ++ ip;
	stack[++ sp] = u;
	for(int v : G[u]) {
		if(!dfn[v]) {
			dfs(v, u);
			low[u] = std::min(low[u], low[v]);
		} else if(dfn[v] < dfn[u] and v != from)
			low[u] = std::min(low[u], dfn[v]);
	}
	if(low[u] == dfn[u]) {
		++ bp;
		while(stack[sp + 1] != u) {
			int x = stack[sp --];
			belong[x] = bp;
			con[bp].push_back(x);
		}
	}
}

bool vis[maxn];
void rebuild() {
	for(int u = 1; u <= bp; u ++) {
		vis[u] = 1;
		for(int x : con[u])
			for(int v : G[x])
				if(!vis[belong[v]]) {
					T[u].push_back(belong[v]);
					vis[belong[v]] = 1;
				}
		for(int x : con[u])
			for(int v : G[x])
				vis[belong[v]] = 0;
		vis[u] = 0;
	}
}

int f[maxn], g[maxn];
void dp(int u) {
	f[u] = g[u] = 1;
	for(int v : T[u])
		if(!f[v]) {
			dp(v);
			f[u] = std::max(f[u], f[v]);
			f[u] = std::max(f[u], g[u] + g[v]);
			g[u] = std::max(g[u], g[v] + 1);
		}
}

int main() {
	int n = read, m = read;
	for(int i = 1; i <= m; i ++) {
		int u = read, v = read;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	for(int i = 1; i <= n; i ++)
		if(!dfn[i])
			dfs(i, 0);
	rebuild();

	int tot = 0, leaf = 0, cnt = 0;
	for(int u = 1; u <= bp; u ++)
		if(T[u].size() < 2)
			++ leaf;

	for(int u = 1; u <= bp; u ++)
		if(!f[u]) {
			dp(u);
			tot += f[u];
			++ cnt;
			if(f[u] > 0) -- leaf;
			if(f[u] > 1) -- leaf;
			/* debug("%d\n", f[u]); */
		}
	/* debug("%d %d %d\n", tot, leaf, cnt); */

	printf("%d\n", n - tot - leaf + cnt - 1);
}