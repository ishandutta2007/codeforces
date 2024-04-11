#include <bits\stdc++.h>
#define pb push_back
#define fi first
#define se second
#define int long long

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
        int n;
        cin>>n;
        vector<vector<int> > g;
        g.resize(n+1);
        for (int i=1; i<=n; i++)
        {
            int k;
            cin>>k;
            for (int j=1; j<=k; j++)
            {
                int x;
                cin>>x;
                g[i].pb(x);
            }
        }
        vector<int> used;
        used.resize(n+1);
        int ans=-1;
        for (int i=1; i<=n; i++)
        {
            int x=-1;
            for (int j:g[i])
                if (used[j]==0)
            {
                used[j]=1;
                x=1;
                break;
            }
            if (x==-1)
                ans=i;
        }

        if (ans==-1)
            cout<<"OPTIMAL\n";
        else
        {
            cout<<"IMPROVE\n";
            int f=-1;
            for (int i=1; i<=n; i++)
                if (used[i]==0)
                    f=i;
            cout<<ans<<" "<<f<<"\n";
        }
    }
    return 0;
}