#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll a,b,c,d,e,f;
    scanf("%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e,&f);
    int t=min(a,d);
    ll ans=0;
    for(int i=0;i<=t;i++)
        ans=max(ans,i*e+min(min(b,c),d-i)*f);
    cout<<ans;
}