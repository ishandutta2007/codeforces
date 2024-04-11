// Problem: A. The Enchanted Forest
// Contest: Codeforces - Codeforces Round #796 (Div. 1)
// URL: https://codeforces.com/contest/1687/problem/A
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
		int n, k;
		cin >> n >> k;
		vector<ll> a(n);
		for(auto &i : a) 
			cin >> i;
		for(int i = 1; i < n; i++) {
			a[i] += a[i - 1];
		}
		for(int i = n - 1; i - k >= 0; i--)
			a[i] -= a[i-k];
		ll ans = 0;
		for(int i = 0; i < n; i++) {
			ll t = min(i+1, k);
			t = a[i] + t * (t - 1) / 2 + (k - t) * t;
			ans = max(ans, t);	
		}
		cout << ans << '\n';	
	});
	
}