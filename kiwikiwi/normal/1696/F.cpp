#include <bits/stdc++.h>
using namespace std;
 
using i64 = long long;
#define maxN 110

int n;
bool vis[maxN];
char dis[maxN][maxN][maxN];
int g[maxN][maxN];
vector<array<int, 2>> e;

bool checksm(int u, int v, int k) {
	if (u == v) return true;
	if (u > v) swap(u, v);
	return dis[u][v][k] == '1';
}
void dfs(int u ,int adj) {
	vis[u] = 1;
	for (int v = 1; v <= n; v++) {
		if (!vis[v] && checksm(adj, v, u)) {
			e.push_back({v, u});
			dfs(v, u);
		}
	}
}
bool check(vector<array<int, 2>> e) {
	/*for (auto [u, v] : e) {
		printf("check %d %d\n",u, v);
	}*/
	if (e.size() != n - 1) return false;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			g[i][j] = (i == j) ? 0 : n + 1;
	for (auto [u, v] : e) {
		g[u][v] = g[v][u] = 1;
	}
	for (int k = 1; k <= n; k++) 
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				if ((g[i][k] == g[j][k]) != (dis[i][j][k] == '1'))
					return false;

	return true;
}

void solve() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
		for (int j = i + 1; j <= n; j++)
			scanf("%s", dis[i][j] + 1);
	for (int i = 2; i <= n; i++) {
		memset(vis, 0, sizeof (vis));
		e.clear();
		dfs(1, i);
		if (check(e)) {
			puts("Yes");
			for (auto [u, v] : e) {
				printf("%d %d\n", u, v);
			}
			return;
		}
	}
	puts("No");
}
int main() {
	int tc;
	scanf("%d", &tc);
	for (int T = 0 ; T < tc; T++) {
		solve();
	}
}