#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[20];
const ll mod=1e9+7;
inline ll inv(ll x){
    ll ans=1;
    for(ll i=mod-2;i;i>>=1,x=x*x%mod)if(i&1)ans=ans*x%mod;
    return ans;
}
ll invf=1,n;
ll hail(ll x){
    if(x<0)return 0;
    ll ans=invf;
    for(ll i=1;i<n;i++)ans=ans*((x+i)%mod)%mod;
    return ans;
}
int main()
{
    ll s,i,j;
    scanf("%lld%lld",&n,&s);
    for(i=0;i<n;i++)scanf("%lld",f+i),f[i]++;
    for(i=1;i<n;i++)invf=invf*i%mod;
    invf=inv(invf);
    ll ans=0;
    for(i=0;i<1<<n;i++){
        ll sum=0;
        for(j=0;j<n;j++){
            if((i>>j)&1)sum+=f[j];
        }
        ll d=hail(s-sum);
        if(__builtin_popcount(i)&1)ans-=d;
        else ans+=d;
        ans%=mod;
    }
    if(ans<0)ans+=mod;
    printf("%lld",ans);
}