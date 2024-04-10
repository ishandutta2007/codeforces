#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
vector<int>arr(505);
vector<vector<int>>dp(505,vector<int>(505));
int f(int l, int r){
	if(l+1==r){
		if(arr[l]==arr[r])return 1;
		return 2;
	}
	if(l==r){
		return 1;
	}
	if(dp[l][r]){
		return dp[l][r];
	}
	dp[l][r] = (int)1e6;
	if(arr[l]==arr[r]){
		dp[l][r] = f(l+1,r-1);
	}
	for(int i = l; i<r; i++){
		dp[l][r] = min(dp[l][r],f(l,i)+f(i+1,r));
	}
	return dp[l][r];
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
	}
	cout << f(1,n) << "\n";
	return 0;
}