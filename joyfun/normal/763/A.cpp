#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second

const int N = 1e5+5;
int n, c[N], ans = -1;
vi g[N];
int dp[N];

void dfs(int u, int p) {
	dp[u] = c[u];
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (v == p) continue;
		dfs(v, u);
		if (dp[v] != dp[u]) dp[u] = -1;
	}
}

void dfs2(int u, int p, int nc) {
	int f = 1;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (v == p) continue;
		if (dp[v] == -1) f = 0;
	}
	if (f) ans = u;
	if (nc != c[u]) return;
	int fff = 1;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (v == p) continue;
		if (dp[v] != nc) {
			int ff = 1;
			for (int j = 0; j < g[u].size(); j++) {
				int vv = g[u][j];
				if (vv == p || vv == v) continue;
				if (dp[vv] != nc) ff = 0;
			}
			if (ff) dfs2(v, u, nc);
			fff = 0;
			break;
		}
	}
	if (fff) {
		for (int i = 0; i < g[u].size(); i++) {
			int v = g[u][i];
			if (v == p) continue;
			dfs2(v, u, nc);
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
	dfs(1, 1);
	dfs2(1, 1, c[1]);
	if (ans != -1) printf("YES\n%d\n", ans);
	else printf("NO\n");
	return 0;
}