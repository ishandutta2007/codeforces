#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
#define ll long long
using namespace std;
const int M=2e5+9;
int n;
char s[2][M];
int dp[2][M];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<2;++i)cin>>(s[i]+1);
	memset(dp,0X3f,sizeof(dp));
	dp[0][1]=0;
	int ans=0;
	for(int i=1;i<=n;++i){
		for(int j=0;j<2;++j){
			if(s[j][i]=='1')ans++;
			if(s[j^1][i]=='1'&&s[j][i+1]=='1'){
				dp[j^1][i+2]=min(dp[j^1][i+2],dp[j][i]+1);
				dp[j][i+1]=min(dp[j][i+1],dp[j][i]+1);
			}
			else{
				if(s[j^1][i]=='1'){
					dp[j^1][i+1]=min(dp[j^1][i+1],dp[j][i]);
					dp[j][i+1]=min(dp[j][i+1],dp[j][i]+1);
				}
				else dp[j][i+1]=min(dp[j][i+1],dp[j][i]);
			}
		}
	}
	cout<<ans-min(dp[0][n+1],dp[1][n+1])<<"\n";
	return 0;
}
/*
1
5 2
1 1 2 2



1000000000
0010000000
0010000000
0000001000
0001000000
0100000000
0000010000
0000000010
*/