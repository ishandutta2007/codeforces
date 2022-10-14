// Problem: D. INOI Final Contests
// Contest: Codeforces - Codeforces Round #684 (Div. 1)
// URL: https://codeforces.com/contest/1439/problem/D
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
const int N = 505;
int dp[N], cnt[N], f[N][N], ss[N][N], sc[N][N], C[N][N], n, m, p;
int add(int a, int b) {
	return a+b>=p?a+b-p:a+b;
}
int mul(int a, int b) {
	return a*1ll*b%p;
}
int inv(int a) {
	return a>1?p - mul(p/a, inv(p%a)):a;
}
int fact[N], ifact[N];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	cin >> n >> m >> p;
	fact[0] = 1;
	ifact[0] = 1;
	for(int i = 1; i < N; i++) {
		fact[i] = mul(fact[i-1], i);
		ifact[i] = inv(fact[i]);
	}
	for(int i = 0; i < n; i++)
		for(int j = 0; j <= i; j++)
			if(!j) C[i][j] = 1;
			else C[i][j] = add(C[i-1][j], C[i-1][j-1]);
	for(int l = 1; l <= n; l++) {
		for(int p = 0; p < l; p++) {
			for(int i = 0; i < l; i++) {
				f[l][p] = add(f[l][p], abs(p-i));
			}
		}
	}
	cnt[0] = 1;
	for(int l = 1; l <= n; l++) {
		for(int s = 0; s < l; s++) {
			int t = mul(cnt[s], cnt[l-1-s]);
			t = mul(t, C[l-1][s]);
			dp[l] = add(dp[l], mul(f[l][s], t));
			t = mul(t, l+1);
			cnt[l] = add(cnt[l], t);
			dp[l] = add(dp[l], mul(dp[s], mul(l+1, mul(cnt[l-1-s], C[l-1][s]))));
			dp[l] = add(dp[l], mul(dp[l-1-s], mul(l+1, mul(cnt[s], C[l-1][s]))));
		}
	}
	for(int i = 0; i <= n; i++)
		cnt[i] = mul(cnt[i], ifact[i]), dp[i] = mul(dp[i], ifact[i]);
	sc[0][0] = 1;
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= m; j++) {
			sc[i+1][j] = add(sc[i+1][j], sc[i][j]);
			ss[i+1][j] = add(ss[i+1][j], ss[i][j]);
			for(int k = 1; i+k <= n && j+k <= m; k++) {
				sc[i+k+1][j+k] = add(sc[i+k+1][j+k],
					mul(cnt[k], sc[i][j]));
				
				ss[i+k+1][j+k] = add(ss[i+k+1][j+k],
					add(mul(dp[k], sc[i][j]), mul(ss[i][j], cnt[k])));
			}
			// cout << i << " " << j << " " << sc[i][j] << " " << ss[i][j] << endl;
		}
	}
	// cout << ss[2][2] << " " << ss[3][2] << endl;
	int ans = mul(ss[n+1][m], fact[m]);
	cout << ans << '\n';
}