// Problem: D. Keep the Average High
// Contest: Codeforces - Good Bye 2021: 2022 is NEAR
// URL: https://codeforces.com/contest/1616/problem/D
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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
		int n;
		cin >> n;
		vector<ll> a(n);
		for(auto &i : a) cin >> i;
		ll x;cin >> x;
		for(auto &i : a) i -= x;
		int ans = n;
		set<ll> pref;
		ll cur = 0;
		for(int i = 0; i < n; i++) {
			ll nw = cur+a[i];
			if(pref.size() && *pref.rbegin() > nw) {
				cur = 0;
				pref.clear();
				ans--;
				continue;
			}
			pref.insert(cur);
			cur += a[i];
		}
		cout << ans << '\n';
	});
	
}