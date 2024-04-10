#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
ll cal(ll x)
{
    ll tot=1,ans=0;
    while(x*2<=n)
    {
        ans+=tot;
        x*=2;tot*=2;
    }
    ans+=min(tot,n-x+1);
    return ans;
}
int main()
{
    scanf("%lld%lld",&n,&k);
    ll l=1,r=n/2,ans=1;
    while(l<=r)
    {
        ll m=l+r>>1;
        if(cal(m)-1>=k) ans=max(ans,m*2),l=m+1;
        else r=m-1;
    }
    l=0,r=(n-1)/2;
    while(l<=r)
    {
        ll m=l+r>>1;
        if(cal(m*2+1)>=k) ans=max(ans,m*2+1),l=m+1;
        else r=m-1;
    }
    printf("%lld\n",ans);
}