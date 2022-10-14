// Problem: C.  
// Contest: Codeforces - Codeforces Round #729 (Div. 2)
// URL: https://codeforces.com/contest/1542/problem/C
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
const int mod = 1e9+7;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	multitest([&](){
		ll cur = 1, ans = 0, n;
		cin >> n;
		for(int i = 1; cur <= n; i++) {
			ll nxt = cur*(i/__gcd(cur, ll(i)));
			ans =( ans +  (n/cur - n/nxt)*i)%mod;
			cur = nxt;
		}
		cout << ans << '\n';
	});
	
}