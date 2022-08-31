#include <bits/stdc++.h>
using namespace std;
 
using i64 = long long;
#define maxN 401000

int a[maxN], par[maxN], l[maxN], r[maxN], tot, ps[maxN];
int n, m;
vector<int> adj[maxN];
vector<pair<int, int>> son[maxN];
int findpar(int x) {
	if (par[x] == x) return x;
	else return par[x] = findpar(par[x]);
}

void dfs(int u, int f) {
	l[u] = ++tot;
	for (auto v : adj[u]) {
		if (v == f) continue;
		dfs(v, u);
		son[u].push_back({l[v], v});
	}
	r[u] = tot;
}

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		par[i] = i;
	vector<pair<int, int>> e2;
	for (int i = 1; i <=m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		if (findpar(u) != findpar(v)) {
			par[findpar(u)] = findpar(v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		} else {
			e2.push_back({u, v});
		}
	}
	dfs(1, 0);
	for (auto [u, v]: e2) {
		if (l[u] > l[v]) swap(u, v);
		if (r[v] <= r[u]) {
			ps[l[v]]++;
			ps[r[v] + 1]--;
			auto w = prev(upper_bound(son[u].begin(), son[u].end(),
				make_pair(l[v], 1 << 30))) -> second;
			ps[1]++;
			ps[n + 1]--;
			ps[l[w]]--;
			ps[r[w] + 1]++;
		} else {
			ps[l[u]]++;
			ps[r[u] + 1]--;
			ps[l[v]]++;
			ps[r[v] + 1]--;
		}
	}
	int m = e2.size();
	for (int i = 1; i <= n; i++) ps[i] += ps[i - 1];
	for (int i = 1; i <= n; i++)
		printf("%d", (ps[l[i]] == m));
	puts("");
}

int main() {
	solve();
}