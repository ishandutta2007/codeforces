// Problem: C1. Guessing the Greatest (easy version)
// Contest: Codeforces - Codeforces Round #703 (Div. 2)
// URL: https://codeforces.com/contest/1486/problem/C1
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
int qry(int l, int r) {
	if(l == r) return -1;
	cout << "? " << l << " " << r << endl;
	cin >> l;
	return l;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	int n;
	cin >> n;
	int a = qry(1, n);
	int f = qry(1, a);
	int g = qry(a, n);
	if(f == a) {
		int pos = a;
		for(int z = 1<<17; z>>=1;)
			if(pos-z > 0 && qry(pos-z, a) != a) pos -= z;
		cout << "! " << --pos << endl;
	} else {
		int pos = a;
		for(int z = 1<<17; z>>=1;)
			if(pos+z < n && qry(a, pos+z) != a) pos += z;
		cout << "! " << ++pos << endl;
	}
}