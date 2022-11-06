#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
bool good(int a, int b){
	if(a>=1&&a<=n&&b>=1&&b<=m)return 1;
	return 0;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m >> k;
	if(k%2==1){
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=m; j++){
				cout << "-1 ";
			}
			cout << "\n";
		}
		return 0;
	}
	k/=2;
	vector<vector<int>>hedge(n+1,vector<int>(m+1));
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<m; j++){
			cin >> hedge[i][j];
		}
	}
	vector<vector<int>>vedge(n+1,vector<int>(m+1));
	for(int i = 1; i<n; i++){
		for(int j = 1; j<=m; j++){
			cin >> vedge[i][j];
		}
	}
	vector<vector<int>>dp(n+1,vector<int>(m+1));
	vector<vector<int>>dp2(n+1,vector<int>(m+1,(int)1e18));
	vector<int>dx = {-1,0,1,0};
	vector<int>dy = {0,1,0,-1};
	while(k--){
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=m; j++){
				for(int d = 0; d<4; d++){
					int x = i+dx[d]; int y = j+dy[d];
					if(good(x,y)){
						if(dx[d]==0){
							dp2[x][y] = min(dp2[x][y],dp[i][j]+hedge[x][min(y,j)]);
						}
						else{
							dp2[x][y] = min(dp2[x][y],dp[i][j]+vedge[min(x,i)][y]);
						}
					}
				}
			}
		}
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=m; j++){
				dp[i][j] = dp2[i][j]; dp2[i][j] = (int)1e18;
			}
		}
	}
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			cout << dp[i][j]*2 << " ";
		}
		cout << "\n";
	}
	return 0;
}