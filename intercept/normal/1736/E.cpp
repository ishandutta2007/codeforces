#include<bits/stdc++.h>
#define pii pair<int,int>
#define ll long long
#define fi first
#define se second
#define eb emplace_back
using namespace std;
const int M=509;
int n;
int a[M],dp[M][M][2];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=0;i<=n;++i){
		for(int j=0;j<=n;++j)dp[i][j][0]=dp[i][j][1]=-2e9;
	}
	dp[0][0][0]=0;
	for(int i=0;i<n;++i){
		for(int j=i+1;j<=n;++j){
			for(int k=0;k<=n;++k){
				int x=k-(j-i-1)+1;
				if(x>=0&&x<=n)dp[j][x][0]=max(dp[j][x][0],max(dp[i][k][0],(j!=i+1)?dp[i][k][1]:(int)-2e9)+a[j]*(j-i));
				if(x>=0&&x<=n&&j>i+1)dp[j-1][x][1]=max(dp[j-1][x][1],max(dp[i][k][1],dp[i][k][0])+a[j]*(j-1-i));
				dp[j][k][0]=max(dp[j][k][0],dp[i][k][0]+a[i]*(j-i));
			}
		}
	}
	int ans=0;
	for(int i=0;i<=n;++i)ans=max(ans,dp[n][i][0]);
	cout<<ans<<"\n";
	return 0;
}