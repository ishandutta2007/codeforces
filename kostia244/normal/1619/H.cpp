// Problem: H. Permutation and Queries
// Contest: Codeforces - Codeforces Round #762 (Div. 3)
// URL: https://codeforces.com/contest/1619/problem/H
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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
const int N = 1e5 + 55, C = 300;
int n, q, p[N], r[N], f[N], h[N];
void calc(int v) {
	h[0] = v;
	for(int i = 1; i <= C; i++) {
		h[i] = p[h[i-1]];
	}
	for(int j = C; j >= 0; j--) {
		f[v] = h[j];
		v = r[v];
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		cin >> p[i];
		r[p[i]] = i;
	}
	for(int i = 1; i <= n; i++)
		calc(i);
	for(int t, x, y; q--;) {
		cin >> t >> x >> y;
		if(t == 1) {
			swap(p[x], p[y]);
			swap(r[p[x]], r[p[y]]);
			calc(x), calc(y);
		} else {
			while(y>=C)
				x = f[x], y -= C;
			while(y)
				x = p[x], y--;
			cout << x << '\n';
		}
	}
}