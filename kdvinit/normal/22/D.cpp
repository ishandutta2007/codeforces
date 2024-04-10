/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n; cin>>n;
    vector< array<int, 3> > time;

    for(int i=1; i<=n; i++)
    {
        int x, y;
        cin>>x>>y;

        int l=min(x, y), r=max(x, y);
        time.push_back({l, -1, i});
        time.push_back({r, 1, i});
    }
    sort(time.begin(), time.end());

    vector<int> ans;
    set<int> seg;
    int vis[n+1]={0};

    for(auto cur: time)
    {
        int x = cur[0];
        int typ = cur[1];
        int ind = cur[2];

        if(typ==-1)
        {
            seg.insert(ind);
        }
        else
        {
            if(vis[ind]==1) continue;
            ans.push_back(x);
            for(auto y: seg) vis[y]=1;
            seg.clear();
        }
    }

    cout<<ans.size()<<endl;
    for(auto x: ans) cout<<x<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}