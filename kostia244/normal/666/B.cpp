// Problem: B. World Tour
// Contest: Codeforces - Codeforces Round #349 (Div. 1)
// URL: https://codeforces.com/contest/666/problem/B
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
const int maxn = 3030;
int n, m, D[maxn][maxn];
vector<int> g[maxn], gt[maxn];
vector<array<int, 2>> bfs(int s) {
	for(int i = 1; i <= n; i++) D[s][i] = 1<<30;
	queue<int> q;
	auto add = [&](int v, int x) {
		if(D[s][v] <= x) return;
		D[s][v] = x;
		q.push(v);
	};
	add(s, 0);
	while(!q.empty()) {
		int v = q.front();
		q.pop();
		for(auto z : g[v])
			add(z, D[s][v]+1);
	}
	vector<array<int, 2>> f;
	for(int i = 1; i <= n; i++) if(D[s][i]<(1<<30))
		f.push_back({D[s][i], i});
	sort(all(f), greater<>());
	while(f.size() > 4) f.pop_back();
	return f;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	cin >> n >> m;
	for(int f, t, i = 1; i <= m; i++) {
		cin >> f >> t;
		g[f].push_back(t);
		gt[t].push_back(f);
	}
	vector<vector<array<int, 2>>> z(n+1), t(n+1);
	for(int i = 1; i <= n; i++) z[i] = bfs(i);
	swap(g, gt);
	for(int i = 1; i <= n; i++) t[i] = bfs(i);
	array<int, 5> ans = {-1, 0, 0, 0, 0};
	for(int u = 1; u <= n; u++) 
		for(int v = 1; v <= n; v++) if(u != v && D[v][u] != 1<<30) {
			//cout << u << " " << v << " " << t[u].size() << " " << z[v].size() << endl;
			for(auto [A, x] : t[u]) if(u != x && v != x) {
				for(auto [B, y] : z[v]) if(u != y && v != y && x != y) {
					ans = max(ans, {D[v][u] + A + B, x, u, v, y});
				}
			}
		}
	cout << ans[1] << " " << ans[2] << " " << ans[3] << " " << ans[4] << '\n';
}