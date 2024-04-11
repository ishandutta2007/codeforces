// Problem: B. Morning Jogging
// Contest: Codeforces - Contest 2050 and Codeforces Round #718 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1517/problem/B
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
		vector<array<int, 3>> a;
		vector<multiset<int>> b(n);
		vector<vector<int>> has(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++)
			for(int t, j = 0; j < m; j++) {
				cin >> t;
				a.push_back({t, i, j});
				b[i].insert(t);
			}
		sort(all(a));
		for(int i = 0; i < m; i++) {
			has[a[i][1]][i] = a[i][0];
			b[a[i][1]].erase(b[a[i][1]].find(a[i][0]));
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(has[i][j] == -1) {
					has[i][j] = *b[i].begin();
					b[i].erase(b[i].begin());
				}
			}
		}
		for(auto i : has) {
			for(auto j : i) cout << j << ' ';
			cout << '\n';
		}
	});
	
}