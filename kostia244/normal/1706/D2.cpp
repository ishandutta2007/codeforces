// Problem: D2. Chopping Carrots (Hard Version)
// Contest: Codeforces - Codeforces Round #809 (Div. 2)
// URL: https://codeforces.com/contest/1706/problem/D2
// Memory Limit: 64 MB
// Time Limit: 4000 ms
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
		int n, k;
		cin >> n >> k;
		vector<vector<pair<int, int>>> s(1e5 + 2);
		int minVal = 1e9 + 1, ans = 1e9 + 1;
		for(int t, i = 0; i < n; i++) {
			cin >> t;
			minVal = min(minVal, t);
			s[t].push_back({t, 1});
		}
		[&]() {
		for(int high = 100001; high--;) {while(s[high].size()) {
			ans = min(ans, high - minVal);
			auto [ai, di] = s[high].back();
			s[high].pop_back();
			//ai/floor(ai/di) < *t
			di = min(k, high == 0 ? k : ai/high) + 1;
			int val = ai / di;
			if(di > k) return;
			s[val].push_back({ai, di});
			minVal = min(minVal, val);
			ans = min(ans, high - minVal);
		}
		s[high].shrink_to_fit();
		}
		}();
		cout << ans << '\n';
	});
	
}