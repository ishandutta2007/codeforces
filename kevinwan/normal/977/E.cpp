#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> g[200001];
bool vis[200001];
bool dfs(int x) {
	vis[x] = 1;
	bool ans = 1;
	for (auto y : g[x]) {
		if (vis[y])continue;
		ans &= dfs(y);
	}
	return ans & (g[x].size() == 2);
}
int main() {
	int n, m,a,b,i;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int ans = 0;
	for (i = 1; i <= n; i++)if (!vis[i])ans += dfs(i);
	printf("%d", ans);
}