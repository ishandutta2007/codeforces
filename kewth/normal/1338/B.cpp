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
int f[maxn], g[maxn], shit[2];

void dp (int u, int fa, int d) {
	bool leaf = 0;
	for (int v : G[u])
		if (v != fa) {
			dp(v, u, d + 1);
			g[u] += g[v] + 1;
			if (G[v].size() == 1)
				-- g[u], leaf = 1;
		}
	g[u] += leaf;
	shit[d & 1] |= G[u].size() == 1;
}

int main () {
	int n = read;
	for (int i = 1; i < n; i ++) {
		int u = read, v = read;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	int rt = 1;
	for (int i = 2; i <= n; i ++)
		if (G[i].size() > 1)
			rt = i;
	dp(rt, 0, 0);

	printf("%d %d\n", shit[0] and shit[1] ? 3 : 1, g[rt]);
}