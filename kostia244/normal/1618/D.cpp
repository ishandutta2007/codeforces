// Problem: D.   
// Contest: Codeforces - Codeforces Round #760 (Div. 3)
// URL: https://codeforces.com/contest/1618/problem/D
// Memory Limit: 512 MB
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
		int n, k;
		cin >> n >> k;
		map<int, int> cnt;
		ll sm = 0;
		for(int t, i = n; i--;)
			cin >> t, cnt[-t]++, sm += t;
		int ans = 1<<30;
		for(int z = 0; z <= k; z++) {
			int cur = sm, tk = 2*k;
			for(auto [v, c] : cnt) {
				cur += min({tk, c, k+z})*v;
				tk -= min({tk, c, k+z});
			}
			ans = min(ans, cur+z);
		}
		cout << ans << '\n';
	});
	
}