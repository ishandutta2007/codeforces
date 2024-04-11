// Problem: B. Triangles on a Rectangle
// Contest: Codeforces - Educational Codeforces Round 119 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1620/problem/B
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
	multitest([&](){
		#define int long long
		int n, m;
		cin >> n >> m;
		vector<array<int, 2>> a[4];
		for(int k, t = 0; t < 4; t++) {
			cin >> k;
			a[t].resize(k);
			for(auto &i : a[t]) {
				cin >> i[t>=2];
				i[t<2] = t == 1 ? m : (t == 3 ? n : 0);
			}
			sort(all(a[t]));
		}
		int ans = 0;
		for(int t = 0; t < 4; t++) {
			for(int c = 0; c < 4; c++) if(t != c) {
				for(auto [x, y] : a[t]) {
					int x1 = a[c][0][0]-x, y1 = a[c][0][1]-y;
					int x2 = a[c].back()[0]-x, y2 = a[c].back()[1]-y;
					ans = max(ans, abs(x1*y2 - x2*y1));
				}
			}
		}
		cout << ans << '\n';
	});
	
}
/*
0 1
0 2
8 2
8 3
8 4
1 0
4 0
6 0
4 5
5 5

1 0
2 0
2 8
3 8
4 8
0 1
0 4
0 6
5 4
5 5
*/