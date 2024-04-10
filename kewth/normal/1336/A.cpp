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

const int maxn = 200005;
std::vector<int> G[maxn];
int size[maxn];
int a[maxn];

void dfs (int u, int fa, int d) {
	size[u] = 1;
	for (int v : G[u])
		if (v != fa) {
			dfs(v, u, d + 1);
			size[u] += size[v];
		}
	a[u] = d - size[u];
}

int main () {
	int n = read, m = read;
	for (int i = 1; i < n; i ++) {
		int u = read, v = read;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	dfs(1, 0, 1);
	std::sort(a + 1, a + n + 1);
	ll ans = 0;
	for (int i = 0; i < m; i ++)
		ans += a[n - i];
	printf("%lld\n", ans);
}