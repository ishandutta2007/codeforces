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
		vector<int>arr(n+1);
		for(int i = 1; i<=n; i++){
			cin >> arr[i];
		}
		vector<vector<int>>dp(2,vector<int>(n+1));
		dp[0][1] = (int)1e18;dp[0][0] = (int)1e18;dp[1][0] = (int)1e18;
		dp[1][1] = arr[1];
		if(n>1){
			dp[1][2] = arr[1]+arr[2];
			dp[0][2] = dp[1][1];
		}
		
		for(int i = 3; i<=n; i++){
			dp[0][i] = min(dp[1][i-1],dp[1][i-2]);
			dp[1][i] = min(dp[0][i-1]+arr[i],dp[0][i-2]+arr[i]+arr[i-1]);
		}
		cout << min(dp[0][n],dp[1][n]) << "\n";
	}
	return 0;
}