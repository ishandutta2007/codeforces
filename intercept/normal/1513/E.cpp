#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
const int M=1e5+9;
int n,cnt1,cnt2,cnt3,d=0;
int a[M],fac[M];
ll sum=0,ans=1;
int kpow(int x,int y,int rex=1){
	for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*x*rex%mod;
	return rex;
}
int calc(int x,int y){
	if(x<y)return 0;
	return 1ll*fac[x]*kpow(fac[y],mod-2)%mod*kpow(fac[x-y],mod-2)%mod;
}
int main(){
	fac[0]=1;
	for(int i=1;i<M;++i)fac[i]=1ll*fac[i-1]*i%mod;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),sum+=a[i];
	if(sum%n){
		printf("0\n");
		return 0;
	}
	sum/=n;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		if(a[i]<sum)cnt1++;
		if(a[i]==sum)cnt2++;
		if(a[i]>sum)cnt3++;
		if(a[i]==a[i-1]||i==1)d++;
		if(a[i]!=a[i-1]||i==n)ans=ans*kpow(fac[d],mod-2)%mod,d=1;
	}
	ans=ans*calc(n,cnt2)%mod;
	ans=ans*fac[cnt1]%mod*fac[cnt3]%mod*fac[cnt2]%mod;
	n-=cnt2;
	if(cnt1==1||cnt3==1)ans=ans*n%mod;
	else if(cnt1||cnt3)ans=ans*2%mod; 
	printf("%lld\n",ans);
	return 0;
}