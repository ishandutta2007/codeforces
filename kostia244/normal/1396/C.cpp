#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
using ll = long long;
using namespace std;
const int maxn = 1<<20;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll dp[maxn][2], n, P, L, A, D, c[maxn];
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> P >> L >> A >> D;
	for(int i = 0; i < n; i++) cin >> c[i];
	P = min(P, A);
	memset(dp, 0x3f, sizeof dp);
	dp[0][0] = 0;
	for(int i = 0; i < n; i++) {
		ll dm1 = min(P*(c[i]+1), L), next = i+1==n?0:D;
		ll ak = P*c[i] + A;
		dp[i+1][1] = min(dp[i+1][1], next + dm1 + dp[i][0]);
		dp[i+1][0] = min(dp[i+1][0], next + 2*D + min(P, L) + dm1 + dp[i][0]);
		dp[i+1][0] = min(dp[i+1][0], next + ak + dp[i][0]);
		dp[i+1][0] = min(dp[i+1][0], dp[i][1] + dm1 + 2*D + 2*min(P, L) + next);
		dp[i+1][0] = min(dp[i+1][0], dp[i][1] + ak + D + min(P, L) + 2*next);
		//cout << dp[i][0] << " " << dp[i][1] << endl;
	}
	cout << dp[n][0] << '\n';
}