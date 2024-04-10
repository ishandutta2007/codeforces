#include<bits/stdc++.h>
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
     ll n,m;
     vector<pair<ll,ll> >g;
     cin>>n>>m;
     for(int i=0;i<n;i++)
        {
            ll d=0,x;
            for(int j=0;j<m;j++)
            {
                cin>>x;
                d+=x*j;
            }
            g.push_back({d,i+1});
        }
        sort(g.begin(),g.end());
        cout<<g[n-1].second<<" "<<g[n-1].first-g[0].first<<endl;
    }

    return 0;

}