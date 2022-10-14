// Problem: E. Mahmoud and Ehab and the xor-MST
// Contest: Codeforces - Codeforces Round #473 (Div. 2)
// URL: https://codeforces.com/contest/959/problem/E
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
map<ll, ll> memo;
ll solve(ll x) {
	if(x == 0 || memo.count(x)) return memo[x];
	ll b = 1ll<<__lg(x);
	//cout << x << " " << b << endl; 
	return memo[x] = solve(b-1) + b + solve(x^b);
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	ll n;
	cin >> n;
	cout << solve(n-1) << '\n';
}