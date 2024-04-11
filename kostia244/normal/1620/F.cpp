// Problem: F. Bipartite Array
// Contest: Codeforces - Educational Codeforces Round 119 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1620/problem/F
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
const int N = 1e6 + 16;
int dp[N][2];
int p[N][2];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	multitest([&](){
		int n;
		cin >> n;
		vector<int> a(n);
		for(auto &i : a) 
			cin >> i;
		for(int i = 0; i <= n; i++)
			dp[i][0] = dp[i][1] = 1<<30;
		dp[0][0] = dp[0][1] = -(1<<30);
		auto upd = [&](int i, int j, int k, int U) {
			if(dp[i][j] > k) {
				dp[i][j] = k;
				p[i][j] = U;
			}
		};
		for(int i = 0; i+1 < n; i++) {
			for(int z = 0; z < 2; z++) {
				int v = z ? -a[i] : a[i];
				for(int f = 0; f < 2; f++) {
					int vv = f ? -a[i+1] : a[i+1];
					if(v <= vv) {
						upd(i+1, f, dp[i][z], z);
					}
					if(dp[i][z] <= vv) {
						upd(i+1, f, v, z);
					}
				}
			}
		}
		if(dp[n-1][0] == (1<<30)) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
			int t = 0;
			for(int i = n-1; i>=0; i--) {
				if(t) a[i] *= -1;
				t = p[i][t];
			}
			for(auto i : a) cout << i << " ";
			cout << '\n';
		}
	});
}