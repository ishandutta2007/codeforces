#include <bits/stdc++.h>
using namespace std;
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,t;
	cin >> n >> t;
	vector<pair<int,int>>arr(n+1);
	for(int i = 1; i<=n; i++){
		int x,y;
		cin >> x >> y;
		arr[i] = {x,y};
	}
	vector<vector<double>>dp(2,vector<double>(t+1));
	vector<vector<double>>psa(2,vector<double>(t+1));
	vector<vector<double>>powers(2,vector<double>(t+1));
	double ans = 0;
	dp[1][0] = 1; psa[1][0] = 1; powers[1][0] = 1;
	for(int i = 1; i<=t; i++){
		psa[1][i] = psa[1][i-1]*(100-arr[1].first)/100.0; + dp[1][i];

	}
	powers[1][1] = (100-arr[1].first)/100.0;
	for(int j = 2; j<=t; j++){
		int i = 1; int idx = i&1;
		powers[idx][j] = powers[idx][j-1]*powers[idx][1];
	}
	for(int i = 2; i<=n+1; i++){
		int idx = i&1;
		powers[idx][0] = 1;
		powers[idx][1] = (100-arr[i].first)/100.0;
		for(int j = 2; j<=t; j++){
			powers[idx][j] = powers[idx][j-1]*powers[idx][1];
		}
		for(int j = 1; j<=t; j++){
			dp[idx][j] = psa[(idx)^1][j-1]*arr[i-1].first/100.0;
			if(j>=arr[i-1].second){
				dp[idx][j]-=psa[(idx)^1][j-arr[i-1].second]*powers[(idx)^1][arr[i-1].second-1]*arr[i-1].first/100.0;
				dp[idx][j]+=dp[(idx)^1][j-arr[i-1].second]*powers[(idx)^1][arr[i-1].second-1];
			}
			psa[idx][j] = psa[idx][j-1]*(100-arr[i].first)/100.0+dp[idx][j];
			if(i==n+1)ans+=(i-1)*dp[idx][j];
			else{
				if(j+arr[i].second<=t)continue;
				ans+=(i-1)*dp[idx][j]*powers[idx][t-j];
			}
		}
		for(int j = 0; j<=1; j++){
			powers[(idx)^1][j] = dp[(idx)^1][j] = psa[(idx)^1][j] = 0;
		}
	}
	/*
	for(int i = 1; i<=n; i++){
		powers[i][0] = 1;
		powers[i][1] = (100-arr[i].first)/100.0;
		for(int j = 2; j<=t; j++){
			powers[i][j] = powers[i][j-1]*powers[i][1];
		}
	}
	for(int i = 2; i<=n+1; i++){
		for(int j = 1; j<=t; j++){
			dp[i][j] = psa[i-1][j-1]*arr[i-1].first/100.0;
			if(j>=arr[i-1].second)dp[i][j]-=psa[i-1][j-arr[i-1].second]*powers[i-1][arr[i-1].second-1]*arr[i-1].first/100.0;
			if(j>=arr[i-1].second)dp[i][j]+=dp[i-1][j-arr[i-1].second]*powers[i-1][arr[i-1].second-1];
			psa[i][j] = psa[i][j-1]*(100-arr[i].first)/100.0+dp[i][j];
		}
	}
	cout << fixed << setprecision(10);
	double ans = 0;
	for(int i = 2; i<=n+1; i++){
		for(int j = 1; j<=t; j++){
			if(i==n+1)ans+=(i-1)*dp[i][j];
			else{
				if(j+arr[i].second<=t)continue;
				ans+=(i-1)*dp[i][j]*powers[i][t-j];
			}
		}
	}
	*/
	cout << fixed << setprecision(10);
	cout << ans << "\n";
	return 0;
}