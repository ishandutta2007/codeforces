#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k,Mod,dp[110][110][110],C[110][110],fac[110];
ll solve(int n,int k,int m){
	if (m<0||m>n) return (k==0)*fac[n];
	if (k<0||k>n) return 0;
	if (n==1) return (m==1&&k==1||m!=1&&k==0);
	if (~dp[n][k][m]) return dp[n][k][m];
	ll res=solve(n-1,k-(m==1),m-1)*2%Mod;
	for (int i=2;i<n;i++)
		for (int j=0;j<=k-(m==1);j++){
			ll x=solve(i-1,j,m-1),y=solve(n-i,k-(m==1)-j,m-1);
			if (!x||!y) continue;
			res=(res+x*y%Mod*C[n-1][i-1])%Mod;
		}
	dp[n][k][m]=res; return res;
}
int main(){
	memset(dp,-1,sizeof(dp));
	cin>>n>>m>>k>>Mod;
	for (int i=0;i<=n;i++){
		C[i][0]=1; if (i) fac[i]=1ll*fac[i-1]*i%Mod; else fac[i]=1;
		for (int j=1;j<=i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%Mod;
	}
	cout<<solve(n,k,m)<<endl;
	return 0;
}