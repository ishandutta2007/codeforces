// Problem: E. Mirror Grid
// Contest: Codeforces - Codeforces Round #806 (Div. 4)
// URL: https://codeforces.com/contest/1703/problem/E
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
		int n, ans = 0;cin >> n;
		vector<string> a(n);
		vector<vector<int>> cnt(n, vector<int>(n));
		for(auto &i : a) cin >> i;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++) {
				int x = i;
				int y = j;
				int c[2] = { 0 };
				for(int z = 0; z < 4; z++) {
					if(!cnt[x][y]++)
						c[a[x][y]-'0']++;
					int tx = y;
					int ty = n - 1 - x;
					x = tx, y = ty;
				}
				//(2, 1) -> (1, 3) ->
				//(y, n - 1 - x)
				ans += min(c[0], c[1]);
			}
		cout << ans << '\n';
	});
	
}