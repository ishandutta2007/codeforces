// Problem: B. Minimal Cost
// Contest: Codeforces - Codeforces Global Round 13
// URL: https://codeforces.com/contest/1491/problem/B
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
		ll n, u, v;
		cin >> n >> u >> v;
		vector<ll> a(n);
		for(auto &i : a) cin >> i;
		ll ans = 1ll<<32;
		for(int i = 1; i < n; i++) if(abs(a[i]-a[i-1])>1) ans = 0;
		for(int i = 1; i < n; i++) {
			if(abs(a[i-1]-a[i]) == 1) {
				ans = min(ans, u);
				ans = min(ans, v);
			} else if(a[i-1] = a[i]) ans = min(ans, v+min(u,v));
		}
		cout << ans << '\n';
	});
	
}