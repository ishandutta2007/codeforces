#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        for(int i=0;i<m;i++)cin>>a[i];
        sort(a,a+m);
        vector<ll>g;
        g.push_back(a[0]-1+n-a[m-1]);
        for(int i=0;i+1<m;i++)
            g.push_back(a[i+1]-a[i]-1);
        ll ans=m;
        sort(g.begin(),g.end());
        ll d=0,z=g.size();
        for(int i=z-1;i>=0;i--)
        {
            ll u=min(2*d,g[i]);
            ans+=u;
            g[i]-=u;
            if(g[i]==0)continue;
            if(g[i]==1){d++;continue;}
            if(g[i]==2){d++;ans++;continue;}
            d+=2;
            ans++;
        }
        cout<<ans<<endl;
    }

    return 0;

}