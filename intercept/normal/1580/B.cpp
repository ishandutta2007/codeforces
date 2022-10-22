#include<bits/stdc++.h>
using namespace std;
int p;
int dp[109][109][109],c[109][109],f[109],P[109];
int dfs(int n,int m,int k){
	if(n==0)return k==0;
	if(m==1)return k==1?f[n]:0;
	if(n==1)return k==0;
	if(n+1<m+k&&k)return 0;
	if(k>(n+1)/2)return 0;
	if(m<30&&k>P[m])return 0;
	if(~dp[n][m][k])return dp[n][m][k];
	int ans=0;
	for(int i=0;i<n;++i)
		for(int j=0;j<=k;++j)
			ans=(ans+1ll*dfs(i,m-1,j)*dfs(n-i-1,m-1,k-j)%p*c[n-1][i]%p)%p;
	return dp[n][m][k]=ans;
}
int main(){
	memset(dp,-1,sizeof(dp));
	int n,m,k;
	scanf("%d%d%d%d",&n,&m,&k,&p);
	f[0]=P[0]=1;
	for(int i=1;i<=30;++i)P[i]=P[i-1]*2;
	for(int i=1;i<=n;++i)f[i]=1ll*f[i-1]*i%p;
	for(int i=0;i<=n;++i){
		c[i][0]=c[i][i]=1;
		for(int j=1;j<i;++j)c[i][j]=(c[i-1][j]+c[i-1][j-1])%p;
	}
	printf("%d\n",dfs(n,m,k));
	return 0;
}