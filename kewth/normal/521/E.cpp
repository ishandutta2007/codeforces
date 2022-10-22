#if 0
date


 dfs 
#endif
#include <cstdio>
#include <algorithm>
#include <vector>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	inline operator char () { char x[3]; return scanf("%s", x), *x; }
} read;

const int maxn = 200005;
std::vector<int> G[maxn];
bool vis[maxn], ins[maxn];
int fa[maxn], deep[maxn];
int cx[maxn], cy[maxn];

int lca(int x, int y) {
	while(deep[x] > deep[y]) x = fa[x];
	while(deep[y] > deep[x]) y = fa[y];
	while(x != y) x = fa[x], y = fa[y];
	return x;
}

int tmp[maxn], tp;
void print() {
	printf("%d", tp);
	for(int i = 1; i <= tp; i ++)
		printf(" %d", tmp[i]);
	puts("");
	tp = 0;
}

void add_path(int x, int y) {
	while(x != y) {
		tmp[++ tp] = x;
		x = fa[x];
	}
	tmp[++ tp] = y;
}

void get(int a, int b, int c, int d) {
	if(deep[b] > deep[d]) {
		std::swap(a, c);
		std::swap(b, d);
	}
	int e = lca(a, c);

	puts("YES");

	add_path(e, d);
	std::reverse(tmp + 1, tmp + tp + 1);
	print();

	add_path(d, b);
	add_path(a, e);
	print();

	tmp[++ tp] = d;
	add_path(c, e);
	print();

	exit(0);
}

void dfs(int u) {
	deep[u] = deep[fa[u]] + 1;
	vis[u] = ins[u] = 1;
	for(int v : G[u])
		if(v != fa[u]) {
			if(!vis[v]) {
				fa[v] = u;
				// debug("%d -> %d\n", u, v);
				dfs(v);
			}
			else if(ins[v]) {
				// debug("cover %d %d\n", u, v);
				for(int x = u; x != v; x = fa[x])
					if(cx[x] and cy[x])
						get(cx[x], cy[x], u, v);
					else {
						cx[x] = u;
						cy[x] = v;
					}
			} 
		}
	ins[u] = 0;
}

int main() {
	int n = read, m = read;
	for(int i = 1; i <= m; i ++) {
		int u = read, v = read;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i = 1; i <= n; i ++)
		if(!vis[i])
			dfs(i);
	puts("NO");
}