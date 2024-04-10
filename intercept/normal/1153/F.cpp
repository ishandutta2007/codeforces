#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int mod=998244353;
const int M=4009;
int n,k,l;
int ans=0;
int f[M][M];
int fac[M];
int kpow(int x,int y,int rex=1){
	for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*rex*x%mod;
	return rex;
}
int main(){
	scanf("%d%d%d",&n,&k,&l);
	f[0][0]=1;
	fac[0]=1;
	for(int i=1;i<=n+n;++i){
		fac[i]=1ll*fac[i-1]*i%mod;
		for(int j=0;j<=i;++j){
			if(j)f[i][j]=f[i-1][j-1];
			f[i][j]=(f[i][j]+1ll*f[i-1][j+1]*(j+1)%mod)%mod;
		}
	}
	for(int i=1;i<n+n;++i){
		for(int j=k;j<=i;++j){
			ans=(ans+1ll*f[i][j]*f[n+n-i][j]%mod*fac[j]%mod)%mod;
		}
	}
	ans=1ll*ans*kpow(n+n+1,mod-2)%mod*kpow(f[n+n][0],mod-2)%mod*l%mod;
	printf("%d\n",ans);
	return 0;
}
/*
8 10
1 3 2 7 8 2 5 4 6 1
*/