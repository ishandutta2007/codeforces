#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>>dp(2005,vector<int>(2005));
int n;
vector<int>arr(2005);
vector<vector<int>>mx(2005,vector<int>(2005));
vector<vector<int>>mn(2005,vector<int>(2005));
int f(int l, int r){
	if(l==r)return 0;
	if(mx[l][r]-mn[l][r]==0)return 0;
	if(dp[l][r])return dp[l][r];
	return dp[l][r] = min(f(l+1,r),f(l,r-1))+mx[l][r]-mn[l][r];
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
	}
	sort(arr.begin()+1,arr.begin()+n+1);
	for(int i = 1; i<=n; i++){
		mx[i][i] = arr[i]; mn[i][i] = arr[i];
		for(int j = i+1; j<=n; j++){
			mx[i][j] = max(mx[i][j-1],arr[j]);
			mn[i][j] = min(mn[i][j-1],arr[j]);
		}
	}
	cout << f(1,n) << "\n";
	return 0;
}