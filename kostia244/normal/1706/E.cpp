// Problem: E. Qpwoeirut and Vertices
// Contest: Codeforces - Codeforces Round #809 (Div. 2)
// URL: https://codeforces.com/contest/1706/problem/E
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
		if (a < b) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};
int main() {
	cin.tie(0)->sync_with_stdio(0);
	multitest([&](){
		int n, m, q;
		cin >> n >> m >> q;
		vector<array<int, 2>> e(m);
		for(auto &[u, v] : e) cin >> u >> v, u--, v--;
		vector<array<int, 2>> Q(q);
		vector<int> ans(q, -1);
		for(auto &[l, r] : Q) cin >> l >> r, l--, r--;
		for(int z = 1<<20; z>>=1;) {
			vector<vector<int>> check(m + 1);
			for(int i = 0; i < q; i++) {
				if(ans[i] + z <= m) {
					check[ans[i] + z].push_back(i);
				}
			}
			dsu d(n);
			set<int> alive;
			for(int i = 0; i < n; i++)
				alive.insert(i);
			auto Check = [&](int l, int r) {
				while(alive.size()) {
					auto it = alive.upper_bound(l);
					if(it == alive.end() || !d.sameSet(l, *it))
						break;
					alive.erase(it);
				}
				auto it = alive.upper_bound(l);
				return it == alive.end() || *it > r;
			};
			for(int i = 0; i <= m; i++) {
				for(auto x : check[i]) {
					if(!Check(Q[x][0], Q[x][1]))
						ans[x] += z;
				}
				if(i < m) d.join(e[i][0], e[i][1]);
			}
		}
		for(auto i : ans) cout << 1+i << ' ';cout << '\n';
	});
	
}