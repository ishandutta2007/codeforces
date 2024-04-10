#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=1e9+7;
bool pr[1000009];
ll lcm(ll x,ll y)
{
    ll g=__gcd(x,y);
    x/=g;
    return x*y;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

int t;
cin>>t;

while(t--)
{
    ll n;
    cin>>n;
    ll ans=(2*n)%mod;
    ll x=1;
    for(int i=2;i<10000000;i++)
    {
        ll d=lcm(x,i);
        if(d>n)break;
        ans+=(n/d)%mod;
        ans%=mod;
        x=d;
    }
    cout<<ans<<endl;
}
    return 0;
}