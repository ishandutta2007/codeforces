#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()

const int N = 1000005;
int n, sz, fa[N][20], dep[N], ad[N], an;
vi g[N];

void dfs(int u, int p, int d) {
	fa[u][0] = p; dep[u] = d;
	for (int i = 1; i < 20; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int i = 0; i < sz(g[u]); i++)
		dfs(g[u][i], u, d + 1);
}

int lca(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	for (int i = 0; i < 20; i++)
		if ((dep[u] - dep[v])>>i&1) u = fa[u][i];
	if (u == v) return u;
	for (int i = 19; i >= 0; i--) {
		if (fa[u][i] == fa[v][i]) continue;
		u = fa[u][i], v = fa[v][i];
	}
	return fa[u][0];
}

int cal(int u, int v) {
	return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}

pii ans;

int meg(int x) {
	int u = ans.fi, v = ans.se;
	int Max = cal(u, v);
	int a = cal(x, u), b = cal(x, v);
	if (Max < a) {
		Max = a;
		ans = mp(x, u);
	}
	if (Max < b) {
		Max = b;
		ans = mp(x, v);
	}
	return Max;
}

int main() {
	scanf("%d", &n);
	for (int i = 2; i <= 4; i++) g[1].pb(i);
	sz = 4;
	int v;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &v);
		g[v].pb(++sz); ad[++an] = sz;
		g[v].pb(++sz); ad[++an] = sz;
	}
	dfs(1, 1, 0);
	ans = mp(2, 4);
	for (int i = 1; i <= an; i += 2) {
		meg(ad[i]);
		printf("%d\n", meg(ad[i + 1]));
	}
	return 0;
}