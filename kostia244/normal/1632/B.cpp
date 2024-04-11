// Problem: B. Roof Construction
// Contest: Codeforces - Codeforces Round #769 (Div. 2)
// URL: https://codeforces.com/contest/1632/problem/B
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
		int b = 1;
		while(2*b < n) b *= 2;
		for(int i = n-1; i >= b; i--) cout << i << " ";
		for(int i = 0; i < b; i++) cout << i << " "; cout << '\n';
	});
	
}