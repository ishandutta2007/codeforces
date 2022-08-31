#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int maxN = 345678;
int n, w[maxN], u, v, z;
i64 dp[maxN], answer;
vector<pair<int, int> > e[maxN];
void dfs(int u, int par) {
	dp[u] = w[u];
	answer = max(answer, (i64)w[u]);
	for (auto edge : e[u]) {
		int v = edge. first;
		if (v == par) continue;
		dfs(v, u);
		dp[v] -= edge.second;
		answer = max(answer, dp[u] + dp[v]);
		dp[u] = max(dp[u], dp[v] + w[u]);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
	for (int i = 1; i < n; i++) {
		scanf("%d%d%d", &u, &v, &z);
		e[u].push_back(make_pair(v, z));
		e[v].push_back(make_pair(u, z));
	}
	answer = 0;
	dfs(1, 0);
	printf("%lld\n", answer);
}