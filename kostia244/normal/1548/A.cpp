// Problem: A. Web of Lies
// Contest: Codeforces - Codeforces Round #736 (Div. 1)
// URL: https://codeforces.com/contest/1548/problem/A
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
	
		int n, m, q;
		cin >> n >> m;
		int ans = n;
		vector<int> bad(n+1);
		auto add_edge = [&](int u, int v) {
			bad[u > v ? v : u]++;
			if(bad[u > v ? v : u] == 1)
				ans--;
		};
		auto rem_edge = [&](int u, int v) {
			bad[u > v ? v : u]--;
			if(bad[u > v ? v : u] == 0)
				ans++;
		};
		for(int f, t, i = 0; i < m; i++) {
			cin >> f >> t;
			add_edge(f, t);
		}
		cin >> q;
		for(int t, x, y; q--;) {
			cin >> t;
			if(t == 3) cout << ans << '\n';
			else {
				cin >> x >> y;
				if(t == 1)
					add_edge(x, y);
				else
					rem_edge(x, y);
			}
		}
	
}