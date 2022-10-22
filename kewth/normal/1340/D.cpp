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
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator () (a...); }
} read;

const int maxn = 100005;
std::vector<int> G[maxn];
std::vector<par> ans;

void dfs (int u, int fa, int x, int m) {
	int f = x;
	ans.push_back(par(u, x));
	int tot = int(G[u].size() - 1);
	for (int v : G[u])
		if (v != fa) {
			if (x == m)
				ans.push_back(par(u, x = f - tot - 1));
			dfs(v, u, ++ x, m);
			-- tot;
		}
	if (u > 1) {
		if (x >= f)
			ans.push_back(par(u, x = f - 1));
		if (x < f - 1) debug("asd\n");
		ans.push_back(par(fa, ++ x));
	}
}

int main () {
	int n = read;
	for (int i = 1; i < n; i ++) {
		int u = read, v = read;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	int m = 0;
	for (int i = 1; i <= n; i ++)
		m = std::max(m, int(G[i].size()));
	dfs(1, 0, 0, m);
	printf("%lu\n", ans.size());
	for (par p : ans)
		printf("%d %d\n", p.first, p.second);
}