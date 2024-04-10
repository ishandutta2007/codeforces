#if 0
date +%Y.%m.%d

DP  f[u][i]  u  i  O(n) 
#endif
#include <cstdio>
#include <vector>
#define debug(...) fprintf(stderr, __VA_ARGS__)

inline int input() { int x; scanf("%d", &x); return x; }

const int maxn = 1000005;
std::vector<int> G[maxn];
int *f[maxn], memory_pool[maxn];
int len[maxn], son[maxn];
int ans[maxn];

inline void add(int u, int v) {
	G[u].push_back(v);
	G[v].push_back(u);
}

void dfs(int u, int fa) {
	for(int v : G[u])
		if(v != fa) {
			dfs(v, u);
			if(len[v] > len[son[u]])
				son[u] = v;
		}
	len[u] = len[son[u]] + 1;
	debug("%d -> %d\n", u, son[u]);
}

void dp(int u, int fa) {
	f[u][0] = 1;
	if(son[u]) {
		f[son[u]] = f[u] + 1;
		dp(son[u], u);
		int max = 0;
		for(int v : G[u])
			if(v != fa and v != son[u]) {
				f[v] = f[u] + len[u];
				dp(v, u);
				max = std::max(max, len[v]);
				for(int i = 0; i < len[v]; i ++)
					f[u][i + 1] += f[v][i];
			}
		for(int i = 1; i <= max; i ++)
			if(f[u][i] > f[u][ans[u]])
				ans[u] = i;
		if(ans[son[u]] >= max and f[u][ans[son[u]] + 1] > f[u][ans[u]])
			ans[u] = ans[son[u]] + 1;
	}
}

int main() {
	int n = input();
	for(int i = 1; i < n; i ++)
		add(input(), input());
	dfs(1, 0);
	f[1] = memory_pool;
	dp(1, 0);
	for(int u = 1; u <= n; u ++)
		printf("%d\n", ans[u]);
}