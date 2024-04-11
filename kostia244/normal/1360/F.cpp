#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,popcnt")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 60, mod = 1e9 + 7, i2 = (mod+1)/2;
int n, m, p[11][1<<10], pc[11][1<<10], dp[11][1<<10], hlp[11][26];
string a[11];
string ans;
void rec(int i, int m) {
	if(i) {
		rec(i-1, p[i][m]);
		ans += pc[i][m];
	}
}
void solve() {
	memset(p, 0, sizeof p);
	memset(pc, 0, sizeof pc);
	memset(dp, 0, sizeof dp);
	memset(hlp, 0, sizeof hlp);
	ans = "";
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < m; i++) {
		for(char c = 'a'; c <= 'z'; c++) {
			for(int j = 0; j < n; j++) hlp[i][c-'a'] += (a[j][i]!=c)<<j;
		}
	}
	dp[0][0] = 1;
	for(int i = 0; i < m; i++) {
		for(int msk = 0; msk < 1<<n; msk++) {
			if(!dp[i][msk]) continue;
			for(char c = 'a'; c <= 'z'; c++) {
				int u = hlp[i][c-'a'];
				if(u&msk) continue;
				dp[i+1][u|msk] = 1;
				p[i+1][u|msk] = msk;
				pc[i+1][u|msk] = c;
			}
		}
	}
	int x = 0;
	for(int i = 0; i < 1<<n; i++) if(dp[m][i]) x = i;
	if(!dp[m][x]) cout << "-1\n";
	else {
	rec(m, x);
	cout << ans << '\n';
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}