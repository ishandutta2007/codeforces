// Problem: E.  
// Contest: Codeforces - Codeforces Global Round 19
// URL: https://codeforces.com/contest/1637/problem/E
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
	multitest([&](){
		int n, m;
		cin >> n >> m;
		ll ans = -(1ll<<60);
		vector<int> a(n), c;
		for(int t, i = 0; i < n; i++) {
			cin >> a[i];
		}
		c = a;
		sort(all(c));
		c.erase(unique(all(c)), c.end());
		vector<int> cnt(c.size());
		for(auto &i : a) {
			i = lower_bound(all(c), i)-c.begin();
			cnt[i]++;
		}
		vector<vector<int>> bad(c.size()), cv(n+1);
		for(int u, v, i = 0; i < m; i++) {
			cin >> u >> v;
			u = lower_bound(all(c), u)-c.begin();
			v = lower_bound(all(c), v)-c.begin();
			bad[u].push_back(v);
			bad[v].push_back(u);
		}
		for(int i = 0; i < c.size(); i++)
			cv[cnt[i]].push_back(i);
		for(int i = 0; i <= n; i++) {
			sort(all(cv[i]), [&](int x, int y) {
				return c[x] > c[y];
			});
		}
		auto check = cnt;
		sort(all(check)); check.erase(unique(all(check)), check.end());
	
		vector<int> dead(c.size(), 0);
		for(int x = 0; x < c.size(); x++) {
			for(auto i : bad[x]) dead[i] = 1;
			dead[x] = 1;
			
			for(auto cn : check) {
				int y = 0;
				while(y < cv[cn].size() && dead[cv[cn][y]])
					y++;
				if(y < cv[cn].size()) {
					y = cv[cn][y];
					ans = max(ans, (cnt[x]+cnt[y])*1ll*(c[x]+c[y]));
				}
			}
			
			dead[x] = 0;
			for(auto i : bad[x]) dead[i] = 0;
		}
		cout << ans << '\n';
	});
	
}