// Problem: B. Up the Strip
// Contest: Codeforces - Codeforces Round #740 (Div. 1, based on VK Cup 2021 - Final (Engine))
// URL: https://codeforces.com/contest/1558/problem/B
// Memory Limit: 128 MB
// Time Limit: 6000 ms
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
const int N = 4e6 + 69420;
int n, mod, a[N], run[N];
void add(int &a, int b) {
	a = a+b>=mod?a+b-mod:a+b;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	cin >> n >> mod;
	int pref = 1;
	for(int i = 1; i <= n; i++) {
		add(run[i], run[i-1]);
		add(a[i], run[i]);
		add(a[i], pref);
		for(int z = 2; z*i <= n; z++) {
			add(run[i*z+(z==1)], a[i]);
			if(i*z+z <= n)
				add(run[i*z+z], mod-a[i]);
		}
		if(i>1)
			add(pref, a[i]);
	}
	cout << a[n] << '\n';
}