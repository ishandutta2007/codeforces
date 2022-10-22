#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
const int N=1005,mod=1e9+7;
ll n,k,dp[5][N][N],s;
// 0: akhari tanha  1;2 taye akhar to yeki 2:2 taye akhar kenare ham 3:gheire 4:hame
int main(){
	Get(n,k);
	dp[0][1][0]=1;
	dp[4][1][0]=1;
	f(i,2,n+1){
		f(j,0,n+1){
			dp[0][i][j]=dp[4][i-1][j];
			if(j>1) dp[1][i][j]=dp[0][i-1][j-2];
			dp[2][i][j]=(dp[1][i-1][j]*2+dp[2][i-1][j])%mod;
			if(j>0) dp[2][i][j]+=dp[2][i-1][j-1]+dp[3][i-1][j-1]*2,dp[2][i][j]%=mod;
			dp[3][i][j]=(dp[0][i-1][j]*max(i-2-j,s)+dp[0][i-1][j+1]*(j+1)+dp[1][i-1][j+1]*max(j-1,s)+dp[1][i-1][j]*max(i-1-j,s));
			dp[3][i][j]%=mod;
			dp[3][i][j]+=dp[2][i-1][j]*max(i-1-j-1,s)+dp[2][i-1][j+1]*j+dp[3][i-1][j+1]*(j+1)+dp[3][i-1][j]*max(i-j-3,s);
			dp[3][i][j]%=mod;
			dp[4][i][j]=(dp[0][i][j]+dp[1][i][j]+dp[2][i][j]+dp[3][i][j])%mod;
		}
	}
	cout<<dp[4][n][k];
}