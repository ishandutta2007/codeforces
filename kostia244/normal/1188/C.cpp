// Problem: C. Array Beauty
// Contest: Codeforces - Codeforces Round #572 (Div. 1)
// URL: https://codeforces.com/contest/1188/problem/C
// Memory Limit: 256 MB
// Time Limit: 5000 ms
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
const int N = 1010, C = 1e5 + 2*N, mod = 998244353;
int n, k, a[N], dp[N][N], ptr[N];
void add(int &a, int b) {
	a = a+b>=mod?a+b-mod:a+b;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i], ptr[i] = i-1;
	sort(a+1, a+n+1);
	int ans = 0;
	for(int val = 1; val <= C/(k-1); val++) {
		for(int i = 1; i <= n; i++) 
			while(ptr[i] && a[i]-a[ptr[i]]<val)
				ptr[i]--;
		int sum = 0;
		for(int i = 0; i <= n; i++)
			dp[0][i] = 1;
		for(int i = 1; i <= k; i++) {
			for(int j = 1; j <= n; j++) {
				dp[i][j] = dp[i-1][ptr[j]];
				add(dp[i][j], dp[i][j-1]);
			}
		}
		add(ans, dp[k][n]);
	}
	cout << ans << '\n';
}