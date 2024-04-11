#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
//#define int ll

const int nmax = 20500;

map<int, set<int> > vals; /// cnt -> val
map<int, set<int> > bad; ///
void solve()
{
    vals.clear();
    bad.clear();

    int n, m;
    cin>>n>>m;
    map<int, int> mp;
    for (int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        mp[x]++;
    }
    for (auto pa : mp)
        vals[pa.se].insert(pa.fi);
    for (int i=0; i<m; i++)
    {
        int x, y;
        cin>>x>>y;
        bad[x].insert(y);
        bad[y].insert(x);
    }

    ll ans = 0;
    for (auto& pa : mp)
    {
        int a = pa.fi;
//        for (int x : bad[a])
//            vals[mp[x]].erase(x);
//        vals[mp[a]].erase(a);

        int c = mp[a];
        for (int i=1; i<=c; i++)
        {
            auto it = vals[i].end();
            while (true)
            {
                if (it == vals[i].begin())
                    break;
                it = prev(it);
                int q = *it;
                if (bad[a].count(q) || (q==a))
                    continue;
                ans = max(ans, (q+a)*1ll*(c+i));
                break;
            }
//            if (!vals[i].empty())
//            {
//                int q = *prev(vals[i].end());
//                ans = max(ans, (q + a) * (c + i));
//            }
//            for (int q : vals[i])
//                if (q != a)
        }

//        for (int x : bad[a])
//            vals[mp[x]].insert(x);
//        vals[mp[a]].insert(a);
    }
    cout<<ans<<"\n";
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _;
    cin>>_;
    while (_--)
        solve();
}