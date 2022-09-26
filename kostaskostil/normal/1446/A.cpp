#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

const int nmax=1000500;
typedef long long ll;
#define int ll

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin>>q;
    for (int i=0; i<q; i++)
    {
        int n, s;
        cin>>n>>s;
        vector<pair<int, int> > v(n);
        for (int i =0; i<n; i++)
            cin>>v[i].fi, v[i].se=i+1;
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        int c=0;
        vector<int> ans;
        for (int i=0; i<n; i++)
        {
            if (c+v[i].fi <= s)
                ans.pb(v[i].se), c+=v[i].fi;
        }
        if ((s+1)/2 <= c)
        {
            cout<<ans.size()<<"\n";
            for (int i:ans)
                cout<<i<<" ";
            cout<<"\n";
        }
        else cout<<"-1\n";
    }
}