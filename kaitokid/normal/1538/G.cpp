#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll a,b,x,y;
bool ch(int u)
{
    if(x<a*u)return false;
    if(y<a*u)return false;
    ll d=(x-a*u)/(b-a);
    ll z=(y-a*u)/(b-a);
    return (d+z)>=u;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>x>>y>>a>>b;
        if(a==b)
        {
            ll ans=min(x/a,y/a);
            cout<<ans<<endl;
            continue;
        }
        if(a>b)swap(a,b);
        ll st=0,en=1000000002;
        while(st<en)
        {
            ll mid=(st+en+1)/2;
            if(ch(mid))st=mid;
            else en=mid-1;
        }
        cout<<st<<endl;
    }
    return 0;
}