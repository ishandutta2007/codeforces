#include <bits/stdc++.h>
using namespace std;
 
using i64 = long long;
#define maxN (1 << 18) + 10

int n, val[maxN], s[maxN], dep[maxN];
vector<int> adj[maxN];

void dfs(int u,int par) {
	dep[u] = dep[par] + 1;
	if (dep[u] == 1) s[u] = 0;
	else if (dep[u] % 2 == 1) s[u] = 1;
	else s[u] = -1;
	val[u] = s[u];
	for (auto v : adj[u]) if (v != par) {
		dfs(v, u);
		val[u] -= s[v];
	}
}
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		adj[i].clear();
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++) printf("%d ",val[i]);
	puts("");
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 1; i <= tc; i++) {
		solve();
	}
}