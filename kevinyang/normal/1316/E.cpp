#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>>arr(100001,vector<int>(8));
int n,p,k;
bool comp(vector<int>a, vector<int>b){
	return a[p] > b[p];
}
vector<vector<int>>dp(100001,vector<int>(1<<7));
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	
	cin >> n >> p >> k;
	for(int i = 1; i<=n; i++){
		cin >> arr[i][p];
	}
	for(int i = 1; i<=n; i++){
		for(int j = 0; j<p; j++){
			cin >> arr[i][j];
		}
	}
	sort(arr.begin()+1,arr.begin()+n+1,comp);
	for(int j = 1; j<(1<<p); j++){
		dp[0][j] = -(int)1e18;
	}
	for(int i = 1; i<=n; i++){
		for(int mask = 0; mask<(1<<p); mask++){
			if(__builtin_popcount(mask)>i){
				dp[i][mask] = -(int)1e18;
			}
			for(int j = 0; j<p; j++){
				if(mask&(1<<j)){
					dp[i][mask] = max(dp[i][mask],dp[i-1][mask^(1<<j)] + arr[i][j]);
				}
			}
			if(i>k+__builtin_popcount(mask)){
				dp[i][mask] = max(dp[i][mask],dp[i-1][mask]);
			}
			else{
				dp[i][mask] = max(dp[i][mask],dp[i-1][mask]+arr[i][p]);
			}
		}
	}
	cout << dp[n][(1<<p)-1] << "\n";
	return 0;
}