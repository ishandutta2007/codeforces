#if 0
date +%Y.%m.%d


#endif
#include <cstdio>
#include <algorithm>
#include <vector>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
} read;

const int maxn = 200005;
struct Edge { int to, w; };
std::vector<Edge> G[maxn];
int size[maxn];

ll minans, maxans;
int n;

void dfs(int u, int fa, int fw) {
	size[u] = 1;
	for(Edge e : G[u])
		if(e.to != fa) {
			dfs(e.to, u, e.w);
			size[u] += size[e.to];
		}
	if(size[u] & 1)
		minans += fw;
	maxans += 1ll * std::min(size[u], n - size[u]) * fw;
}

int main() {
	int T = read;
	while(T --) {
		n = read << 1;
		for(int i = 1; i <= n; i ++) G[i].clear();
		for(int i = 1; i < n; i ++) {
			int u = read, v = read, w = read;
			G[u].push_back({v, w});
			G[v].push_back({u, w});
		}
		minans = maxans = 0;
		dfs(1, 0, 0);
		printf("%lld %lld\n", minans, maxans);
	}
}