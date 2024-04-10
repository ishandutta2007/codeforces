#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<int,ll>mp;
map<pair<int,int> ,ll >g;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        int l=INT_MAX,r=0;
        mp.clear();
        g.clear();
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int x,y,z;
            cin>>x>>y>>z;
            if(mp[x]==0 ||mp[x]>z)mp[x]=z;
            if(mp[y]==0 ||mp[y]>z)mp[y]=z;
            if(g[{x,y}]==0 || g[{x,y}]>z)g[{x,y}]=z;
            l=min(l,x);
            r=max(r,y);
            ll ans=mp[l]+mp[r];
            if(g[{l,r}]!=0)ans=min(ans,g[{l,r}]);
            cout<<ans<<endl;
        }

    }
    return 0;
}