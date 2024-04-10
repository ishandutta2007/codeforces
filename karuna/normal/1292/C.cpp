#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N;
ll dp[3030][3030], dir[3030][3030], sub[3030][3030];
vector<int> E[3030];

int dfs(int st, int prv, int cur) {
	dir[cur][st] = prv;
	for (int nxt : E[cur]) {
		if (prv == nxt) continue;
		sub[st][cur] += dfs(st, cur, nxt);
	}
	return ++sub[st][cur];
}
ll solve(int u, int v) {
	if (u == v) return 0;
	if (dp[u][v] != 0) return dp[u][v];
	if (dir[u][v] == v) {
		return dp[u][v] = (ll)sub[u][v] * sub[v][u];
	}
	return dp[u][v] = max(solve(dir[u][v], v), solve(u, dir[v][u])) + (ll)sub[u][v] * sub[v][u];
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> N;
	for (int i=1; i<N; i++) {
		int x, y; cin >> x >> y;
		E[x].push_back(y); E[y].push_back(x);
	}
	for (int i=1; i<=N; i++) dfs(i, -1, i);

	ll ans = 0;
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=N; j++) ans = max(ans, solve(i, j));
	}
	cout << ans;
}