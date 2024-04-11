//#pragma GCC optimize("trapv")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
using vpi = vector<pi>;
const int maxn = 1e2 + 5;
int dp[maxn][maxn][maxn][2], n, p[maxn];
int cnt[2];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	cnt[0] = n/2;
	cnt[1] = n - cnt[0];
//	cout << cnt[0] << " " << cnt[1] << "\n";''
	for(int i = 0; i < n; i++) {
		cin >> p[i];
		if(p[i])
		cnt[p[i]&1]--;
	}
//	cout << cnt[0] << " " << cnt[1] << "\n";/*
//	return 0;*/
	memset(dp, 0x3, sizeof dp);
	dp[0][cnt[0]][cnt[1]][0]=dp[0][cnt[0]][cnt[1]][1]=0;
	for(int i = 0; i < n; i++) {
		for(int c0 = 0; c0 <= n; c0++) {
			for(int c1 = 0; c1+c0 <= n; c1++) {
				for(int lst = 0; lst < 2; lst++) {
					if(dp[i][c0][c1][lst]>n) continue;
//					cout << i << " " << c0 << " " << c1 << " " << lst << " " << dp[i][c0][c1][lst] << "\n";
					if(p[i]>0) {
						dp[i+1][c0][c1][p[i]&1]=min(dp[i+1][c0][c1][p[i]&1], dp[i][c0][c1][lst] + (lst^(p[i]&1)));
					} else {
						if(c1)
						dp[i+1][c0][c1-1][1]=min(dp[i+1][c0][c1-1][1], dp[i][c0][c1][lst] + (lst^1));
						if(c0)
						dp[i+1][c0-1][c1][0]=min(dp[i+1][c0-1][c1][0], dp[i][c0][c1][lst] + lst);
					}
				}
			}
		}
	}
	int ans = 133333;
	for(int c0 = 0; c0 <= n; c0++) {
		for(int c1 = 0; c1+c0 <= n; c1++) {
			for(int lst = 0; lst < 2; lst++) {
				ans = min(ans, dp[n][c0][c1][lst]);
			}
		}
	}
	cout << ans;
}