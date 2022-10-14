// Problem: B. Beautiful Array
// Contest: Codeforces - Codeforces Round #816 (Div. 2)
// URL: https://codeforces.com/contest/1715/problem/B
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
		ll n, k, b, s;
		cin >> n >> k >> b >> s;
		if(s < b*k || s > b*k + n*(k-1))
			cout << "-1\n";
		else {
			s -= b*k;
			for(int i = 0; i < n; i++) {
				ll t = min(k-1, s);
				cout << (i==0?b*k:0) + t << ' ';
				s-=t;
			}
		cout << '\n';
		}
	});
	
}