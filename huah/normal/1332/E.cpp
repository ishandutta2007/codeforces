#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
ll n,m,l,r;
ll qpow(ll a,ll n)
{
    ll ans=1;
    while(n)
    {
        if(n&1) ans=ans*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return ans;
}
int main()
{
    scanf("%lld%lld%lld%lld",&n,&m,&l,&r);
    if((n&1)&&(m&1)) printf("%lld\n",qpow((r-l+1)%mod,n*m));
    else
    {
        if((r-l+1)&1)
        {
            ll ans=qpow((r-l+1)%mod,n*m);
            ans=((ans-1)%mod+mod)%mod;
            ans=ans*qpow(2,mod-2)%mod;
            printf("%lld\n",(ans+1)%mod);
        }
        else
        {
            ll A=(r-l+1)>>1;
            printf("%lld\n",qpow(A,n*m)*qpow(2,n*m-1)%mod);
        }
    }
}