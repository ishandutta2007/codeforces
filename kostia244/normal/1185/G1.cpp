#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
const int mod = 1000000007ll;
int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int n, T, dp[230][1<<15][3], song[15][2];
	memset(dp, 0, sizeof dp);
	cin >> n >> T;
	for(int i = 0; i < n; i++)
		cin >> song[i][0] >> song[i][1], song[i][1]--;
	dp[0][0][0] = 1;
	dp[0][0][1] = 1;
	dp[0][0][2] = 1;
	for(int i = 0; i < T; i++) {
		for(int msk = 0; msk < 1<<n; msk++) {
			for(int tp = 0; tp < 3; tp++) {
				if(dp[i][msk][tp]==0)continue;
				for(int to = 0; to < n; to++) {
					if(msk&(1<<to)) continue;
					if(song[to][1]==tp) continue;
					if(i+song[to][0] > T) continue;
					dp[i+song[to][0]][msk|(1<<to)][song[to][1]] += dp[i][msk][tp];
					if(dp[i+song[to][0]][msk|(1<<to)][song[to][1]] >= mod)
						dp[i+song[to][0]][msk|(1<<to)][song[to][1]]-=mod;
				}
			}
		}
	}
	ll ans = 0;
	for(int msk = 0; msk < 1<<n; msk++)
		for(int tp = 0; tp < 3; tp++) {
			ans += dp[T][msk][tp];
			if(ans >= mod) ans-=mod;
		}
	ans = (ans*500000004)%mod;
	cout << ans;
}