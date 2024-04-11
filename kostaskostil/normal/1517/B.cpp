#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
#define int ll

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ___;
    cin>>___;
    while (___--)
    {
        int n, m;
        cin>>n>>m;
        vector<pair<int, pair<int, int> > > a;
        vector<vector<int> > v(n, vector<int>(m));
        vector<vector<int> > d(n, vector<int>(m));
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                cin>>v[i][j], a.pb({v[i][j], {i, j}});
        sort(a.begin(), a.end());
        for (int i=0; i<m; i++)
            d[a[i].se.fi][a[i].se.se]=i+1;
        for (int i=0; i<n; i++)
        {
            set<int> lt;
            for (int i=0; i<m; i++)
                lt.insert(i);
            for (int j=0; j<m; j++)
                if (d[i][j]!=0)
                    lt.erase(j);
            vector<int> ans(m+1, -1);
            for (int j=0; j<m; j++)
                ans[d[i][j]] = v[i][j];
            for (int j=1; j<=m; j++)
                if (ans[j] == -1)
            {
                int c = *lt.begin();
                lt.erase(c);
                ans[j] = v[i][c];
            }

            for (int j=1; j<=m; j++)
                cout<<ans[j]<<" ";
            cout<<"\n";
        }
    }
}