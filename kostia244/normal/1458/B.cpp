// Problem: B. Glass Half Spilled
// Contest: Codeforces - Codeforces Round #691 (Div. 1)
// URL: https://codeforces.com/contest/1458/problem/B
// Memory Limit: 512 MB
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
	int n;
	cin >> n;
	vector<array<int, 2>> items(n);
	int sum = 0;
	for(auto &[x, y] : items) cin >> y >> x, y -= x, sum += x;
	const int A = 101*101;
	vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(A, -2*A)));
	dp[0][0][0] = 0;
	for(int i = 0; i < n; i++) {
		for(int t = 0; t <= n; t++) {
			for(int c = 0; c < A; c++) {
				dp[i+1][t][c] = dp[i][t][c];
			}
		}
		#define maxq(a, b) a = max(a, b)
		for(int t = 0; t <= n; t++) {
			for(int c = 0; c < A; c++) if(dp[i][t][c]>=0) {
				//cout << i << " _ " << t << " " << c << " " << dp[i][t][c] << " _ " << dp[i][t][c]+items[i][1] << endl;
				maxq(dp[i+1][t+1][c+items[i][0]], dp[i][t][c]+items[i][1]);
			}
		}
	}
	cout << fixed << setprecision(1);
	for(int t = 1; t <= n; t++) {
		int ans = 0;
		for(int c = 0; c < A; c++) if(dp.back()[t][c] >= 0) {
			ans = max(ans, 2*c + min(dp.back()[t][c]*2, sum-c));
		} 
		cout << double(ans)/2 << ' ';
	}
}