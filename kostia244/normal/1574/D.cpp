// Problem: D.   
// Contest: Codeforces - Educational Codeforces Round 114 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1574/problem/D
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
	//multitest([&](){});
	int n;
	cin >> n;
	vector<vector<int>> a(n);
	for(auto &i : a) {
		int t;cin>>t;
		i.resize(t);
		for(auto &j : i) cin >> j;
		reverse(all(i));
	}
	int m;
	cin >> m;
	array<int, 10> def;def.fill(0);
	set<array<int, 10>> vis;
	set<array<int, 10>> block;
	for(int i = 0; i < m; i++) {
		auto t = def;
		for(int j = 0; j < n; j++)
			cin >> t[j], t[j] = a[j].size()-t[j];
		block.insert(t);
	}
	priority_queue<pair<int, array<int, 10>>> q;
	auto add = [&](array<int, 10> x, int sm) {
		if(vis.insert(x).second) {
			q.push({sm, x});
		}
	};
	add(def, 0);
	while(true) {
		auto [sm, X] = q.top(); q.pop();
		if(!block.count(X)) {
			for(int i = 0; i < n; i++)
				cout << a[i].size()-X[i] << " "; cout << endl;
			return 0;
		}
		for(int i = 0; i < n; i++) if(X[i]+1 < a[i].size()) {
			auto T = X;T[i]++;
			add(T, sm-a[i][X[i]]+a[i][X[i]+1]);
		}
	}
}