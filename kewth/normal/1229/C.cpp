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
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator () (a...); }
} read;

const int maxn = 100005;
std::vector<int> G[maxn];
int deg[maxn];

ll ans = 0;
void update (int u, int t) {
	ans += (deg[u] - ll(G[u].size())) * ll(G[u].size()) * t;
}

int main () {
	int n = read, m = read;
	for (int i = 1; i <= m; i ++) {
		int u = read, v = read;
		if (u > v) std::swap(u, v);
		G[u].push_back(v);
		++ deg[u];
		++ deg[v];
	}

	for (int u = 1; u <= n; u ++)
		update(u, 1);
	printf("%lld\n", ans);

	int q = read;
	while (q --) {
		int u = read;
		for (int x : G[u]) {
			update(x, -1);
			G[x].push_back(u);
			update(x, 1);
		}
		update(u, -1);
		G[u].clear();
		printf("%lld\n", ans);
	}
}