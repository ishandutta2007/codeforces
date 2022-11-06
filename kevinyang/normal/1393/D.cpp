#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	vector<vector<char>>arr(n+10,vector<char>(m+10));
	vector<vector<int>>dp(n+10,vector<int>(m+10));
	for(int i = 2; i<n+2; i++){
		string s;
		cin >> s;
		for(int j = 2; j<m+2; j++){
			arr[i][j] = s[j-2];
		}
	}
	int sum = 0;
	for(int i = 2; i<n+2; i++){
		for(int j = 2; j<m+2; j++){
			if(arr[i][j]==arr[i-1][j]&&arr[i][j]==arr[i-1][j-1]&&arr[i][j]==arr[i-1][j+1]
				&&arr[i][j]==arr[i-2][j]){
				dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j+1],dp[i-2][j]))+1;
			}
			else{
				dp[i][j] = 1;
			}
			sum+=dp[i][j];
		}
	}
	cout << sum << "\n";
	return 0;
}