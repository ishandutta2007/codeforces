#include <bits/stdc++.h>
using namespace std;
#define ll long long

// x*b + a*(d-x) + t*((d-x-1)/k)
// d-x - 1 = k*y + r, 0<=r<k
//b*(d- 1-k*y-r) +a*(k*y+r+1) + t*y
// (ak+t-bk)*y + b*d + (a-b)*r + a- b
int main()
{
    ll d,k,a,b,t;
    cin>>d>>k>>a>>b>>t;
    if(d == 1)
    {
        cout<<a;
        return 0;
    }
    ll x = a*k+t-b*k;
    if(x >= 0)
    {
        ll r = min(k-1,d-1);
        cout<<b*d+(a-b)*r+ a- b << endl;
    }
    else
    {
        ll ans = 1e18;
        for(int r = 0;r<k&&r<=d-1;r++)
        {
            ll y = (d-r-1)/k;
            ans = min(ans,x*y+b*d+(a-b)*r+a-b);
        }
        cout<<ans;
    }
}