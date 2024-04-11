// Problem: B. Inflation
// Contest: Codeforces - Educational Codeforces Round 103 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1476/problem/B
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
		cin >> n >> k;
		vector<ll> a(n);
		for(auto &i : a) cin >> i;
		auto good = [&](ll x) {
			a[0] += x;
			ll good = 1, sm = 0;
			for(auto i : a) {
				if(sm) good &= 100*i <= k*sm;
				sm += i;
			}
			a[0] -= x;
			return good;
		};
		ll ans = -1;
		for(ll a = 1ll<<50; a>>=1;)
			ans += a*!good(ans+a);
		cout << ++ans << '\n';
	});
	
}