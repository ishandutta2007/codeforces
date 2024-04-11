#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;



main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    for (int i=1; i<=t; i++)
    {
        int n, m;
        cin>>n>>m;
        vector<pair<int, int> > ed;
        vector<int> ans;
        vector<int> used;

        for (int x, y, i=1; i<=m; i++)
        {
            cin>>x>>y;
            ed.pb({x, y});
        }

        used.resize(3*n+1);
        for (int i=0; i<m; i++)
            if (used[ed[i].fi]==0)
            if (used[ed[i].se]==0)
                ans.pb(i+1), used[ed[i].fi]=used[ed[i].se]=1;
        if (ans.size()>=n)
        {
            cout<<"Matching\n";
            for (int i=0; i<n; i++)
                cout<<ans[i]<<" ";
            cout<<"\n";
        }
        else
        {
            cout<<"IndSet\n";
            int q=0;
            for (int i=1; i<=3*n; i++)
                if (used[i]==0)
                    if (q<n)
                        q++, cout<<i<<" ";
            cout<<"\n";
        }
    }

}