#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		vector<vector<int>>arr(n,vector<int>(m+1));
		for(int i = 0; i<n; i++){
			for(int j = 1; j<=m; j++){
				cin >> arr[i][j];
			}
		}
		vector<vector<int>>dp(1<<n,vector<int>(m+1));
		for(int a = 1; a<=m; a++){
			for(int d = 0; d<n; d++){
				int temp = arr[n-1][a];
				for(int i = n-1; i>0; i--){
					arr[i][a] = arr[i-1][a];
				}
				arr[0][a] = temp;
				for(int i = 0; i<(1<<n); i++){
					for(int j = 0; j<(1<<n); j++){
						if((i&j)>0)continue;
						int v = 0;
						for(int k = 0; k<n; k++){
							if(j&(1<<k)){
								v+=arr[k][a];
							}
						}
						dp[i^j][a] = max(dp[i^j][a],v+dp[i][a-1]);
					}
				}
			}
		}
		cout << dp[(1<<n)-1][m] << "\n";
	}
	return 0;
}