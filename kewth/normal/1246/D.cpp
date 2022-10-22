#if 0
date +%Y.%m.%d


#endif
#include <cstdio>
#include <algorithm>
#include <vector>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
typedef std::pair<int, int> par;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
} read;

const int maxn = 100005;
int fa[maxn];
int len[maxn], son[maxn];
bool f[maxn];
std::vector<int> G[maxn];
int ans[maxn], ap;

void dp (int u) {
	for (int v : G[u])
		dp(v);
	std::sort(G[u].begin(), G[u].end(), [] (int x, int y) {
				return len[x] < len[y];
			});
	if (!G[u].empty()) son[u] = G[u].back();
	len[u] = len[son[u]] + 1;
}

void dfs (int u) {
	if (f[u]) return;
	/* debug("dfs %d\n", u); */
	if (G[u].empty()) return;
	for (size_t i = G[u].size() - 1; i; i --) {
		dfs(G[u][i]);
		ans[++ ap] = G[u][i];
		G[G[u][i - 1]].push_back(G[u][i]);
	}
	while (G[u].size() > 1) G[u].pop_back();
	if (!G[u].empty())
		dfs(G[u][0]);
	f[u] = 1;
}

int main () {
	int n = read;
	for (int i = 2; i <= n; i ++) {
		fa[i] = read + 1;
		G[fa[i]].push_back(i);
	}

	dp(1);
	dfs(1);
	for (int x = 1; x; x = G[x].empty() ? 0 : G[x][0])
		printf("%d ", x - 1);
	puts("");
	printf("%d\n", ap);
	for (int i = ap; i; i --)
		printf("%d ", ans[i] - 1);
	puts("");
}