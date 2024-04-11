#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

const int nmax = 2e5 + 100;

typedef long long ll;
#define int ll

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ___;
    cin>>___;
    for (int _ = 0; _ < ___; _++)
    {
        int n;
        cin>>n;
        vector<int> g(n, -1);
        vector<pair<int, int> > a(n);
        for (int i=0; i<n; i++)
            cin>>a[i].fi, a[i].se=i;
        for (int i=1; i<n; i++)
        {
            int x, y;
            cin>>x>>y;
            g[x-1]++;
            g[y-1]++;
        }
        int sum = 0;
        for (auto i: a)
            sum+=i.fi;
        cout<<sum;

        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        int cur=0;

        for (int i=2; i<n; i++)
        {
            while (g[a[cur].se] == 0)
                cur++;
            g[a[cur].se]--;
            sum+=a[cur].fi;
            cout<<" "<<sum;
        }
        cout<<"\n";
    }
}