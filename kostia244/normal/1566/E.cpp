// Problem: E.  
// Contest: Codeforces - Codeforces Global Round 16
// URL: https://codeforces.com/contest/1566/problem/E
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
vector<vector<int>> g;
int ans;
int dfs(int v, int p) {
	int lev = 0;
	for(auto i : g[v]) if(i != p) {
		int t = dfs(i, v);
		if(t != -1)
			lev++;
	}
	if(lev) {
		ans += lev;
		ans -= v != 1;
		return -1;
	}
	if(v == 1)
		ans++;
	return 1;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	multitest([&](){
		int n;
		cin >> n;
		g.assign(n+1, {});
		for(int f, t, i = 1; i < n; i++) {
			cin >> f >> t;
			g[f].push_back(t);
			g[t].push_back(f);
		}
		ans = 0;
		dfs(1, 1);
		cout << ans << '\n';
	});
	
}