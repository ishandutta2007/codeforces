#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
vector<vector<vector<int>>>dp(201,vector<vector<int>>(201,vector<int>(201)));
string s,t;
/*
int f(int a, int b, int c){//max ans for first a chars, b changes, and c chars equal to t[0]
	if(a==1||c==0)return 0;
	if(dp[a][b][c]>=0)return dp[a][b][c];
	int ret = 0;
	if(s[a-1] == t[1])ret = max(ret,f(a-1,b,c)+c);
	else if(s[a-1] == t[0])ret = max(ret,f(a-1,b,c-1));
	else ret = max(ret,f(a-1,b,c));
	if(s[a-1]!=t[0]&&b>0)ret = max(ret,f(a,b-1,c-1));
	if(s[a-1]!=t[1]&&b>0)ret = max(ret,f(a,b-1,c)+c);
	dp[a][b][c] = ret;
	return ret;
}
*/
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> k;
	cin >> s;
	cin >> t;
	for(int i = 0; i<=200; i++){
		for(int j = 0; j<=200; j++){
			for(int k = 0; k<=200; k++){
				dp[i][j][k] = -1;
			}
		}
	}
	dp[0][0][0] = 0;
	int ans = 0;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<=k; j++){
			for(int l = 0; l<=n; l++){
				if(dp[i][j][l]==-1)continue;
				int e0 = s[i]==t[0];
				int e1 = s[i]==t[1];
				int e2 = t[0]==t[1];
				dp[i+1][j][l+e0] = max(dp[i+1][j][l+e0],dp[i][j][l]+(e1?l:0));
				if(j<k){
					dp[i+1][j+1][l+1] = max(dp[i+1][j+1][l+1],dp[i][j][l]+(e2?l:0));
					dp[i+1][j+1][l+e2] = max(dp[i+1][j+1][l+e2],dp[i][j][l]+l);
				}
			}
		}
	}

	for(int i = 0; i<=k; i++){
		for(int j = 0; j<=n; j++){
			ans = max(ans,dp[n][i][j]);
		}
	}
	cout << ans << "\n";
	return 0;
}