#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
#define fs first
#define sc second
typedef long long ll;
typedef pair<int, int> pii; 
const int N = 1e5 + 10;
struct Edge { int v, w; };
int n, l, sl, w, sz[N], f[N], size, rt;
vector<Edge> G[N];
bool vis[N];
pii a[N];
ll ans;
void findrt(int u, int fa = 0) {
	sz[u] = 1; f[u] = 0;
	for(int i = 0; i < (int) G[u].size(); i ++) {
		int v = G[u][i].v;
		if(vis[v] || v == fa) continue ;
		findrt(v, u); sz[u] += sz[v];
		f[u] = max(f[u], sz[v]);
	}
	f[u] = max(f[u], size - sz[u]);
	if(!rt || f[rt] > f[u]) rt = u;
}
bool cmp(const pii &a, const pii &b) { return a.sc < b.sc; }
void dfs(int u, int d1, int d2, int fa = 0) {
	a[++ sl] = pii(d1, d2);
	for(int i = 0; i < (int) G[u].size(); i ++) {
		int v = G[u][i].v;
		if(vis[v] || v == fa) continue ;
		dfs(v, d1 + 1, d2 + G[u][i].w, u);
	}
}
int bit[N];
void ins(int u, int d) {
	if(u < 0) return ;
	for(u ++; u <= n; u += u & (-u)) bit[u] += d;
}
int qry(int u) {
	int ans = 0; u = min(u, n - 1);
	for(u ++; u >= 1; u &= u - 1) ans += bit[u];
	return ans;
}
void calc(int u, int d1, int d2, int t) {
	sl = 0; dfs(u, d1, d2);
	int p = 0; sort(a + 1, a + sl + 1, cmp);
	for(int i = sl; i >= 1; i --) {
		for(; p < sl && a[p + 1].sc <= w - a[i].sc; p ++) ins(l - a[p + 1].fs, 1);
		ans += t * (qry(n - 1) - qry(a[i].fs - 1));
	}
	for(; p >= 1; p --) ins(l - a[p].fs, -1);
}
void solve(int u) {
	vis[u] = 1; calc(u, 0, 0, 1);
	for(int i = 0; i < (int) G[u].size(); i ++) {
		int v = G[u][i].v;
		if(vis[v]) continue ;
		calc(v, 1, G[u][i].w, -1);
		rt = 0; size = sz[v]; findrt(v); solve(rt);
	}
}
int main() {
	scanf("%d%d%d", &n, &l, &w);
	if(l == n) l = n - 1; 
	for(int f, w, i = 2; i <= n; i ++) {
		scanf("%d%d", &f, &w);
		G[f].push_back((Edge) {i, w});
		G[i].push_back((Edge) {f, w});
	}
	rt = 0; size = n; findrt(1); solve(rt);
	printf("%lld\n", (ans - n) / 2);
	return 0;
}
/*
(d[u] <= l - d[v], de[u] <= w - de[v])
*/