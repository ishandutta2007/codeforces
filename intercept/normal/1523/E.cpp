#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int M=2e5+9;
int n,k;
int ans;
int fac[M],inv[M];
int A(int x,int y){
	if(x<=0||y>x)return 0;
	return 1ll*fac[x]*inv[x-y]%mod;
}
int kpow(int x,int y,int rex=1){
	for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*rex*x%mod;
	return rex;
}
void work(){
	scanf("%d%d",&n,&k);
	ans=1;k--;
	for(int i=1;i<=n&&n-(i-1)*(k-1)>=i;++i){
		ans=(ans+1ll*A(n-(i-1)*k,i)*kpow(A(n,i),mod-2)%mod)%mod;
	}
	printf("%d\n",ans);
}
int main(){
	fac[0]=fac[1]=inv[0]=inv[1]=1;
	for(int i=2;i<M;++i){
		fac[i]=1ll*fac[i-1]*i%mod;
		inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	}
	for(int i=2;i<M;++i)inv[i]=1ll*inv[i-1]*inv[i]%mod;
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}
/*
1
4 3
*/