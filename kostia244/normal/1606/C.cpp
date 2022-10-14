// Problem: C. Banknotes
// Contest: Codeforces - Educational Codeforces Round 116 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1606/problem/C
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
		ll n, k;
		cin >> n >> k;k++;
		vector<ll> pw(19);
		pw[0] = 1;
		for(int i = 1; i < 19; i++) pw[i] = pw[i-1]*10ll;
		vector<int> a(n);
		for(auto &i : a) cin >> i;
		a.push_back(18);
		ll ans = 0;
		for(int i = 0; k; i++) {
			ll t = min(k, pw[a[i+1]-a[i]]-1);
			k -= t;
			ans += pw[a[i]]*t;
		}
		cout << ans << '\n';
	});
	
}