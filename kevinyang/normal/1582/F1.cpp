#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int>arr(n+1);
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
	}
	vector<vector<bool>>dp(512,vector<bool>(512));
	dp[0][0] = true;
	for(int i = 0; i<512; i++){
		dp[i][0] = true;
	}
	vector<bool>ans(512); ans[0] = true;
	for(int i = 1; i<=n; i++){
		int x = arr[i];
		for(int j = 0; j<512; j++){
			if(dp[x][j]){
				for(int k = x+1; k<512; k++){
					if(dp[k][j^x])break;
					dp[k][j^x] = true;
					ans[j^x] = true;
				}
			}
		}
	}
	cout << count(ans.begin(),ans.end(),true) << "\n";
	for(int i = 0; i<512; i++){
		if(ans[i])cout << i << " ";
	}
	cout << "\n";
	return 0;
}