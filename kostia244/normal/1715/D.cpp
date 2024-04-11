// Problem: D. 2+ 
// Contest: Codeforces - Codeforces Round #816 (Div. 2)
// URL: https://codeforces.com/contest/1715/problem/D
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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
	//multitest([&](){});
	int n, m;
	cin >> n >> m;
	vector<vector<array<uint32_t, 2>>> g(n);
	vector<uint32_t> a(n), can(n, -1);
	for(int f, t, w, i = 0; i < m; i++) {
		cin >> f >> t >> w;
		if(--f > --t) swap(f, t);
		can[f] &= w;
		can[t] &= w;
		g[f].push_back({t, w});
	}
	for(int i = 0; i < n; i++) {
		for(auto [j, w] : g[i]) {
			uint32_t left = w & ~(a[i] | a[j]);
			a[i] |= left & (j == i ? -1u : ~can[j]);
		}
		for(auto [j, w] : g[i]) {
			uint32_t left = w & ~(a[i] | a[j]);
			a[j] |= left & can[j];
		}
	}
	for(auto i : a) cout << i << " ";
}