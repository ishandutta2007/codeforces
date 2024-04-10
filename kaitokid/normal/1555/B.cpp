#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll W,H,x1,y1,x2,y2,w,h;
        cin>>W>>H>>x1>>y1>>x2>>y2>>w>>h;
        ll ans=1000000000;
        if(x2-x1+w<=W)
        {
            ll u=x1,v=W-x2;
            ans=min(ans,max(0LL,w-u));
            ans=min(ans,max(0LL,w-v));

        }
        if(y2-y1+h<=H)
        {
            ll u=y1,v=H-y2;
            ans=min(ans,max(0LL,h-u));
            ans=min(ans,max(0LL,h-v));

        }
        if(ans==1000000000)cout<<-1<<endl;
        else cout<<ans<<endl;
         }
    return 0;
}