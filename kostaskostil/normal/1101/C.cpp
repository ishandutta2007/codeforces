#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;
#define int long long
#define fi first
#define se second
set<pair< pair<int, int>, int> > s;
int ans[100500];

main()
{
    int ttt;
    cin>>ttt;
    for (int iii=0; iii<ttt; iii++)
    {
        int l, r;
        s.clear();
        memset(ans, 0, sizeof(ans));
        int n;
        cin>>n;
        for (int i=1; i<=n; i++)
            cin>>l>>r, s.insert({{l, r}, i});
        r=-1000000000;
        int c=0;
        for (auto pa:s)
        {
            c++;
            if ((c!=1) and (pa.fi.fi>r))
            {
                c=0;
                break;
            }
            else
            {
                r=max(r, pa.fi.se);
                ans[pa.se]=1;
            }
        }
        if (c==0)
            for (int i=1; i<=n; i++)
                cout<<ans[i]+1<<" ";
        else
            cout<<"-1";
        cout<<"\n";
    }
}