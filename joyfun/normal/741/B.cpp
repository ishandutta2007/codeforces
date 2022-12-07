#include<bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, m, W;
int w[N], b[N], fa[N],  ww[N], bb[N];

int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

vector<int> g[N];

int dp[N][N];

int main(){
	scanf("%d%d%d", &n, &m, &W);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
		ww[i] = w[i];
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
		bb[i] = b[i];
		fa[i] = i;
	}
	int u, v;
	while (m--) {
		scanf("%d%d", &u, &v);
		int pu = find(u), pv = find(v);
		if (pu != pv) {
			fa[pu] = pv;
			b[pv] += b[pu];
			w[pv] += w[pu];
		}
	}
	for (int i = 1; i <= n; i++)
		g[find(i)].push_back(i);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= W; j++)
			dp[i][j] = dp[i - 1][j];
		if (g[i].size() == 0) continue;
		for (int j = 0; j <= W; j++) {
			if (j - w[i] >= 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + b[i]);
			for (int k = 0; k < g[i].size(); k++) {
				int u = g[i][k];
				if (j - ww[u] >= 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - ww[u]] + bb[u]);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= W; i++) ans = max(ans, dp[n][i]);
	printf("%d\n", ans);
	return 0;
}