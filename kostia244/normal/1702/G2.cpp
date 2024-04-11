// Problem: G2. Passable Paths (hard version)
// Contest: Codeforces - Codeforces Round #805 (Div. 3)
// URL: https://codeforces.com/contest/1702/problem/G2
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<vector<int>> g(n);
	for(int f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		f--, t--;
		g[f].push_back(t);
		g[t].push_back(f);
	}
	const int L = 18;
	vector<int> tin(n), tout(n), h(n);
	vector<array<int, L>> up(n);
	int timer = 0;
	auto dfs = [&](auto self, int v) -> void {
		for(int i = 1; i < L; i++)
			up[v][i] = up[up[v][i-1]][i-1];
		tin[v] = timer++;
		for(auto i : g[v]) {
			g[i].erase(find(all(g[i]), v));
			h[i] = h[v]+1;
			up[i][0] = v;
			self(self, i);
		}
		tout[v] = timer;
	};
	auto par = [&](int u, int v) {
		return tin[u] <= tin[v] && tin[v] < tout[u];
	};
	auto dist = [&](int u, int v) {
		if(par(u, v))
			return h[v] - h[u];
		swap(u, v);
		if(par(u, v))
			return h[v] - h[u];
		int D = h[u] + h[v];
		for(int z = L; z--;)
			if(!par(up[u][z], v))
				u = up[u][z];
		return D - 2*h[up[u][0]];
	};
	up[0][0] = 0;
	dfs(dfs, 0);
	int q;
	cin >> q;
	for(int k; q--;) {
		cin >> k;
		vector<int> a(k);
		for(auto &i : a) cin >> i, i--;
		int pt = a[0];
		pair<int, int> furthest = {0, a[0]};
		for(int iter = 0; iter < 2; iter++) {
			pt = furthest.second;
			furthest = {0, pt};
			for(auto i : a)
				furthest = max(furthest, pair<int, int>{dist(pt, i), i});
		}
		int ok = 1;
		for(int i = 0; i < k; i++) {
			ok &= dist(pt, furthest.second) ==
				dist(pt, a[i]) + dist(furthest.second, a[i]);
		}
		report(ok);
	}
}