// Problem: D. Useful Edges
// Contest: Codeforces - Codeforces Round #709 (Div. 1, based on Technocup 2021 Final Round)
// URL: https://codeforces.com/contest/1483/problem/D
// Memory Limit: 512 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;

template<typename F>
void multitest(F func) {
	int t;
	cin >> t;
	while(t--) func();
}
void report(int ok) {
	cout << (ok?"YES":"NO") << '\n';
}
const int N = 606;
int n, m, q, g[N][N], dp[N][N], vis[N][N], row[N];
void recalc(int i) {
	row[i] = -1;
	for(int j = 0; j < n; j++) if(g[i][j] && !vis[i][j]) {
		if(row[i] == -1 || dp[i][row[i]] < dp[i][j])
			row[i] = j;
	}
}
void touch(int u, int v, int z) {
	if(vis[u][v]) return;
	dp[u][v] = max(dp[u][v], z);
	if(row[u] == -1 || dp[u][v] > dp[u][row[u]])
		row[u] = v;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	cin >> n >> m;
	for(int u, v, w, i = 0; i < m; i++) {
		cin >> u >> v >> w;u--,v--;
		g[u][v] = g[v][u] = w;
	}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			dp[i][j] = -(1<<30);
	cin >> q;
	for(int u, v, l, i = 0; i < q; i++) {
		cin >> u >> v >> l;u--,v--; 
		dp[u][v] = dp[v][u] = l;
	}
	for(int i = 0; i < n; i++)
		recalc(i);
	while(true) {
		array<int, 3> cur = {-1, -1, -1};
		for(int i = 0; i < n; i++) {
			if(row[i] != -1)
				cur = max(cur, {dp[i][row[i]], i, row[i]});
		}
		if(cur[0] <= 0) break;
		int u = cur[1], v = cur[2];
		for(int w = 0; w < n; w++) {
			if(g[v][w]) {
				touch(u, w, dp[u][v]-g[v][w]);
				touch(w, u, dp[u][v]-g[v][w]);
			}
			if(g[u][w]) {
				touch(w, v, dp[u][v]-g[u][w]);
				touch(v, w, dp[u][v]-g[u][w]);
			}
		}
		vis[u][v] = vis[v][u] = 1;
		recalc(u); recalc(v);
	}
	int ans = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < i; j++) if(g[i][j]) {
			ans += g[i][j] <= dp[i][j];
		}
	cout << ans << '\n';
}