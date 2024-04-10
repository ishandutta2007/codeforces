#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
using namespace std;
const int M=1000009;
const int mod=1e9+7;
int kpow(int x,int y,int rex=1){
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*rex*x%mod;
    return rex;
}
int n,inv2=kpow(2,mod-2);
int d[M];
int calc(ll l,ll r){
	ll x=r-l+1,y=l+r;
	x%=mod;
	y%=mod;
	return y*x%mod*inv2%mod;
}
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
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	pre();
	cin>>n;
	ll sum=0;
	for(int i=1;i<=n;++i){
		int x;
		cin>>x;
		d[(x&1)^1]++;
		d[x+1]--;
		sum+=x;
	}
	for(int i=2;i<M;++i)d[i]=d[i]+d[i-2];
	ll l=1,r=sum;
	ll ans1=0,ans2=1;
	for(int i=M-1;i>=0;--i){
		ans1=(ans1+1ll*calc(r-d[i]+1,r)*i%mod-1ll*calc(l,l+d[i]-1)*i%mod)%mod;
		ans2=1ll*ans2*fac[d[i]]%mod;
		if(i)ans2=1ll*ans2*fac[d[i]]%mod;
		l+=d[i];
		r-=d[i];
	}
	cout<<(ans1%mod+mod)%mod<<" "<<ans2<<"\n";
	return 0;
}