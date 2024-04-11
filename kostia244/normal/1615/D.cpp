// Problem: D. (XO)R- 
// Contest: Codeforces - Codeforces Global Round 18
// URL: https://codeforces.com/contest/1615/problem/D
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
int n, m;
vector<int> col;
vector<array<int, 3>> edges;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	multitest([&](){
		cin >> n >> m;
		col = vector<int>(n);
		edges = vector<array<int, 3>>(n-1);
		dsu D(2*n);
		auto add_edge = [&](int u, int v, int t) {
			u*=2,v*=2;
			D.join(u, v^t);
			D.join(u^1, v^1^t);
		};
		for(auto &[u, v, x] : edges) {
			cin >> u >> v >> x;u--,v--;
			if(x != -1) {
				int p = __builtin_popcount(x)&1;
				add_edge(u, v, p);
			}
		}
		for(int u, v, x, i = 0; i < m; i++) {
			cin >> u >> v >> x;u--,v--;
			add_edge(u, v, x);
		}
		int bad = 0;
		vector<int> use(2*n);
		for(int i = 0; i < n; i++) {
			int x = D.find(2*i), y = D.find(2*i+1);
			if(!use[x] && !use[y]) use[x] = 1;
			bad |= D.sameSet(2*i, 2*i+1);
			col[i] = use[y];
		}
		if(bad) cout << "NO\n";
		else {
			cout << "YES\n";
			for(auto [u, v, x] : edges) {
				if(x == -1) x = col[u]^col[v];
				cout << 1+u << " " << 1+v << " " << x << '\n';
			}
		}
	});
	
}