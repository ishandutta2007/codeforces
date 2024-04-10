#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int M=2e5+9;
int kpow(int x,int y,int rex=1){
	for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*rex*x%mod;
	return rex;
}
int n,l[M],r[M],ans=0;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&l[i]);
	for(int i=1;i<=n;++i)scanf("%d",&r[i]);
	for(int i=1;i<=n;++i){
		int d=min(r[i],r[i-1])-max(l[i],l[i-1])+1;
		if(d<0)d=0;
		d=1-1ll*d*kpow(1ll*(r[i]-l[i]+1)*(r[i-1]-l[i-1]+1)%mod,mod-2)%mod;
		ans=(ans+d+mod)%mod;
	}
	ans=1ll*ans*ans%mod;
	for(int i=1;i<=n;++i){
		int d=min(r[i],r[i-1])-max(l[i],l[i-1])+1;
		if(d<0)d=0;
		d=1-1ll*d*kpow(1ll*(r[i]-l[i]+1)*(r[i-1]-l[i-1]+1)%mod,mod-2)%mod;
		ans=(ans-1ll*d*d%mod+d)%mod;
	}
	for(int i=1;i<n;++i){
		int d1=min(r[i],r[i-1])-max(l[i],l[i-1])+1;
		if(d1<0)d1=0;
		d1=1ll*d1*kpow(1ll*(r[i]-l[i]+1)*(r[i-1]-l[i-1]+1)%mod,mod-2)%mod;
		int d2=min(r[i+1],r[i])-max(l[i+1],l[i])+1;
		if(d2<0)d2=0;
		d2=1ll*d2*kpow(1ll*(r[i+1]-l[i+1]+1)*(r[i]-l[i]+1)%mod,mod-2)%mod;
		int d3=min({r[i+1],r[i],r[i-1]})-max({l[i+1],l[i],l[i-1]})+1;
		if(d3<0)d3=0;
		d3=1ll*d3*kpow(1ll*(r[i+1]-l[i+1]+1)*(r[i]-l[i]+1)%mod*(r[i-1]-l[i-1]+1)%mod,mod-2)%mod;
		ans=(ans-2ll*(1-d1)*(1-d2)%mod+2ll*(1-d1-d2+d3))%mod; 
	}
	printf("%d",(ans+mod)%mod);
	return 0;
}