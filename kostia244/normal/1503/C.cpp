// Problem: C. Travelling Salesman Problem
// Contest: Codeforces - Codeforces Round #712 (Div. 1)
// URL: https://codeforces.com/contest/1503/problem/C
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
	int n;
	cin >> n;
	vector<array<ll, 2>> a(n);
	ll fi = 1ll<<60;
	ll sum = 0;

	map<ll, ll> fuck;

	for(auto &[x, y] : a) {
		cin >> x >> y;
		fi = min(fi, x);
		sum += y;
		fuck[x] = max(fuck[x], y);
	}
	ll lst = -1, free = fi;
	sort(all(a));
	for(auto [x, y] : fuck) {
		if(x > free)
			sum += x-free;
		free = max(free, x+y);
		lst = x;
	}
	cout << sum << '\n';
}