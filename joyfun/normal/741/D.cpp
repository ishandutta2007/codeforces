#include <bits/stdc++.h>
using namespace std;

const int N = 500005;
const int INF = 0x3f3f3f3f;

int n;
typedef pair<int, int> pii;
#define mp(a,b) make_pair(a,b)
#define fi first
#define se second

vector<int> g[N];
int sz[N], dep[N], son[N], fa[N], mask[N];
char c;
int ans[N];
vector<int> V[N];
int M[1<<22];

void dfs(int u, int f) {
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (v == son[u]) continue;
		dfs(v, 0);
	}
	if (son[u]) {
		dfs(son[u], 1);
		swap(V[u], V[son[u]]);
	} else V[u] = vector<int>();

	for (int i = 0; i < 22; i++)
		ans[u] = max(ans[u], M[mask[u]^(1<<i)] - dep[u]);
	ans[u] = max(ans[u], M[mask[u]] - dep[u]);
	M[mask[u]] = max(M[mask[u]], dep[u]);
	V[u].push_back(u);

	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (v == son[u]) continue;
		for (int j = 0; j < V[v].size(); j++) {
			int w = V[v][j];
			for (int k = 0; k < 22; k++)
				ans[u] = max(ans[u], M[mask[w]^(1<<k)] + dep[w] - 2 * dep[u]);
			ans[u] = max(ans[u], M[mask[w]] + dep[w] - 2 * dep[u]);
		}
		for (int j = 0; j < V[v].size(); j++) {
			int w = V[v][j];
			M[mask[w]] = max(M[mask[w]], dep[w]);
			V[u].push_back(w);
		}
	}
	if (!f) for (int i = 0; i < V[u].size(); i++) M[mask[V[u][i]]] = -INF;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < (1<<22); i++) M[i] = -INF;
	for (int i = 2; i <= n; i++) {
		scanf("%d %c", &fa[i], &c);
		g[fa[i]].push_back(i);
		dep[i] = dep[fa[i]] + 1;
		int cc = c - 'a';
		mask[i] = mask[fa[i]]^(1<<cc);
	}
	for (int i = n; i >= 1; i--) {
		sz[fa[i]] += ++sz[i];
		if (!son[fa[i]] || sz[son[fa[i]]] < sz[i]) son[fa[i]] = i;
	}
	dfs(1, 0);
	for (int i = n; i >= 1; i--) ans[fa[i]] = max(ans[fa[i]], ans[i]);
	for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
	return 0;
}