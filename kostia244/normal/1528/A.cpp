// Problem: A. Parsa's Humongous Tree
// Contest: Codeforces - Codeforces Round #722 (Div. 1)
// URL: https://codeforces.com/contest/1528/problem/A
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
int n;
vector<vector<int>> g;
vector<ll> l, r;
array<ll, 2> dfs(int v, int p) {
	array<ll, 2> res {0, 0};
	for(int i : g[v]) if(i^p) {
		auto ch = dfs(i, v);
		res[0] += max(abs(l[v]-l[i])+ch[0], abs(l[v]-r[i])+ch[1]);
		res[1] += max(abs(r[v]-l[i])+ch[0], abs(r[v]-r[i])+ch[1]);
	}
	return res;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	multitest([&](){
		cin >> n;
		r = l = vector<ll>(n);
		g = vector<vector<int>>(n);
		for(int i = 0; i < n; i++)
			cin >> l[i] >> r[i];
		for(int f, t, i = 1; i < n; i++) {
			cin >> f >> t;f--,t--;
			g[f].push_back(t);
			g[t].push_back(f);
		}
		auto t = dfs(0, 0);
		cout << max(t[0], t[1]) << '\n';
	});
	
}