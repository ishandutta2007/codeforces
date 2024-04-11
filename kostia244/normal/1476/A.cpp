// Problem: G. Minimum Difference
// Contest: Codeforces - Educational Codeforces Round 103 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1476/problem/G
// Memory Limit: 256 MB
// Time Limit: 5000 ms
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
		ll x = (k+n-1)/k;
		x *= k;
		cout << (x+n-1)/n << '\n';
	});
	
}