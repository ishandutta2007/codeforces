#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct edge {
	int a, b, ind;
	ll c;
};
bool comp(const edge&a, const edge&b) { return a.c < b.c; }
int p[300001];
int f(int x) { return x == p[x] ? x : p[x] = f(p[x]); }
vector<int> g[300001], d[300001];
edge e[300001];
ll ans[300001];
int up[300001][20], uv[300001][20], dep[300001];
int ma;
void dfs(int x, int p) {
	for (int i = 0; i < g[x].size();i++) {
		int y = g[x][i],c=d[x][i];
		if (y == p)continue;
		dep[y] = dep[x] + 1;
		up[y][0] = x;
		uv[y][0] = c;
		dfs(y, x);
	}
}
int par(int x, int a) {
	for (int i = 0; i<=17; i++)if ((a>>i) & 1)ma = max(ma, uv[x][i]), x = up[x][i];
	return x;
}
int main()
{
	int n, m,i,j;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++)p[i] = i;
	for (i = 0; i < m; i++)scanf("%d%d%lld", &e[i].a, &e[i].b, &e[i].c),e[i].ind = i;
	sort(e, e + m,comp);
	ll mst = 0;
	for (i = 0; i < m; i++)if (f(e[i].a) != f(e[i].b))d[e[i].a].push_back(e[i].c),d[e[i].b].push_back(e[i].c),p[f(e[i].a)] = e[i].b, mst += e[i].c, g[e[i].a].push_back(e[i].b), g[e[i].b].push_back(e[i].a);
	dfs(1, 0);
	up[1][0] = 1;
	for (i = 1; i < 18; i++)for (j = 1; j <= n; j++)up[j][i] = up[up[j][i - 1]][i - 1], uv[j][i] = max(uv[j][i - 1], uv[up[j][i - 1]][i - 1]);
	for (i = 0; i < m; i++) {
		int a = e[i].a, b = e[i].b;
		ma = 0;
		if (dep[a] > dep[b])a = par(a, dep[a] - dep[b]);
		if (dep[a] < dep[b])b = par(b, dep[b] - dep[a]);
		for (j = 17; j >= 0; j--) {
			if (up[a][j] != up[b][j])ma = max(ma, uv[a][j]), ma = max(ma, uv[b][j]),a=up[a][j],b=up[b][j];
		}
		if (a != b)ma = max(ma, max(uv[a][0], uv[b][0]));
		ans[e[i].ind]=mst - ma + e[i].c;
	}
	for (i = 0; i < m; i++)printf("%lld\n", ans[i]);
}