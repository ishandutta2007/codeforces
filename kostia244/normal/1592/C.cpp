// Problem: C. Bakry and Partitioning
// Contest: Codeforces - Codeforces Round #746 (Div. 2)
// URL: https://codeforces.com/contest/1592/problem/C
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
vector<int> a;
array<int, 2> dfs(int v, int p, int xr) {
	int ok = 0, cnt = 0, sub = a[v-1];
	for(auto i : g[v])
	if(i != p) {
		auto [cok, csub] = dfs(i, v, xr);
		sub ^= csub;
		if(ok == 1 && cok) ok = 2;	
		ok = max(ok, cok);
	}
	if(p) {
	if(ok == 1 && sub==0) ok = 2;
	if(ok == 0 && sub==xr)ok = 1;
	}
	return {ok, sub};
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	multitest([&](){
		int n, k;
		cin >> n >> k;
		g = vector<vector<int>>(n+1);
		a = vector<int>(n);
		int xr = 0;
		for(auto &i : a) cin >> i, xr ^= i;
		for(int f, t, i = 1; i < n; i++) {
			cin >> f >> t;
			g[f].push_back(t);
			g[t].push_back(f);
		}
		if(xr == 0) {
			cout << "YES\n";
		} else {
			auto [ok, sbn] = dfs(1, 0, xr);
			report(k>2&&ok>1);
		}
	});
	
}