#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second

using namespace std;
const int nmax=5e5+100;
#define int long long

set<int> a;
set<int> b;
set<int> c;

int check(int x, set<int>& l, set<int>& h)
{
    auto ity=l.upper_bound(x);
    if (ity==l.begin()) return 4e18;
    auto itz=h.lower_bound(x);
    if (itz==h.end()) return 4e18;
    int y=*prev(ity);
    int z=*itz;
    return (x-y)*(x-y)+(x-z)*(x-z)+(y-z)*(y-z);
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ttt;
    cin>>ttt;
    for (int iii=0; iii<ttt; iii++)
    {
        a.clear(), b.clear(), c.clear();
        int n, m, k;
        cin>>n>>m>>k;
        for (int x, i=1; i<=n; i++)
            cin>>x, a.insert(x);
        for (int x, i=1; i<=m; i++)
            cin>>x, b.insert(x);
        for (int x, i=1; i<=k; i++)
            cin>>x, c.insert(x);
        int ans=4e18;
        for (int x:a)
        {
            ans=min(ans, check(x, b, c));
            ans=min(ans, check(x, c, b));
        }
        for (int x:b)
        {
            ans=min(ans, check(x, a, c));
            ans=min(ans, check(x, c, a));
        }
        for (int x:c)
        {
            ans=min(ans, check(x, b, a));
            ans=min(ans, check(x, a, b));
        }
        cout<<ans<<"\n";
    }
}