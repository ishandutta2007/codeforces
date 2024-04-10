#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll rv(ll x)
{
    ll ans=0;
    while(x>0)
    {
        ans*=2;
        ans+=(x%2);
        x/=2;
    }
    return ans;
}
bool go(ll x,ll y)
{
    if(x==y)return true;
    while(x<y)
    {
        x=2*x+1;
        if(x==y)return true;
    }
    return false;
}
bool ch(ll x,ll y)
{
if(x>y)return false;
if(x==y)return true;
ll d=-1;
for(ll i=0;i<=63;i++)if(x&(1LL<<i))d=i;
for(ll j=d;j<=63;j++)
{
    x|=(1LL<<j);
    if(x>y)break;
    if(go(x,y))return true;
}
return false;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
        ll x,y;
        cin>>x>>y;
        if(x==y){cout<<"YES";return 0;}
        ll p=2*x+1;
        if(ch(p,y)){cout<<"YES";return 0;}
        p=rv(p);
        if(ch(p,y)){cout<<"YES";return 0;}
        while(x%2==0)x/=2;
        if(ch(x,y)){cout<<"YES";return 0;}
        x=rv(x);
        if(ch(x,y)){cout<<"YES";return 0;}
    cout<<"NO";
    return 0;
}