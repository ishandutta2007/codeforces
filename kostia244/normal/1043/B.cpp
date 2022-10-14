// Problem: B. Lost Array
// Contest: Codeforces - Codeforces Round #519 by Botan Investments
// URL: https://codeforces.com/contest/1043/problem/B
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
	int n;
	cin >> n;
	vector<ll> a(n), b;
	for(auto &i : a) cin >> i;
	for(int i = n-1; i-1 >= 0; i--) a[i] = a[i]-a[i-1];
	for(int len = 1; len <= n; len++) {
		int ok = 1;
		for(int i = 0; i+len < n; i++)
			ok &= a[i] == a[i+len];
		if(ok) b.push_back(len);
	}
	cout << b.size() << '\n';
	for(auto i : b) cout << i << " "; cout << endl;
}