// Problem: E. Avoid Rainbow Cycles
// Contest: Codeforces - Grakn Forces 2020
// URL: https://codeforces.com/contest/1408/problem/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
struct dsu {
	vector<int> e;
	dsu(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	int m, n;
	cin >> m >> n;
	vector<int> a(m), b(n);
	vector<array<int, 3>> edges;
	for(auto &i : a) cin >> i;
	for(auto &i : b) cin >> i;
	ll cst = 0;
	for(int k, t, i = 0; i < m; i++) {
		cin >> k;
		while(k--) {
			cin >> t;t--;
			cst += a[i]+b[t];
			edges.push_back({a[i]+b[t], n+i, t});
		}
	}
	sort(all(edges), greater<>());
	dsu d(n+m);
	for(auto [w, x, y] : edges) {
		cst -= w*d.join(x,y);
	}
	cout << cst << '\n';
}