// Problem: A. 
// Contest: Codeforces - Codeforces Round #745 (Div. 1)
// URL: https://codeforces.com/contest/1580/problem/A
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
		vector<vector<int>> a(n, vector<int>(m));
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				char c;cin >> c;
				a[i][j] = c-'0';
			}
		}
		auto b = a;
		for(int i = 1; i < n; i++)
			for(int j = 0; j < m; j++)
				b[i][j] += b[i-1][j];
		int R = 1<<30;
		for(int l = 0; l < n; l++) {
			for(int r = l+4; r < n; r++) {
				auto get = [&](int i) {
					int v = b[r-1][i]-b[l][i];//1s inside
					v += a[l][i] == 0;
					v += a[r][i] == 0;
					return v;
				};
				auto gg = [&](int i) {
					int v = b[r-1][i]-b[l][i];//1s inside
					return (r-l-1) - v;
				};
				int ans = 69420;
				for(int i = 3; i < m; i++) {
					ans = min(ans, get(i-1)+get(i-2)+gg(i-3));
					R = min(R, ans+gg(i));
					ans += get(i);
				}
			}
		}
		assert(R<30);
		cout << R << '\n';
	});
	
}