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
int a[maxn], b[maxn];
std::vector<int> G[maxn], iG[maxn];
int stack[maxn], sp;
int deg[maxn];
int tops[maxn], tp;
char ans[maxn];
bool vis[maxn], ivis[maxn];

void dfs (int u) {
	if (vis[u]) return;
	vis[u] = 1;
	for (int v : G[u])
		dfs(v);
}

void idfs (int u) {
	if (ivis[u]) return;
	ivis[u] = 1;
	for (int v : iG[u])
		idfs(v);
}

int main () {
	int n = read, m = read;
	for (int i = 1; i <= m; i ++) {
		int u = read, v = read;
		G[u].push_back(v);
		iG[v].push_back(u);
		++ deg[v];
	}

	for (int u = 1; u <= n; u ++)
		if (!deg[u])
			stack[++ sp] = u;

	while (sp) {
		int u = stack[sp --];
		tops[++ tp] = u;
		for (int v : G[u])
			if (-- deg[v] == 0)
				stack[++ sp] = v;
	}

	if (tp != n)
		return puts("-1"), 0;

	int tot = 0;
	for (int u = 1; u <= n; u ++) {
		if (!vis[u] and !ivis[u])
			ans[u] = 'A', ++ tot;
		else
			ans[u] = 'E';
		dfs(u);
		idfs(u);
	}

	printf("%d\n", tot);
	puts(ans + 1);
}