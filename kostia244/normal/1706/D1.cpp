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
		set<array<int, 3>, greater<>> s;
		for(int t, i = 0; i < n; i++) {
			cin >> t;
			s.insert({t, t, 1});
		}
		int ans = s.begin()->at(0) - s.rbegin()->at(0);
		while(true) {
			auto [val, ai, di] = *s.begin();
			s.erase(s.begin());
			if(di > k) break;
			//ai/floor(ai/di) < *t
			di = min(k, val == 0 ? k : ai/val) + 1;
			val = ai / di;
			if(di > k) break;
			s.insert({val, ai, di});
			ans = min(ans, s.begin()->at(0) - s.rbegin()->at(0));
		}
		cout << ans << '\n';
	});
	
}