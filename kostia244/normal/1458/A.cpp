// Problem: A. Row GCD
// Contest: Codeforces - Codeforces Round #691 (Div. 1)
// URL: https://codeforces.com/contest/1458/problem/A
// Memory Limit: 512 MB
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
	#define int long long
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	int n, m;
	cin >> n >> m;
	int g = 0, lst = -1;
	for(int t, i = 0; i < n; i++) {
		cin >> t;
		if(lst != -1) g = __gcd(g, abs(lst-t));
		lst = t;
	}
	for(int t, i = 0; i < m; i++) {
		cin >> t;
		cout << __gcd(lst+t, g) << ' ';
	}
}