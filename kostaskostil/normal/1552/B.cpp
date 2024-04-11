
#include <bits/stdc++.h>
#pragma GCC optimize("O3")

#define pb push_back
#define fi first
#define se second

using namespace std;

        vector<vector<pair<int, int> > > v;//(5, vector<pair<int, int> >(n));
        vector<vector<pair<int, int> > > p;//(5, vector<pair<int, int> >(n));
        int n;

bool win(int i, int j)
{
                int cnt=0;
                for (int k=0; k<5; k++)
                    if (p[k][i].fi < p[k][j].fi)
                        cnt++;
                if (cnt>=3)
                {
                    return true;
                }
                return false;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _;
    cin>>_;
    while (_--)
    {
        cin>>n;
        v.assign(5, vector<pair<int, int> >(n));
        p.assign(5, vector<pair<int, int> >(n));
        for (int i=0; i<n; i++)
            for (int j=0; j<5; j++)
        {
            cin>>v[j][i].fi;
            p[j][i].fi = v[j][i].fi;
            v[j][i].se = i;
        }
        int cur=0;
        for (int i = 1; i<n; i++)
            if (win(i, cur))
                cur=i;
        bool ok = true;
        for (int i = 0; i<n; i++)
            if (i!=cur)
                if (win(i, cur))
                    ok = false;
        cur++;
        if (!ok)
            cur=-1;
        cout<<cur<<"\n";
    }
}