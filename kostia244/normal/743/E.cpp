#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
const int mod = 1000000007ll;
int n, a[1010], dp[1010][1 << 8], nxt[1010][1010][9];
bool can(int cnt) {
	memset(dp, 0, sizeof dp);
	dp[1][0] = 1;
	for (int i = 1; i <= n; i++) {
		if (dp[i][(1 << 8) - 1])
			return true;
		for (int msk = 0; msk < 1 << 8; msk++) {
			if(dp[i][msk]==0) continue;
			for (int j = 0; j < 8; j++) {
				if ((msk >> j) & 1)
					continue;
				dp[nxt[i][cnt][j]][msk|(1<<j)]=1;
			}
		}
	}
	return dp[n + 1][(1 << 8) - 1];
}
int get(int cnt) {
	memset(dp, 0, sizeof dp);
	dp[1][0] = 1;
	int res = 1;
	for (int i = 1; i <= n; i++) {
		if (dp[i][(1 << 8) - 1])
		res = max(res, dp[i][(1 << 8) - 1]);
		for (int msk = 0; msk < 1 << 8; msk++) {
			if(dp[i][msk]==0) continue;
			for (int j = 0; j < 8; j++) {
				if ((msk >> j) & 1)
					continue;
				dp[nxt[i][cnt][j]][msk|(1<<j)]=max(dp[nxt[i][cnt][j]][msk|(1<<j)], dp[i][msk]);
				dp[nxt[i][cnt+1][j]][msk|(1<<j)]=max(dp[nxt[i][cnt+1][j]][msk|(1<<j)], dp[i][msk]+1);
			}
		}
	}
	return max(res, dp[n + 1][(1 << 8) - 1])-1;
}
int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	memset(nxt, 0, sizeof nxt);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i], a[i]--, nxt[i][1][a[i]] = i + 1;
	for (int i = n; i; i--) {
		for (int num = 1; num <= n; num++) {
			for (int t = 0; t < 8; t++) {
				nxt[i][0][t]=i;
				if (nxt[i][num][t])
					continue;
				if (num == 1)
					nxt[i][num][t] = nxt[i + 1][num][t];
				else
					nxt[i][num][t] = nxt[nxt[i][1][t]][num - 1][t];
			}
		}
	}
	int ans = 0;
	for (int i = 1 << 9; i; i >>= 1) {
		if (8 * (ans + i) <= n && can(ans + i))
			ans += i;
	}
	cout << ans*8 + get(ans);
}