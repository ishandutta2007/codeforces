#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 5;

vector <int> adj[N];
ll f[N];
int a[N], b[N], id[N];
ll ans;
int n, len, cnt;

void dfs1(int u) {
	f[u] = a[u];
	for (int i = 0; i < (int)adj[u].size(); i++) {
		int v = adj[u][i];
		dfs1(v);
		if (f[v] >= 0) f[u] += f[v];
	}
	ans += f[u];
}

void dfs2(int u) {
	for (int i = 0; i < (int)adj[u].size(); i++) {
		int v = adj[u][i];
		if (f[v] >= 0) dfs2(v);
	}
	id[++cnt] = u;
	for (int i = 0; i < (int)adj[u].size(); i++) {
		int v = adj[u][i];
		if (f[v] < 0) dfs2(v);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
		if (~b[i]) adj[b[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		if (b[i] == -1) {
			dfs1(i);
			dfs2(i);
		}
	}
	printf("%lld\n", ans);
	for (int i = 1; i <= n; i++) printf("%d%c", id[i], i == n ? '\n' : ' ');
	return 0;
}