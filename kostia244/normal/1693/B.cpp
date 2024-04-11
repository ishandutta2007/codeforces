// Problem: B. Fake Plastic Trees
// Contest: Codeforces - Codeforces Round #800 (Div. 1)
// URL: https://codeforces.com/contest/1693/problem/B
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
array<ll, 2> dfs(int v) {
	ll myVal = 0, myOps = 0;
	for(auto &i : g[v]) {
		auto [val, ops] = dfs(i);
		myOps += ops;
		myVal += val;
	}
	if(myVal < l[v]) myVal = r[v], myOps++;
	myVal = min(myVal, r[v]);
	return array<ll, 2>{myVal, myOps};
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	multitest([&](){
		cin >> n;
		g = vector<vector<int>>(n+1);
		l = r = vector<ll>(n+1);
		for(int t, i = 2; i <= n; i++) {
			cin >> t;
			g[t].push_back(i);
		}
		for(int i = 1; i <= n; i++) cin >> l[i] >> r[i];
		cout << dfs(1)[1] << '\n';
	});
	
}