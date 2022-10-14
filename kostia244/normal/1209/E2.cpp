#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,popcnt,sse4.1,sse4.2,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 1<<20, mod = 998244353, rt = 565042129, i2 = (mod+1)/2;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m;
int ta[maxn][16], a[15][15], dp[14][13][1<<12];
void solve() {
	memset(dp, 0, sizeof dp);
	cin >> n >> m;
	for(int i = 0; i < n; i++) 
		for(int j = 0; j < m; j++)
			cin >> ta[j][i];
	vpi rows;
	for(int i = 0; i < m; i++) {
		int cm = 0;
		for(int j = 0; j < n; j++) cm = max(cm, ta[i][j]);
		rows.pb({-cm, i});
	}
	sort(all(rows));
	if(m > 12) m = 12;
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			a[i][j] = ta[rows[i].second][j];
		}
	}
	for(int i = 0; i < m; i++) {
		for(int s = 0; s < n; s++)
			for(int msk = 0; msk < 1 << n; msk++)
				dp[i][s][msk] = dp[i][0][msk];
		for(int s = 0; s < n; s++) {
			for(int msk = 1 << n; msk--;) {
				for(int j = 0; j < n; j++) {
					if((msk>>j)&1) {
						dp[i][s][msk^(1<<j)] = max(dp[i][s][msk^(1<<j)], dp[i][s][msk]+a[i][(j+s)%n]);
					}
				}
				dp[i+1][0][msk] = max(dp[i+1][0][msk], dp[i][s][msk]);
			}
		}
	}
	cout << dp[m][0][0] << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}