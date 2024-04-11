#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
const int maxn = 1030, b = 10*maxn, mod = 1e9 + 7;
using vi = vector<int>;
int n, dp[maxn][20*maxn], a[maxn];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		dp[i][b]++;
	}
	for(int i = 0; i < n; i++) {
		for(int v = 0; v < 20*maxn; v++) {
			if(dp[i][v]) {
				(dp[i+1][v+a[i]] += dp[i][v])%=mod;
				(dp[i+1][v-a[i]] += dp[i][v])%=mod;
			}
		}
	}
	int ans = mod - n + 1;
	for(int i = 1; i <= n; i++) (ans += dp[i][b])%=mod;
	cout << ans;
}