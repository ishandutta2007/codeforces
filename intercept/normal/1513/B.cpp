#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int M=2e5+9;
int n;
int a[M],fac[M];
int kpow(int x,int y,int rex=1){
	for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*x*rex%mod;
	return rex;
}
int calc(int x,int y){
	if(x<y)return 0;
	return 1ll*fac[x]*kpow(fac[y],mod-2)%mod*kpow(fac[x-y],mod-2)%mod;
}
void work(){
	int x=(1ll<<31)-1,cnt=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		x&=a[i];
	}
	for(int i=1;i<=n;++i)cnt+=a[i]==x;
	int ans=2ll*calc(cnt,2)*fac[n-2]%mod;
	printf("%d\n",ans);
}
int main(){
	fac[0]=1;
	for(int i=1;i<M;++i)fac[i]=1ll*fac[i-1]*i%mod;
	int T;
	scanf("%d\n",&T);
	while(T--)work();
	return 0;
}