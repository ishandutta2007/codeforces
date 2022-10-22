#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<ll,ll> >v[100009];
ll mx[100009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>m>>n;
        for(int i=0;i<m;i++)v[i].clear();
        for(int i=0;i<n;i++)mx[i]=0;
        for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        {
            ll x;
            cin>>x;
            v[i].push_back({x,j});
            mx[j]=max(mx[j],x);
        }
       ll ans=0;
       for(int i=0;i<m;i++)
       {
           sort(v[i].begin(),v[i].end());
           ll res=v[i][n-2].first;
           for(int j=0;j<n-2;j++)res=min(res,mx[v[i][j].second]);
           ans=max(ans,res);
       }
       cout<<ans<<endl;


    }

    return 0;
}