// Problem: D. Treelabeling
// Contest: Codeforces - Codeforces Round #754 (Div. 2)
// URL: https://codeforces.com/contest/1605/problem/D
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
int n;
vector<vector<int>> g;
vector<int> c, p[2];
void dfs(int v, int pr) {
	p[c[v]].push_back(v);
	for(auto i : g[v]) if(i != pr) {
		c[i] = c[v]^1;
		dfs(i, v);
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	multitest([&](){
		cin >> n;
		g = vector<vector<int>>(n+1);
		for(int f, t, i = 1; i < n; i++) {
			cin >> f >> t;
			g[f].push_back(t);
			g[t].push_back(f);
		}
		p[0] = p[1] = {};
		c = vector<int>(n+1, 0);
		dfs(1, 0);
		vector<int> ans(n+1);
		while(n) {
			int p2 = 1;
			while(p2*2 <= n) p2*=2;
			int f = p[1].size() >= p[0].size();
			for(int i = p2; i <= n; i++) {
				ans[p[f].back()] = i;
				p[f].pop_back();
			}		
			n = p2-1;
		}
		for(int i = 1; i < ans.size(); i++) cout << ans[i] << " "; cout << endl;
	});
	
}