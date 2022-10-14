// Problem: E. Train Hard, Win Easy
// Contest: Codeforces - Codeforces Round #519 by Botan Investments
// URL: https://codeforces.com/contest/1043/problem/E
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

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	int n, m;
	cin >> n >> m;
	vector<array<ll, 2>> pts(n);
	vector<ll> adi, adis;
	ll sy = 0;
	for(auto &[x, y] : pts) {
		cin >> x >> y;
		x*=-1,y*=-1;
		sy += y;
		adi.push_back(x-y);
	}
	sort(all(adi), greater<>());
	adis = {0};
	for(auto i : adi)
		adis.push_back(adis.back()+i);
	vector<vector<int>> g(n+1);
	for(int f, t, i = 0; i < m; i++) {
		cin >> f >> t;f--,t--;
		g[f].push_back(t);
		g[t].push_back(f);
	}
	for(int i = 0; i < n; i++) g[i].push_back(i);
	for(int i = 0; i < n; i++) {
		ll res = pts[i][0]*n + sy, cadi = pts[i][0]-pts[i][1];
		int ps = -1;
		for(int z = 1<<30; z>>=1;)
			if(ps+z < adi.size() && adi[ps+z]-cadi >= 0)
				ps += z;
		ps++;
		res += adis[ps]-cadi*ps;
		for(auto j : g[i]) {
			res -= max(pts[i][0]+pts[j][1], pts[i][1]+pts[j][0]);
		}
		cout << -res << ' ';
	}
}