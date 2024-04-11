// Problem: C. Garden of the Sun
// Contest: Codeforces - Codeforces Round #706 (Div. 1)
// URL: https://codeforces.com/contest/1495/problem/C
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
		int n, m;
		cin >> n >> m;
		auto in = [&](int x, int l, int r) {
			return x >= l && x < r;
		};
		auto good = [&](int x, int y) { return in(x, 0, n) && in(y, 0, m); };
		vector<vector<char>> res(n, vector<char>(m, '.'));
		for(auto &i : res) for(auto &j : i) cin >> j;
		for(int i = 0; i < n; i+=3) {
			for(int j = 0; j < m; j++) res[i][j] = 'X';
		}
		for(int i = 0; i+3 < n; i+=3) {
			int fr = 1;
			for(int j = 0; j < m; j++) {
				if(res[i+1][j] == 'X' || res[i+2][j] == 'X') {
					fr = 0;
					res[i+1][j] = res[i+2][j] = 'X';
					break;
				}
			}
			if(fr) res[i+1][0] = res[i+2][0] = 'X';
		}
		if(n%3 == 0) {
			for(int j = 0; j < m; j++)
				if(res[n-1][j] == 'X') res[n-2][j] = 'X';
		}
		for(auto i :res) {
			for(auto j : i) cout << j;cout << '\n';
		}
	});
	
}