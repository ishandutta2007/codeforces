#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int M=2e5+9;
int n,k;
int a[M];
int inv[M],fac[M];
int c(int x,int y){
    if(x<y||y<0)return 0;
    return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}
void pre(){
    fac[0]=fac[1]=inv[0]=inv[1]=1;
    for(int i=2;i<M;++i){
        fac[i]=1ll*fac[i-1]*i%mod;
        inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
    }
    for(int i=2;i<M;++i)inv[i]=1ll*inv[i]*inv[i-1]%mod;
}
int kpow(int x,int y,int rex=1){
	for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*rex*x%mod;
	return rex;
}
int main(){
	pre();
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	int t=0,p=1,ans=0;
	for(int i=1;i<=n;++i){
		if(a[i]==a[i%n+1])p=1ll*p*k%mod;
		else t++;
	}
	for(int i=0,j=1;i<=t;++i,j=1ll*j*(k-2)%mod){
		int x=t-i;
		if(x&1)continue;
		ans=(ans+1ll*c(x,x/2)*j%mod*c(t,i))%mod;
	}
	ans=1ll*(1ll*kpow(k,n)+mod-1ll*ans*p%mod)*kpow(2,mod-2)%mod;
	cout<<ans<<endl;
	return 0;
}