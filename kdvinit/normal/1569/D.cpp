/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define endl "\n"

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve()
{
    int n, m, k;
    cin>>n>>m>>k;

    map<int, int> mpx, mpy;
    map<int, int> mp1x, mp1y;
    map<pair<int, int>, int> mp2x, mp2y;

    ordered_set rx, ry;

    int x[n+1], y[m+1];
    for(int i=1; i<=n; i++) { cin>>x[i]; mpx[x[i]]=1; rx.insert(x[i]); }
    for(int i=1; i<=m; i++) { cin>>y[i]; mpy[y[i]]=1; ry.insert(y[i]); }

    int ans = 0;
    for(int i=1; i<=k; i++)
    {
        int xp, yp; cin>>xp>>yp;
        if(mpx[xp]==1 && mpy[yp]==1) continue;

        if(mpx[xp]==1)
        {
            int cnt = ry.order_of_key(yp);
            ans+=mp1x[cnt]; mp1x[cnt]++;
            ans-=mp2x[{xp, cnt}]; mp2x[{xp, cnt}]++;
        }
        else
        {
            int cnt = rx.order_of_key(xp);
            ans+=mp1y[cnt]; mp1y[cnt]++;
            ans-=mp2y[{yp, cnt}]; mp2y[{yp, cnt}]++;
        }
    }

    cout<<ans<<endl;
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}