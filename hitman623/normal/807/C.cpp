#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long x,y,p,q,i,d,t,u,v,e;
    cin>>t;
    while(t--)
    {
        cin>>x>>y>>p>>q;
        if(q==p)
        {
            if(x==y) cout<<0;
            else cout<<-1;
            cout<<endl;
            continue;
        }
        if(p==0)
        {
            if(x==0) cout<<0;
            else cout<<-1;
            cout<<endl;
            continue;
        }
        d=x*q-p*y;
        u=p-(x%p)-p*(!(x%p));
        v=(u*(q-p)+d)/p;
        if(v<0)
        {
            d=-d;
            e=d/(q-p)+!!(d%(q-p));
            u+=e+p-(e%p)-p*(!(e%p));
            if((u-p)*(q-p)-d>=0)
            u-=p;
            d=-d;
        }
        v=(u*(q-p)+d)/p;
        cout<<u+v<<endl;
    }
    return 0;
}