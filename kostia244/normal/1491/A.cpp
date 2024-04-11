// Problem: A. K-th Largest Value
// Contest: Codeforces - Codeforces Global Round 13
// URL: https://codeforces.com/contest/1491/problem/A
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
	//multitest([&](){});
	int n, q;
	cin >> n >> q;
	vector<int> vals(n+1);
	int c1 = 0;
	for(int i = 1; i <= n; i++) cin >> vals[i], c1 += vals[i];
	for(int t, x; q--;) {
		cin >> t >> x;
		if(t == 1) {
			c1 -= vals[x];
			vals[x] ^= 1;
			c1 += vals[x];
		} else {
			cout << (x<=c1) << '\n';
		}
	}
}