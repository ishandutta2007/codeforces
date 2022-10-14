#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 1<<17, mod = 1e9 + 7;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const int bias = 16*17;
int n, dp[1<<16][32*17], R[20], B[20];
char C[20];
#define get(x, y) (((x)>>(y))&1)
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> C[i] >> R[i] >> B[i];
	}
	memset(dp, 0x3f, sizeof dp);
	dp[0][bias] = 0;//DIFF = red - blue
	for(int msk = 0; msk < 1<<n; msk++) {
		int blues = 0, reds = 0, defbias = 0;
		for(int j = 0; j < n; j++) if(get(msk, j)) {
			(C[j]=='B'?blues:reds)++;
			defbias += -R[j] + B[j];
		}
		for(int d = 0; d < 32*17; d++) {
			if(dp[msk][d] >= 1061109567) continue;
			int rd = d-bias+defbias;
			int cr, cb;
			if(rd > 0) {
				cr = rd;
				cb = 0;
			} else {
				cr = 0;
				cb = -rd;
			}
			for(int j = 0; j < n; j++) if(!get(msk, j)) {
				int cost_r = max(0, R[j]-reds);
				int cost_b = max(0, B[j]-blues);
				int at = max(max(cost_r-cr, cost_b-cb), 0);;
				int nr = cr + at - cost_r;
				int nb = cb + at - cost_b;
				int nans = dp[msk][d] + at;
				int nd = nr - nb + bias + R[j] - B[j] - defbias;
				dp[msk | (1<<j)][nd] = min(dp[msk | (1<<j)][nd], nans);
			}
		}
	}
	int ans = 1<<30;
	for(int i = 0; i < 32*17; i++) ans = min(ans, dp[(1<<n)-1][i]);
	cout << ans+n << endl;
}