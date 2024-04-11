// Problem: D1.     ( )
// Contest: Codeforces - Codeforces Round #540 (Div. 3)
// URL: https://codeforces.com/contest/1118/problem/D1
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
int dp[120][120];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(auto &i : a) cin >> i;
	sort(all(a));
	int days = 1;
	while(days <= n) {
		memset(dp, -0x4f, sizeof dp);
		dp[0][0] = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++) {
				dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
				dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + max(0, a[i]-(j/days)));
			}
		if(*max_element(dp[n], dp[n]+n+1) >= m) break;
		days++;
	}
	cout << (days > n ? -1 : days) << '\n';
}