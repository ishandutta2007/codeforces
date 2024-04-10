#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,m,k;
int dp[409][209],c[409],ans[209];
int kpow(int x,int y,int rex=1){
	for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*x*rex%mod;
	return rex;
}
int main(){
    scanf("%d%d",&n,&k);
    m=min(n,2*k);
    for(int i=0;i<=k;i+=2)dp[0][i]=1;
    c[0]=1;
    for(int i=1;i<=m;++i)c[i]=1ll*c[i-1]*(n-i+1)%mod*kpow(i,mod-2)%mod;
    for(int i=2;i<=m;++i)
    	for(int j=1;j<=k;++j)dp[i][j]=1ll*(dp[i-1][j-1]+dp[i-2][j-1])*(i-1)%mod;
	for(int i=1;i<=k;++i){
		for(int j=0;j<=m;++j)
			(ans[i]+=1ll*dp[j][i]*c[j]%mod)%=mod;
		printf("%d ",ans[i]);
	}
    return 0;
}