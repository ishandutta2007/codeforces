// Problem: A. Shifting Stacks
// Contest: Codeforces - Codeforces Round #703 (Div. 2)
// URL: https://codeforces.com/contest/1486/problem/A
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
		int n;
		cin >> n;
		int ok = 1;
		ll s= 0, z = 0;
		for(int t, i = 0; i < n; i++) cin >> t, s += t, z += i, ok &= s >= z;
		report(ok);
	});
	
}