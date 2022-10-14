// Problem: A. New Year Transportation
// Contest: Codeforces - Good Bye 2014
// URL: https://codeforces.com/contest/500/problem/A
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
	//multitest([&](){});
	int n, t;
	cin >> n >> t;
	vector<int> a(n-1);
	for(auto &i : a) cin >> i;
	t--;
	int p = 0;
	while(p < t) {
		p += a[p];
	}
	report(p == t);
}