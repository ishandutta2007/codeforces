#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll r[1000009];
ll u[1000009],v[1000009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            ll x,y;
            cin>>x>>y;
            ll p=min(x,m);
            x-=p;
            y-=(m-p);
            u[i]=p;
            v[i]=m-p;
            ans+=x-y;
            r[i]=2*min(y,p);
        }
        if(ans>=0){cout<<ans<<endl;
        for(int i=0;i<n;i++)cout<<u[i]<<" "<<v[i]<<endl;
        continue;}
        ans*=-1;
        for(int i=0;i<n;i++)
        {
            ll g=min(ans-ans%2,r[i]);
            ans-=g;
            u[i]-=g/2;
            v[i]+=g/2;
        }
        cout<<ans<<endl;

        for(int i=0;i<n;i++)cout<<u[i]<<" "<<v[i]<<endl;
    }
    return 0;
}