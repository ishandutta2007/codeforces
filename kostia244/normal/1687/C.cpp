// Problem: C. Sanae and Giant Robot
// Contest: Codeforces - Codeforces Round #796 (Div. 1)
// URL: https://codeforces.com/contest/1687/problem/C
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

int main() {
	cin.tie(0)->sync_with_stdio(0);
	multitest([&](){
		int n, m;
		cin >> n >> m;
		vector<ll> a(n+1);
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		for(int t, i = 1; i <= n; i++) {
			cin >> t;
			a[i] -= t;
			a[i] += a[i - 1];
		}
		vector<vector<int>> g(n+1);
		for(int l, r, i = 0; i < m; i++) {
			cin >> l >> r;
			l--;
			g[l].push_back(r);
			g[r].push_back(l);
		}
		set<int> nonzero;
		for(int i = 0; i <= n; i++)
			nonzero.insert(i);
		queue<array<int, 2>> q;
		auto make_zero = [&](int pos) {
			nonzero.erase(pos);
			a[pos] = 0;
			for(auto i : g[pos]) {
				if(a[i] == 0) {
					q.push({pos, i});
				}
			}
		};
		for(int i = 0; i <= n; i++) 
			if(a[i] == 0) {
				make_zero(i);
			}
		while(!q.empty()) {
			auto [l, r] = q.front();
			q.pop();
			if(l > r) swap(l, r);
			while(true) {
				auto it = nonzero.lower_bound(l);
				if(it != nonzero.end() &&
					*it <= r) {
					make_zero(*it);	
				} else {
					break;
				}
			}
		}
		report(count(all(a), 0) == a.size());
	});
	
}