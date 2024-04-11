// Problem: A. Gamer Hemose
// Contest: Codeforces - Codeforces Round #746 (Div. 2)
// URL: https://codeforces.com/contest/1592/problem/A
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

int main() {
	cin.tie(0)->sync_with_stdio(0);
	multitest([&](){
		ll n, h;
		cin >> n >> h;
		vector<ll> a(n);
		for(auto &i : a) cin >> i;
		sort(all(a), greater<>());
		ll ans = h/(a[0]+a[1]);ans*=2;
		ans += h%(a[0]+a[1]) > 0;
		ans += h%(a[0]+a[1]) > a[0];
		cout << ans << '\n';
	});
	
}