#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ch(ll x)
{
    ll a=x/3,b=x/3,c=x/3;
    x%=3;
    if(x>0)a++;
    if(x>1)b++;
    return 2*(a*b + b*c +a*c);
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
        ll l=1,r=100000;
        while(l<r)
        {
            ll mid=(l+r)/2;
            if(ch(mid)<n)l=mid+1;
            else r=mid;
        }
        cout<<l<<endl;

    }
    return 0;
}