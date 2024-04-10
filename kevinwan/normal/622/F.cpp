//Oshvleiki Svlaiyoska Ranasku sachi
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=1e6+10;
const ll mod=1e9+7;
ll po(ll a,ll b=mod-2){
    ll ans=1;
    for(;b;b>>=1,a*=a,a%=mod)if(b&1)ans*=a,ans%=mod;
    return ans;
}
ll p[mn],fact[mn],nfact[mn];
int main(){
    ll n,k;
    scanf("%lld%lld",&n,&k);
    fact[0]=nfact[0]=1;
    for(int i=1;i<=k+1;i++)p[i]=(p[i-1]+po(i,k))%mod;
    if(n<=k+1){
        printf("%lld",p[n]);
        return 0;
    }
    for(int i=1;i<=k+1;i++)fact[i]=fact[i-1]*i%mod,nfact[i]=nfact[i-1]*(-i)%mod;
    ll ans=0,num=1;
    for(int j=0;j<=k+1;j++)num*=n-j,num%=mod;
    for(int i=0;i<=k+1;i++){
        ans+=num*po((n-i)*nfact[k+1-i]%mod*fact[i]%mod)%mod*p[i]%mod,ans%=mod;
    }
    if(ans<0)ans+=mod;
    printf("%lld",ans);
}