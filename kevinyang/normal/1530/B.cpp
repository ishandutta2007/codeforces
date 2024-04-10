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
		vector<vector<int>>ans(n+2,vector<int>(m+2));
		ans[1][1] = 1; ans[n][1] = 1;
		ans[1][m] = 1;
		ans[n][m] = 1;
		vector<int>dx = {-1,-1,0,1,1,1,0,-1};
		vector<int>dy = {0,1,1,1,0,-1,-1,-1};
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=m; j++){
				if(i==1||j==1||i==n||j==m){
					if(ans[i][j]==1)continue;
					bool f = false;
					for(int d = 0; d<8; d++){
						if(ans[i+dx[d]][j+dy[d]]==1)f = true;
					}
					if(!f){
						ans[i][j] = 1;
					}
				}
			}
		}
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=m; j++){
				cout << ans[i][j];
			}
			cout << "\n";
		}
	}
	return 0;
}