#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second

const int nmax=1e5+100;
//#define int long long

int mx;
vector<int> g[nmax];
vector<pair<int, int> > ans;

void dfs(int v, int t, int p=-1)
{
    int needed=t-1;
    ans.pb({v, t});
    for (int i:g[v])
        if (i!=p)
    {
        if (t==mx)
            t=mx-g[v].size(), ans.pb({v, t});
        dfs(i, t+1, v);
        t++;
        ans.pb({v, t});
    }
    if (p!=-1)
    if (t!=needed)
        ans.pb({v, needed});
}

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for (int x, y, i=1; i<n; i++)
    {
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    for (int i=1; i<=n; i++)
        mx=max<int>(mx, g[i].size());
    dfs(1, 0);
    cout<<ans.size()<<"\n";
    for (auto pa:ans)
        cout<<pa.fi<<" "<<pa.se<<"\n";
}