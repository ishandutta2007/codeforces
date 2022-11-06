#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
const int mod = (int)1e9+7;
int n,m;
vector<vector<int>>dp(505,vector<int>(505));
vector<vector<int>>dp2(505,vector<int>(505));
bool good(int x, int y){
	return (x>=1&&x<=n&&y>=1&&y<=m);
}
int check(int i, int j, int x, int y){
	if(good(i,j)&&good(x,y))return dp[i][x];
	return 0;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m;
	vector<vector<char>>arr(n+1,vector<char>(m+1));
	for(int i = 1; i<=n; i++){
		string s;
		cin >> s;
		for(int j = 1; j<=m; j++){
			arr[i][j] = s[j-1];
		}
	}
	if((n+m)%2==1){
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=m; j++){
				if(i+j==(n+m)/2+1){
					if(good(i+1,j)&&arr[i][j]==arr[i+1][j]){
						dp[i][i+1] = 1;
					}
					if(good(i,j+1)&&arr[i][j]==arr[i][j+1]){
						dp[i][i] = 1;
					}
				}
			}
		}	
	}
	else{
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=m; j++){
				if(i+j==(n+m)/2+1){
					dp[i][i] = 1;
				}
			}
		}
	}
	vector<vector<pair<int,int>>>inds(n+m+1);
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=m; j++){
				inds[i+j].push_back({i,j});
			}
		}
		for(int d = (n+m)/2; d>=2; d--){
			for(pair<int,int>p: inds[d]){
				int i = p.first; int j = p.second;
				for(pair<int,int>p2: inds[n+m+2-d]){
					int x = p2.first; int y = p2.second;
					if(arr[i][j]!=arr[x][y])continue;
					dp2[i][x]+=check(i+1,j,x-1,y); dp2[i][x]%=mod;
					dp2[i][x]+=check(i,j+1,x-1,y); dp2[i][x]%=mod;
					dp2[i][x]+=check(i+1,j,x,y-1); dp2[i][x]%=mod;
					dp2[i][x]+=check(i,j+1,x,y-1); dp2[i][x]%=mod;
					//cout << i << " " << j << " " << x << " " << y << " " << dp2[i][x] << "\n";
				}
			}
			for(int i = 1; i<=500; i++){
				for(int j = 1; j<=500; j++){
					dp[i][j] = dp2[i][j];
					dp2[i][j] = 0;
				}
			}
		}
	cout << dp[1][n] << "\n";
	return 0;
}