// Problem: B. 3-Coloring
// Contest: Codeforces - Codeforces Round #712 (Div. 1)
// URL: https://codeforces.com/contest/1503/problem/B
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
	array<vector<array<int, 2>>, 2> c;
	vector<vector<int>> col(n, vector<int>(n));
	for(int i = 0; i < n; i++)for(int j = 0; j < n; j++) c[(i+j)&1].push_back({1+i, 1+j});
	for(int t, i = n*n; i--;) {
		cin >> t;
		if(t == 3) {
			int x = c[0].empty();
			cout << x+1 << " " << c[x].back()[0] << " " << c[x].back()[1] << endl;
			c[x].pop_back();
		} else if(t == 1) {
			int x = c[1].empty() ? 0 : 1;
			cout << (c[1].empty() ? 3 : 2) << " " << c[x].back()[0] << " " << c[x].back()[1] << endl;
			c[x].pop_back();
		} else {
			int x = c[0].empty() ? 1 : 0;
			cout << (c[0].empty() ? 3 : 1) << " " << c[x].back()[0] << " " << c[x].back()[1] << endl;
			c[x].pop_back();
		}
	}
}