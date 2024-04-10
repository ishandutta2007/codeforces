#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	string s,t;
	cin >> s >> t;
	vector<vector<int>>dp(n+1,vector<int>(m+1));//ans if first substr ends at i and second ends at j
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			if(s[i-1]==t[j-1]){
				dp[i][j] = max({dp[i-1][j-1]+2,2LL});
			}
			else{
				dp[i][j] = max({-2LL,dp[i-1][j]-1,dp[i][j-1]-1});
			}
		}
	}
	int ans = 0;
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			ans = max(ans,dp[i][j]);
		}
	}
	cout << ans << "\n";
	return 0;
}