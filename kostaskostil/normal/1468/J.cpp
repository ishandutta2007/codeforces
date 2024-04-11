#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

const int nmax = 2e5+100;

typedef long long ll;
#define int ll

int n;
vector<pair<int, int> > g[nmax];
int p[nmax];

int get(int v)
{
    if (v==p[v])
        return v;
    return p[v]=get(p[v]);
}

void un(int u, int v)
{
    u=get(u);
    v=get(v);
    p[v]=u;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    for (int i_=1; i_<=t; i_++)
    {
        cin>>n;
        for (int i=1; i<=n; i++)
            p[i]=i, g[i].clear();
        int m, k;
        cin>>m>>k;
        vector<pair<int, pair<int, int> > > ed0;
        vector<pair<int, pair<int, int> > > ed;
        for (int i=1; i<=m; i++)
        {
            int x, y, s;
            cin>>x>>y>>s;
            ed0.pb({s, {x, y}});
            g[x].pb({y, s});
            g[y].pb({x, s});
            if (s>=k)
                ed.pb({s-k, {x, y}});
            else
                ed.pb({0, {x, y}});
        }
        sort(ed.begin(), ed.end());
        int ans=0;
        for (auto e : ed)
        {
            if (get(e.se.fi) == get(e.se.se))
                continue;
            un(e.se.fi, e.se.se);
            ans+=e.fi;
        }
        if (ans>0)
            cout<<ans<<"\n";
        else
        {
//            for (int i=1; i<=n; i++)
//                p[i]=i;
//            ed.clear();
//            for (auto e:ed0)
//            {
//                if (e.fi<=k)
//                    ed.pb({k-e.fi, e.se});
//            }
//            sort(ed.begin(), ed.end());
//            int cnt = n;
//            for (auto e : ed)
//            {
//                if (get(e.se.fi) == get(e.se.se))
//                continue;
//                un(e.se.fi, e.se.se);
//                cnt--;
//                if (cnt==1)
//                {
//                    ans=e.fi;
//                    break;
//                }
//            }
            int ans = 1e18;
            for (auto e : ed0)
                ans=min(ans, abs(k-e.fi));
            cout<<ans<<"\n";
        }
    }

}