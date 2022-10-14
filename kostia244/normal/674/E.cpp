#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define int long long
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 1<<19, C = 60;
int p[maxn], sz = 1;
ld dp[maxn][C], ans[maxn];
void create(int v) {
	dp[sz][0] = 1;
	p[++sz] = v;
	ld prev = 0;
	for(int lst = sz-1, h = 1; v && h < C; lst = v, h++, v = p[v]) {
		ld old = (dp[v][h] - (prev/2))/(1.-(prev/2));
		prev = dp[v][h];
		dp[v][h] = old + (1.-old)*(dp[lst][h-1]/2);
		ans[v] -= prev;
		ans[v] += dp[v][h];
	}
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	memset(dp, 0, sizeof dp);
	memset(ans, 0, sizeof ans);
	memset(p, 0, sizeof p);
	int q;
	cin >> q;
	dp[1][0] = 0;
	cout << fixed << setprecision(15);
	for(int t, v; q--;) {
		cin >> t >> v;
		if(t == 1) {
			create(v);
			//for(int i = 1; i <= sz; i++)
			//	for(int h = 0; h < 5; h++) cout << dp[i][0];
		} else cout << ans[v] << '\n';
	}
}