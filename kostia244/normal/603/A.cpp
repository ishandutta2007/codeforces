#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vec = pair<ll, ll>;
const int maxn = 1e5 + 5;
int n, dp[maxn][3];
string s;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s;
	memset(dp, -0x3f, sizeof dp);
	dp[0][0] = 0;
	int last[2] = {0, 0};
	s = " " + s;
	for(int i = 1; i <= n; i++) {
		int t = s[i]-'0';
		dp[i][0] = dp[last[t^1]][0]+1;
		dp[i][1] = max(dp[last[t^1]][1], dp[last[t]][0])+1;
		dp[i][2] = max(dp[last[t]][1], dp[last[t^1]][2])+1;
		last[t] = i;
	}
	cout << max({dp[n][2], dp[n][1], dp[n][0]});
}