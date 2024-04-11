#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1<<11, mod = 1e9 + 7;
int n, m, dp[maxn][maxn], len[maxn];
string s, p;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	dp[0][0] = 0;
	cin >> s >> p;
	n = s.size(), m = p.size();
	for(int i = 0; i < n; i++) {
		int ti = i, j = 0;
		while(ti < n && j < m)
			j += p[j] == s[ti++];
		len[i] = j!=m?-1:ti;
	}
	memset(dp, 0x3f,sizeof dp);
	dp[0][0] = 0;
	for(int i = 0; i <= n; i++)
		for(int j = 0; j < n; j++) {
			dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
			if(len[i] != -1) {
				dp[len[i]][j+1] = min(dp[len[i]][j+1], dp[i][j] + (len[i]-i) - (int)p.size());
			}
		}
	for(int i = 0; i <= n; i++) {
		int ans = 0;
		for(int j = 0; j*p.size() <= n-i; j++) {
			if(dp[n][j] <= i && dp[n][j] < dp[maxn-1][maxn-1]) ans = j;
		}
		cout << ans << " ";
	}
	cout << endl;
}