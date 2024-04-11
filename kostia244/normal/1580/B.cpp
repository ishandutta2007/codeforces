// Problem: B.  
// Contest: Codeforces - Codeforces Round #745 (Div. 1)
// URL: https://codeforces.com/contest/1580/problem/B
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
const int N = 110;
int nonz = 0, tot = 0;
ll a, b, c, m, C[N][N], dp[N][N][N],fact[N];
ll f(int n, int d, int c) {
	if(n == 0) return c == 0;
	if(n == 1) return (c==0&&d>1)||(c==1&&d==1);
	if(d == 0) return 0;
	if(d>n) return c==0?fact[n]:0;
	if(2*c-1>n||2*c-1+d-10>n) return 0;
	if(dp[n][d][c] >= 0) return dp[n][d][c];
	ll &ans = dp[n][d][c];
	if(d == 1) {
		if(c != 1) return ans = 0;
		return ans = fact[n];
	} else
		ans = 0;
	__int128 res = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= c; j++) {
			ll t = f(i, d-1, j)*1ll*f(n-1-i, d-1, c-j)%m;
			res += t*C[n-1][i];
		}
		res %= m;
	}
	ans = res;
	nonz += ans != 0;
	tot++;
	return ans;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	memset(dp, -1, sizeof dp);
	cin >> a >> b >> c >> m;
	fact[0] = 1;
	for(int i = 1; i < N; i++) fact[i] = fact[i-1]*i%m;
	for(int i = 0; i < N; i++)
		for(int j = 0; j <= i; j++)
			if(!j) C[i][j] = 1; 
			else C[i][j] = (C[i-1][j]+C[i-1][j-1])%m;
	cout << f(a, b, c) << '\n';
}