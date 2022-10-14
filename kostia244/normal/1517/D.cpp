// Problem: D. Explorer Space
// Contest: Codeforces - Contest 2050 and Codeforces Round #718 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1517/problem/D
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
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> a(n, vector<int>(m-1));
	for(auto &i : a)
		for(auto &j : i)
			cin >> j;
	vector<vector<int>> b(n-1, vector<int>(m));
	for(auto &i : b)
		for(auto &j : i)
			cin >> j;
	int bad = k&1;k/=2;
	if(bad) {
		for(int i = 0; i < n; i++, cout << '\n')
			for(int j = m;j--;) cout << "-1 ";
		exit(0);
	}
	const int inf = 1<<30;
	vector<vector<int>> dist(n, vector<int>(m, 0));
	vector<vector<int>> dist2(n, vector<int>(m, inf));
	int timer = 0;
	for(int x = 0; x < k; x++) {
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++) {
				dist2[i][j] = inf;
				if(j) dist2[i][j] = min(dist2[i][j], dist[i][j-1] + a[i][j-1]);
				if(j+1<m) dist2[i][j] = min(dist2[i][j], dist[i][j+1] + a[i][j]);
				if(i) dist2[i][j] = min(dist2[i][j], dist[i-1][j] + b[i-1][j]);
				if(i+1<n) dist2[i][j] = min(dist2[i][j], dist[i+1][j] + b[i][j]);
			}
		dist = dist2;
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cout << 2*dist[i][j] << " ";
		}
		cout << '\n';
	}
}