#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<bool>>dp(n+1,vector<bool>(200001));
	vector<int>arr(n+1);
	int sum = 0;
	for(int i = 1; i<=n; i++){
		cin >> arr[i]; sum+=arr[i];
	}
	bool f = true;
	if(sum%2==1)f = false;
	dp[0][0] = 1;
	for(int i = 1; i<=n; i++){
		for(int j = 0; j<=200000; j++){
			dp[i][j] = dp[i-1][j];
			if(j>=arr[i]){
				if(dp[i-1][j-arr[i]]){
					dp[i][j] = true;
				}
			}
		}
	}
	if(!dp[n][sum/2])f = false;
	if(!f){
		cout << "0\n";
		return 0;
	}
	pair<int,int>ans = {(int)1e18,0LL};
	for(int i = 1; i<=n; i++){
		int cnt = 0;
		while(arr[i]%2==0){
			arr[i]/=2;
			cnt++;
		}
		pair<int,int>p = {cnt,i};
		ans = min(p,ans);
	}
	cout << "1\n";
	cout << ans.second << "\n";
	return 0;
}