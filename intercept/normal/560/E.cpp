#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int mod=1e9+7;
const int M=2e5+9;
int n,m,k;
int fac[M],ans[M];
int kpow(int x,int y,int rex=1){
	for(;y;y>>=1){if(y&1)rex=1ll*rex*x%mod;x=1ll*x*x%mod;}
	return rex;
}
int calc(int a,int b,int c,int d){
	return 1ll*fac[c-a+d-b]*kpow(fac[c-a],mod-2)%mod*kpow(fac[d-b],mod-2)%mod;
}
pii a[M];
int main(){
	fac[0]=1;
	for(int i=1;i<M;++i)fac[i]=1ll*fac[i-1]*i%mod;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;++i){
		scanf("%d%d",&a[i].first,&a[i].second);
	}
	a[++k]=pii(n,m);
	sort(a+1,a+k+1);
	for(int i=1;i<=k;++i){
		int x=a[i].first,y=a[i].second;
		ans[i]=calc(1,1,x,y); 
		for(int j=1;j<i;++j){
			int l=a[j].first,r=a[j].second;
			if(l<=x&&r<=y)ans[i]=(ans[i]-1ll*ans[j]*calc(l,r,x,y)%mod+mod)%mod;
		}
	}
	printf("%d\n",ans[k]);
	return 0;
}