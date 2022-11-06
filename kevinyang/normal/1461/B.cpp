#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		vector<vector<char>>mp(n+2,vector<char>(m+2));
		vector<vector<int>>dp(n+2,vector<int>(m+2));
		int ans = 0;
		for(int i = 2; i<=n+1; i++){
			string s;
			cin >> s;
			for(int j = 2; j<=m+1; j++){
				mp[i][j] = s[j-2];
				if(mp[i][j]!='*')continue;
				dp[i][j] = min({dp[i-1][j-1],dp[i][j-1],dp[i][j-2]})+1;
				ans+=dp[i][j];
			}
		}
		cout << ans << "\n";
	}
	return 0;
}