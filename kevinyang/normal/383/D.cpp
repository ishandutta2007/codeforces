#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = (int)1e9+7;
vector<int>arr(1001);
int solve(int l, int r){
	if(l==r)return 0;
	int m = (l+r)/2;
	vector<int>hm(10001);
	if(true){
		vector<int>dp(10001);
		vector<int>dp2(10001);
		dp[5000] = 1;
		for(int i = m; i>=l; i--){
			for(int j = 0; j<=10000; j++){
				if(j+arr[i]<=10000){
					dp2[j+arr[i]]+=dp[j];
					dp2[j+arr[i]]%=mod;
				}
				if(j-arr[i]>=0){
					dp2[j-arr[i]]+=dp[j];
					dp2[j-arr[i]]%=mod;
				}
			}
			for(int j = 0; j<=10000; j++){
				hm[j]+=dp2[j]; hm[j]%=mod;
				dp[j] = dp2[j]; dp2[j] = 0;
			}
		}
	}
	int ans = 0;
	if(true){
		vector<int>dp(10001);
		vector<int>dp2(10001);
		dp[5000] = 1;
		for(int i = m+1; i<=r; i++){
			for(int j = 0; j<=10000; j++){
				if(j+arr[i]<=10000){
					dp2[j+arr[i]]+=dp[j];
					dp2[j+arr[i]]%=mod;
				}
				if(j-arr[i]>=0){
					dp2[j-arr[i]]+=dp[j];
					dp2[j-arr[i]]%=mod;
				}
			}
			for(int j = 0; j<=10000; j++){
				ans+=hm[j]*dp2[j]%mod; ans%=mod;
				dp[j] = dp2[j]; dp2[j] = 0;
			}
		}
	}
	return (ans + solve(l,m) + solve(m+1,r))%mod;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
	}
	cout << solve(1,n) << "\n";
	return 0;
}