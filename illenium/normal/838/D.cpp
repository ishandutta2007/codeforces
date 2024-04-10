#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

inline ll qmod(ll a,ll b)
{
    ll res = 1;
    while(b)
    {
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
 
int main()
{
	ll n,m;
    scanf("%lld %lld",&n,&m);
    ll ans=qmod(2,m)*qmod(n+1,m-1)%mod*(n-m+1)%mod;
    printf("%lld\n",ans%mod);
    return 0;
}