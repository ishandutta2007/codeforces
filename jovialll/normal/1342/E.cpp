#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353
#define N 500005
ll n,k,ans,jc[N],i,ny[N],c,tmp;
inline ll ksm(ll x,ll y){
	ll ret=1;
	while(y){
		if(y&1)ret=ret*x%mod;
		x=x*x%mod,y>>=1;
	}
	return ret;
}
inline ll C(ll x,ll y){
	return jc[x]*ny[y]%mod*ny[x-y]%mod;
}
int main(){
	cin>>n>>k;
	if(k>=n)cout<<0;
	else{
		jc[0]=ny[0]=1;
		for(i=1;i<=n;++i){
			jc[i]=jc[i-1]*i%mod;
			ny[i]=ksm(jc[i],mod-2);
		}
		if(k==0){
			cout<<jc[n];
		}
		else{
			c=n-k;tmp=1;
			for(i=c;i;--i){
				ans+=ksm(i,n)*C(c,i)*tmp%mod;
				tmp=-tmp;
			}ans%=mod;
			cout<<(2ll*C(n,k)%mod*ans%mod+mod)%mod;
		}
	}
	return 0;
}