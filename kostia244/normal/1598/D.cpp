// Problem: D. Training Session
// Contest: Codeforces - Educational Codeforces Round 115 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1598/problem/D
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
		ll n;
		cin >> n;
		map<int, ll> acnt, bcnt;
		vector<array<int, 2>> p(n);
		for(auto &[a, b] : p) {
			cin >> a >> b;
			acnt[a]++, bcnt[b]++;
		}
		ll ans = n*(n-1)*(n-2)/6;
		for(auto &[a, b] : p) {
			ans -= (acnt[a]-1)*(bcnt[b]-1);
		}
		cout << ans << endl;
	});
	
}