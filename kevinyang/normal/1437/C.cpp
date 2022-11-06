#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<vector<int>>dp(2*n+1,vector<int>(2*n+1,(int)1e18));
		vector<int>arr(n+1);
		for(int i = 1; i<=n; i++){
			cin >> arr[i];
		}
		for(int i = 0; i<=2*n; i++){
			dp[i][0] = 0;
		}
		sort(arr.begin(),arr.end());
		for(int i = 1; i<=2*n; i++){
			for(int j = 1; j<=n; j++){
				dp[i][j] = min(dp[i][j],dp[i-1][j]);
				dp[i][j] = min(dp[i][j],dp[i-1][j-1]+abs(i-arr[j]));
			}
		}
		cout << dp[2*n][n] << "\n";
	}
	return 0;
}