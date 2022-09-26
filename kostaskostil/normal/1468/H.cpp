#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

const int nmax = 5e5+100;

typedef long long ll;
#define int ll

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    for (int j=0; j<t; j++)
    {
        int n, k, m;
        cin>>n>>k>>m;
        vector<int> v(n+1, 0);
        for (int i=1; i<=m; i++)
        {
            int x;
            cin>>x;
            v[x]=1;
        }
        vector<int> del;
        for (int i=1; i<=n; i++)
            if (v[i]==0)
                del.pb(i);
        if (del.size() % (k-1) != 0)
            cout<<"NO\n";
        else
        {
            int t = (k-1)/2;
            int l = del[t-1]+1;
            int r = del[del.size()-t]-1;
            bool ok = false;
            for (int i=l; i<=r; i++)
                if (v[i]==1)
                    ok=true;
            if (ok)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
    }
}