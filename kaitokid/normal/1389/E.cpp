#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll go(ll a)
{
    return a*(a-1)/2;
}
int main()
{

    ios::sync_with_stdio(0);
    ll t,n,k,l1,l2,r1,r2;
    cin>>t;
    while(t--)
    {
        ll m,d,w;
    cin>>m>>d>>w;
    m=min(m,d);
    if(d==1){cout<<0<<endl;continue;}
    d--;
    ll v=(d*w)/__gcd(d,w);
    v=v/d;
    ll r=m/v;
    ll ans=(v-m%v)*go(m/v)+(m%v)*go(m/v+1);
    cout<<ans<<endl;

    }
    return 0;
}