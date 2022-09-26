#include <bits/stdc++.h>
#pragma GCC optimize("O3")

#define pb push_back
#define fi first
#define se second

using namespace std;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _;
    cin>>_;
    while (_--)
    {
        int n, k;
        cin>>n>>k;
        vector<pair<int, int> > v(k);
        vector<int> used(2*n, 0);
        for (auto& pa: v)
            cin>>pa.fi>>pa.se, pa.fi--, pa.se--;
        for (auto pa: v)
            used[pa.fi] = used[pa.se] = 1;
        vector<int> unused;
        for (int i=0; i<2*n; i++)
            if (!used[i])
                unused.pb(i);
        for (int i=0; 2*i<unused.size(); i++)
            v.pb({unused[i], unused[unused.size()/2 + i]});
//        cout<<v.size()<<" "<<n<<"\n";
//        for (auto pa : v)
//            cout<<pa.fi<<" "<<pa.se<<" ";
        int ans=0;
        for (int i=0; i<n; i++)
            for (int j=i+1; j<n; j++)
        {
            auto pa1 = v[i];
            auto pa2 = v[j];
            if (pa1.fi > pa1.se)
                swap(pa1.fi, pa1.se);
            if (pa2.fi > pa2.se)
                swap(pa2.fi, pa2.se);
            if (pa1 > pa2)
                swap(pa1, pa2);
            if ((pa2.se > pa1.se) and (pa2.fi < pa1.se))
                ans++;
        }
        cout<<ans<<"\n";
    }
}