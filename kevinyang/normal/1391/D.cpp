#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	vector<vector<int>>mp(n,vector<int>(m+1));
	for(int i = 0; i<n; i++){
		string s;
		cin >> s;
		for(int j = 1; j<=m; j++){
			if(s[j-1]=='1')mp[i][j] = 1;
		}
	}
	vector<int>arr(m+1);
	for(int i = 1; i<=m; i++){
		for(int j = 0; j<n; j++){
			if(mp[j][i]==1){
				arr[i]^=(1<<j);
			}
		}
	}
	if(n>3){
		cout << "-1\n";
		return 0;
	}
	if(n==1){
		cout << "0\n";
		return 0;
	}
	vector<vector<int>>dp(1<<n,vector<int>(m+1,(int)1e9));
	for(int i = 0; i<(1<<n); i++){
		dp[i][1] = __builtin_popcount(i^arr[1]);
	}
	for(int t = 2; t<=m; t++){
		for(int j = 0; j<(1<<n); j++){
			for(int i = 0; i<(1<<n); i++){
				int cnt = ((i&1)>0)+((i&2)>0)+((j&1)>0)+((j&2)>0);
				int cnt2 = ((i&2)>0)+((i&4)>0)+((j&2)>0)+((j&4)>0);
				//cout << i << " " << j << " " << cnt << " " << cnt2 << "\n";
				//cout << ((j&1)>0) << " " << ((j&2)>0) << " " << ((j&4)>0) << "\n";
				if(cnt%2==1){
					if(n==2||cnt2%2==1){
						//cout << "nae\n";
						dp[i][t] = min(dp[i][t],dp[j][t-1]+__builtin_popcount(i^arr[t]));
					}
				}
			}
		}
	}
	int ans = (int)1e9;
	for(int j = 0; j<(1<<n); j++){
		ans = min(ans,dp[j][m]);
	}
	cout << ans << "\n";
	return 0;
}