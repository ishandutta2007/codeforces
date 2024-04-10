#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll get(ll l,ll r,ll x,ll y,ll sum)
{
    y=min(y,sum-l);
    x=max(x,sum-r);
    return max(0ll,y-x+1);
}
int main()
{
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll ans=(b-a+1)*(c-b+1)*(d-c+1);
    for(int i=1;i<=b+c;i++)
        ans-=get(a,b,b,c,i)*max(0ll,d-max(c,(ll)i)+1);
    printf("%lld\n",ans);
}