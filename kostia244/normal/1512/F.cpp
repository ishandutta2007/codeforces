// Problem: F. Education
// Contest: Codeforces - Codeforces Round #713 (Div. 3)
// URL: https://codeforces.com/contest/1512/problem/F
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
		ll n, s;
		cin >> n >> s;
		vector<ll> a(n), b(n-1);
		for(auto &i : a) cin >> i;
		for(auto &i : b) cin >> i;
		int i = 0;
		ll cur = 0, D = 0, ans = 1ll<<60;
		while(true) {
			ans = min(ans, max(0ll, s-cur+a[i]-1)/a[i] + D);
			if(i>=b.size()) break;
			ll t = max(0ll, b[i]-cur+a[i]-1)/a[i];
			cur += t*a[i];
			cur -= b[i];
			D += t+1;
			i++;
		}
		cout << ans << '\n';
	});
	
}