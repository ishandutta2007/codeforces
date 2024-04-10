#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll w,h;
        cin>>w>>h;
        ll ans=0;
        for(int j=0;j<2;j++)
        {
            int k;
            cin>>k;
            ll x,y;
            cin>>x;
            for(int i=1;i<k;i++)cin>>y;
            ans=max(ans,(y-x)*h);
        }

        for(int j=0;j<2;j++)
        {
            int k;
            cin>>k;
            ll x,y;
            cin>>x;
            for(int i=1;i<k;i++)cin>>y;
            ans=max(ans,(y-x)*w);
        }
       cout<<ans<<endl;
    }
    return 0;
}