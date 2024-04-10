#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int M=5009;
int n;
int kpow(int x,int y,int rex=1){
	for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*rex*x%mod;
	return rex;
}
int fac[M],a[M],b[M],dp[M][M],s[M][M];
void work(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)b[i]=0;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),b[a[i]]++;
	for(int i=1;i<=n;++i)b[i]+=b[i-1];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		dp[i][1]=1ll*b[i-1]*(b[i]-b[i-1])%mod;
		s[i][1]=s[i-1][1];
		if(b[i-1]>=1)s[i][1]=(s[i][1]+1ll*dp[i][1]*(b[i-1]-1)%mod)%mod;
	}
	for(int i=1;i<=n;++i){
		for(int j=2;j<=n/2;++j){
			if(b[i-1]>=j*2-1&&b[i]-b[i-1]>0)dp[i][j]=1ll*s[i-1][j-1]*(b[i]-b[i-1])%mod;
			else dp[i][j]=0;
			s[i][j]=s[i-1][j];
			if(b[i-1]-j*2+1>=0)s[i][j]=(s[i][j]+1ll*dp[i][j]*(b[i-1]-(j*2-1))%mod)%mod;
		}
	}
	int s=1;
	fac[0]=1;
	for(int i=1;i<=n;++i)fac[i]=1ll*i*fac[i-1]%mod;
	for(int i=1;i<=n;++i){
		s=1ll*s*kpow(fac[b[i]-b[i-1]],mod-2)%mod;
	}
	s=1ll*s*dp[a[n]][n/2]%mod;
	printf("%d\n",s);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}