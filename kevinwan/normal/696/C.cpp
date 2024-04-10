#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int mn=1e5+10;
ll k[mn];
inline ll po(ll a,ll b=mod-2){
    ll ans=1;
    for(;b;b>>=1,a=a*a%mod)if(b&1)ans=ans*a%mod;
    return ans;
}
int main()
{
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%lld",k+i);
    ll imp=2;
    for(i=0;i<n;i++)imp=po(imp,k[i]);
    ll himp=imp*po(2)%mod;
    ll sgn=-1;
    for(i=0;i<n;i++)if(k[i]%2==0)sgn=1;
    sgn*=-1;
    ll num=(himp-(imp+sgn)*po(3))%mod;
    if(num<0)num+=mod;
    ll dem=himp;
    printf("%lld/%lld",num,dem);
}