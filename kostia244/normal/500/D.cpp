// Problem: D. New Year Santa Network
// Contest: Codeforces - Good Bye 2014
// URL: https://codeforces.com/contest/500/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
const int maxn = 1<<17;
int n, dep[maxn], sz[maxn];
vector<int> g[maxn];
vector<array<int, 3>> edges;
void dfs(int v, int p) {
	sz[v] = 1;
	for(auto i : g[v]) if(i != p) {
		dep[i] = dep[v]+1;
		dfs(i, v);
		sz[v] += sz[i];
	}
}
using ld = long double;
ld ans = 0;
int N;
ll total;
ld contrib(int id) {
	ll bad = total, x = sz[edges[id][1]];
	bad -= x*(x-1)*(x-2);
	x = N - x; 
	bad -= x*(x-1)*(x-2);
	return (ld(bad)*2*edges[id][2])/ld(total);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	cin >> n;N=n;
	total = n*1ll*(n-1)*(n-2);
	for(int f, t, w, i = 1; i < n; i++) {
		cin >> f >> t >> w;
		g[f].push_back(t);
		g[t].push_back(f);
		edges.push_back({f, t, w});
	}
	dfs(1, -69);
	for(auto &[f, t, w] : edges) {
		if(dep[f] > dep[t]) swap(f, t);
	}
	for(int i = 0; i+1 < n; i++)
		ans += contrib(i);
	cin >> n;
	cout << fixed << setprecision(7);
	for(int x, y; n--;) {
		cin >> x >> y;
		ans -= contrib(x-1);
		edges[x-1][2] = y;
		ans += contrib(x-1);
		cout << ans << '\n';
	}
}