// Problem: C. Delete Two Elements
// Contest: Codeforces - Educational Codeforces Round 115 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1598/problem/C
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
		int n;
		cin >> n;
		vector<ll> a(n);
		ll sum = 0, ans = 0;
		map<ll, ll> cnt;
		for(auto &i : a) cin >> i, sum += i;
		for(auto &i : a) cnt[i*n-sum]++;
		for(auto &[x, y] : cnt) if(x > 0) {
			ans += y*cnt[-x];
		} else if(x == 0) ans += y*(y-1)/2;
		cout << ans << '\n';
	});
	
}