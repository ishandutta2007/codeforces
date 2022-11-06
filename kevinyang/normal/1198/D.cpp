#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[51][51][51][51];
bool vis[51][51][51][51];
vector<vector<char>>mp(51,vector<char>(51));
int f(int a, int b, int c, int d){
	if(vis[a][b][c][d])return dp[a][b][c][d];
	vis[a][b][c][d] = true;
	if(a==b&&c==d){
		if(mp[a][c]=='#'){
			return dp[a][b][c][d] = 1;
		}
		else{
			return dp[a][b][c][d] = 0;
		}
	}
	dp[a][b][c][d] = max(b-a+1,d-c+1);
	for(int i = a; i<b; i++){
		dp[a][b][c][d] = min(dp[a][b][c][d],f(a,i,c,d)+f(i+1,b,c,d));
	}
	for(int i = c; i<d; i++){
		dp[a][b][c][d] = min(dp[a][b][c][d],f(a,b,c,i)+f(a,b,i+1,d));
	}
	return dp[a][b][c][d];
}
int n;
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	memset(dp,(int)1e9,sizeof(dp));
	memset(vis,0,sizeof(vis));
	cin >> n;
	for(int i = 1; i<=n; i++){
		string s;
		cin >> s;
		for(int j = 1; j<=n; j++){
			mp[i][j] = s[j-1];
		}
	}
	cout << f(1,n,1,n) << "\n";
	return 0;
}