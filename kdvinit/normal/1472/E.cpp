/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n; cin>>n;

    int x, y, a, b;
    vector<array<int, 3>> xy;
    for(int i=1; i<=n; i++)
    {
        cin>>x>>y;
        a = min(x, y);
        b = max(x, y);
        xy.push_back({a, b, i});
    }
    sort(xy.begin(), xy.end());

    int miny=1e10, mini;
    int ans[n+1];

    for(int i=0; i<n; i++)
    {
        int xx = xy[i][0];

        for(int j=i; j<n; j++)
        {
            int x = xy[j][0];
            int y = xy[j][1];
            int ind = xy[j][2];

            if(x!=xx) break;

            if(miny<y) ans[ind]=mini;
            else ans[ind]=-1;

        }

        int j;
        for(j=i; j<n; j++)
        {
            int x = xy[j][0];
            int y = xy[j][1];
            int ind = xy[j][2];

            if(x!=xx) break;

            if(y<miny) { miny=y; mini=ind; }
        }
        i = j-1;
    }

    for(int i=1; i<=n; i++) cout<<ans[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}