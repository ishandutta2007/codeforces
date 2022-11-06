#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m,k;
	cin >> n >> m >> k;
	vector<vector<int>>dp(m+1,vector<int>(k));//dp[i][j] is the maximum sum with remainder j when %k using exactly i elements
	vector<int>dp2(k);
	vector<int>dp3(k);
	for(int i = 0; i<=m; i++){
		for(int j = 0; j<k; j++){
			dp[i][j] = -1e18;
			dp2[j] = -1e18;
			dp3[j] = -1e18;
		}
	}
	dp2[0] = 0; dp3[0] = 0;
	dp[0][0] = 0;
	for(int i = 1; i<=n; i++){
		vector<int>arr(m+1);
		for(int j = 1; j<=m; j++){
			cin >> arr[j];
		}
		for(int j = 1; j<=m; j++){
			for(int a = m/2; a>=1; a--){
				for(int b = 0; b<k; b++){
					dp[a][(b+arr[j])%k] = max(dp[a][(b+arr[j])%k],dp[a-1][b]+arr[j]);
				}
			}
		}
		for(int j = 1; j<=m/2; j++){
			for(int a = 0; a<k; a++){
				for(int b = 0; b<k; b++){
					dp3[(a+b)%k] = max(dp3[(a+b)%k],dp2[a]+dp[j][b]);
					//cout << ": " << a << " " << b << " " << dp[j][b] << " "  << "\n";
				}
			}
		}
		for(int j = 0; j<=m; j++){
			for(int a = 0; a<k; a++){
				dp2[a] = dp3[a];
				dp[j][a] = -1e18;
			}
		}
		dp[0][0] = 0;
	}
	cout << dp2[0] << "\n";
	return 0;
}