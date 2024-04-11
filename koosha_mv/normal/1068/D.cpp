#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
const int N=1e5+9,M=203,mod=998244353;
ll dp[2][N][M],n,x;
int main(){
	cin>>n;
	dp[0][0][0]=1;
	f(i,1,201) dp[0][0][i]=dp[0][0][i-1];
	f(i,1,n+1){
		scanf("%I64d",&x);
		f(j,1,201){
			dp[0][i][j]=dp[0][i][j-1],dp[1][i][j]=dp[1][i][j-1];
			if(x==j || x==-1){
				dp[0][i][j]=(dp[0][i][j]+dp[0][i-1][200]-dp[0][i-1][j-1]+dp[1][i-1][j]-dp[1][i-1][j-1]+mod+mod)%mod;
				dp[1][i][j]=(dp[1][i][j]+dp[1][i-1][j-1]+dp[0][i-1][j-1])%mod;
			}
		}
	}
	cout<<dp[0][n][200];
}