#include <bits/stdc++.h>
using namespace std;
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	vector<vector<char>>arr(n+1,vector<char>(m+1));
	vector<vector<int>>dp(n+1,vector<int>(m+1));
	for(int i = 1; i<=n; i++){
		string s;
		cin >> s;
		for(int j = 1; j<=m; j++){
			arr[i][j] = s[j-1];
			if(arr[i][j]=='X'){
				if(arr[i-1][j]=='X'&&arr[i-1][j-1]=='X'&&arr[i][j-1]=='X'){
					dp[i][j] = min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]})+1;
				}
				dp[i][j] = max(dp[i][j],1);
			}
		}
	}
	int low = 0;
	int high = min(n,m)/2;
	int mid2 = (low+high+1)/2;
	while(low<high){
		int mid = mid2*2+1;
		vector<vector<int>>dif(2*n+1,vector<int>(2*m+1));
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=m; j++){
				if(dp[i][j]>=mid){
					dif[i-mid+1][j-mid+1]++;
					dif[i-mid+1][j+1]--;
					dif[i+1][j-mid+1]--;
					dif[i+1][j+1]++;
				}
			}
		}
		vector<vector<int>>psa(n+1,vector<int>(m+1));
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=m; j++){
				psa[i][j] = psa[i-1][j]+psa[i][j-1]-psa[i-1][j-1]+dif[i][j];
			}
		}
		bool f = true;
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=m; j++){
				if(arr[i][j] == 'X'&&psa[i][j]==0){
					f = false;
				}
			}
		}
		if(f){
			low = mid2;
		}
		else{
			high = mid2-1;
		}
		mid2 = (low+high+1)/2;
		//cerr << mid2 << " " << low << " " << high << "\n";
	}
	cout << mid2 << "\n";
	vector<vector<char>>ans(n+1,vector<char>(m+1));
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			if(dp[i][j]>=2*mid2+1){
				ans[i-mid2][j-mid2] = 'X';
			}
		}
	}
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			if(ans[i][j]!='X')ans[i][j] = '.';
			cout << ans[i][j];
		}
		cout << "\n";
	}
	return 0;
}