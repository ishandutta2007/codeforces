// Problem: E. Paired Payment
// Contest: Codeforces - Codeforces Round #703 (Div. 2)
// URL: https://codeforces.com/contest/1486/problem/E
// Memory Limit: 512 MB
// Time Limit: 4000 ms
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
const int maxn = 1e5 + 1;
int n, m;
ll dist[maxn][51];
vector<array<int, 2>> g[maxn];
priority_queue<array<ll, 3>> pq;
void enq(int v, int si, ll di) {
	if(dist[v][si] >= 0 && dist[v][si] <= di) return;
	dist[v][si] = di;
	pq.push({-di, v, si});
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	cin >> n >> m;
	for(int f, t, w, i = 0; i < m; i++) {
		cin >> f >> t >> w;
		g[f].push_back({t, w});
		g[t].push_back({f, w});
	}
	memset(dist, -1, sizeof dist);
	enq(1, 0, 0);
	while(!pq.empty()) {
		auto [di, v, sl] = pq.top();
		pq.pop(); di *= -1;
		if(di > dist[v][sl]) continue;
		for(auto [to, w] : g[v]) {
			if(sl == 0) {
				enq(to, w, w*w + di);
			} else {
				enq(to, 0, w*w + sl*w*2 + di);	
			}
		}
	}
	for(int i = 1; i <= n; i++) cout << dist[i][0] << " "; cout << endl;
}