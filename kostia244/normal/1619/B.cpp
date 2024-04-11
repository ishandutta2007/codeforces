// Problem: B. Squares and Cubes
// Contest: Codeforces - Codeforces Round #762 (Div. 3)
// URL: https://codeforces.com/contest/1619/problem/B
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
		ll n;
		cin >> n;
		ll x = 1, y = 1, z = 1;
		while(x*x <= n) x++;
		while(y*y*y <= n) y++;
		while(z*z*z*z*z*z <= n) z++;
		cout << (x+y-z-1) << '\n';
	});
	
}