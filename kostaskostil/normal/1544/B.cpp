#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

typedef long long ll;
#define int ll

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int qqq;
    cin>>qqq;
    for (int iii=0; iii<qqq; iii++)
    {
        int n, m;
        cin>>n>>m;
        vector<vector<int> > v(n, vector<int>(m, 0));
        vector<pair<int, int> > pos;
        for (int i=0; i<m; i++)
        pos.pb({0, i});
        for (int i=1; i<n; i++)
        pos.pb({i, m-1});
        for (int i=m-2; i>=0; i--)
        pos.pb({n-1, i});
        for (int i=n-2; i>=1; i--)
        pos.pb({i, 0});
        for (auto pa : pos)
        {
            bool ok = true;
            for (int dx = -1; dx <= 1; dx++)
            for (int dy = -1; dy <= 1; dy++)
                if (pa.fi + dx >=0 and pa.fi+dx<n and pa.se+dy>=0 and pa.se+dy<m)
                    if (v[pa.fi+dx][pa.se+dy])
                        ok = false;
            if (ok)
                v[pa.fi][pa.se] = 1;
        }
        for (int i=0; i<n; i++, cout<<"\n")
            for (int j : v[i])
                cout<<j;
    }
}