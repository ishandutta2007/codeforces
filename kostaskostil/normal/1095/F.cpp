#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;

int n, m;
int a[200500];
vector<pair<int, int> > g[200500];
int mnpref[200500];
int mnsuf[200500];
set<pair<int, int> > s;
set<pair<int, int> > ex;
int used[200500];
int dist[200500];
main()
{
    cin>>n>>m;
    int mn=1000000000000000000;
    mnpref[0]=mnsuf[n+1]=1000000000000000000;
    for (int i=1; i<=n; i++)
        cin>>a[i], s.insert({a[i], i}); //, mnpref[i]=min(mnpref[i-1], a[i]), s.insert({a[i], i});
    //for (int i=n; i>=1; i--)
    //    mnsuf[i]=min(mnsuf[i+1], a[i]);
    int x, y, w;
    for (int i=1; i<=m; i++)
    {
        cin>>x>>y>>w;
        g[x].pb({y, w});
        g[y].pb({x, w});
    }
    int ans=0;
    s.erase({a[1], 1});
    for (auto pa:g[1])
        ex.insert({pa.se, pa.fi});
    used[1]=1;
    mn=a[1];
    for (int iii=2; iii<=n; iii++)
    {
        int t, l;
        auto pa=*s.begin();
        t=pa.fi+mn;
        l=pa.se;
        while (ex.size()>0)
        {
            auto p=*ex.begin();
            if (used[p.se]==1)
                ex.erase(ex.begin());
            else
            {
                if (p.fi<t)
                {
                    t=p.fi;
                    l=p.se;
                }
                break;
            }
        }

        //if (used[l]==1)
        //    cout<<"WTF\n";

        mn=min(mn, a[l]);
        ans+=t;
        used[l]=1;
        for (auto pa:g[l])
            if (used[pa.fi]==0)
                ex.insert({pa.se, pa.fi});
        s.erase({a[l], l});
    }
    cout<<ans<<"\n";
}