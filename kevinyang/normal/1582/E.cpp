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
		reverse(arr.begin()+1,arr.end());
		vector<int>psa(n+1);
		for(int i = 1; i<=n; i++){
			psa[i] = psa[i-1]+arr[i];
		}
		int k = (int)sqrt(2*n)+5;
		vector<vector<int>>dp(k+5,vector<int>(n+1));
		int ans = 0;
		for(int j = 1; j<=k; j++){
			for(int i = j; i<=n; i++){
				int v = psa[i]-psa[i-j];
				if(j==1){
					dp[j][i] = v;
					dp[j][i] = max(dp[j][i],dp[j][i-1]);
				}
				else{
					if(dp[j-1][i-j]>0&&v<dp[j-1][i-j]){
						dp[j][i] = v;
					}
					if(dp[j][i]==0){
						dp[j][i] = dp[j][i-1];
					}
					dp[j][i] = max(dp[j][i],dp[j][i-1]);
				}
			}
			if(dp[j][n]>0)ans = j;
			//cout << "\n";
		}
		cout << ans << "\n";
	}
	return 0;
}