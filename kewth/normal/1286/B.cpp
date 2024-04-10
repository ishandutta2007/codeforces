#if 0
date +%Y.%m.%d


#endif
#include <cstdio>
#include <algorithm>
#include <vector>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
typedef size_t si;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator ()(a...); }
} read;

const int maxn = 2020;
std::vector<int> G[maxn], V[maxn];
int rk[maxn], size[maxn];
int a[maxn];

void dfs1(int u) {
	size[u] = 1;
	for(int v : G[u]) {
		dfs1(v);
		size[u] += size[v];
	}
}

void dfs2(int u) {
	si r = si(rk[u]);
	if(r >= V[u].size()) puts("NO"), exit(0);
	a[u] = V[u][r];
	si now = 0;
	for(int v : G[u]) {
		for(int i = 1; i <= size[v]; i ++) {
			if(now == r) ++ now;
			V[v].push_back(V[u][now ++]);
		}
		dfs2(v);
	}
}

int main() {
	int n = read, rt = 1;
	for(int i = 1; i <= n; i ++) {
		int f = read;
		read(rk[i]);
		if(f) G[f].push_back(i);
		else rt = i;
	}

	dfs1(rt);
	for(int i = 1; i <= n; i ++)
		V[rt].push_back(i);
	dfs2(rt);

	puts("YES");
	for(int i = 1; i <= n; i ++)
		printf("%d ", a[i]);
	puts("");
}