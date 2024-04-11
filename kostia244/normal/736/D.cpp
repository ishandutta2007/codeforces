// Problem: D. 
// Contest: Codeforces - Codeforces Round #382 (Div. 1)
// URL: https://codeforces.com/contest/736/problem/D
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
const int N = 2020;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	int n, m;
	cin >> n >> m;
	vector<bitset<2*N>> a(n);
	vector<array<int, 2>> edges(m);
	for(auto &[f, t] : edges) {
		cin >> f >> t;f--,t--;
		a[f][t] = 1;
	}
	
	for(int i = 0; i < n; i++)
		a[i][N+i] = 1;
	//convert to triangular
	for(int i = 0; i < n; i++) {
		if(!a[i][i]) {
			int j = i;
			while(!a[j][i]) j++;
			swap(a[i], a[j]);
		}
		for(int j = i+1; j < n; j++) {
			if(a[j][i])
				a[j] ^= a[i];
		}
	}
	
	//kill non-diagonal
	for(int i = n-1; i >= 0; i--) {
		for(int j = n-1; j > i; j--) {
			if(a[i][j])
				a[i] ^= a[j];
		}
	}
	for(auto [f, t] : edges) {
		report(!a[t][N+f]);
	}
}