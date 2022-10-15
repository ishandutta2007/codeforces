/*
K.D. Vinit  /,,/
Test Run - 2
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

map<pair<int, int>, int> mp, vis;
int n, k;
vector<int> val;

map<pair<int, int>, pair<int, int>> rht, lft, up, dwn;

int dfs(pair<int, int> nd)
{
    vis[nd]=1;
    int cur = mp[nd]-1;
    if(mp[rht[nd]]!=0 && vis[rht[nd]]==0) cur=min(cur, dfs(rht[nd]));
    if(mp[lft[nd]]!=0 && vis[lft[nd]]==0) cur=min(cur, dfs(lft[nd]));
    if(mp[up[nd]]!=0 && vis[up[nd]]==0) cur=min(cur, dfs(up[nd]));
    if(mp[dwn[nd]]!=0 && vis[dwn[nd]]==0) cur=min(cur, dfs(dwn[nd]));
    return cur;
}

bool check(int x)
{
    int m = val.size();
    int cnt=0;
    for(int i=0; i<m; i++)
    {
        if(val[i]>x) cnt++;
    }

    if(cnt<=x+1) return true;
    else return false;
}

void solve()
{
    mp.clear(); vis.clear(); val.clear();
    rht.clear(); lft.clear(); up.clear(); dwn.clear();
    cin>>n>>k;

    int x[n+1], y[n+1], tim;
    for(int i=1; i<=n; i++)
    {
        cin>>x[i]>>y[i]>>tim;
        mp[{x[i], y[i]}]=tim+1;
        rht[{x[i], y[i]}]={x[i], y[i]};
        lft[{x[i], y[i]}]={x[i], y[i]};
        up[{x[i], y[i]}]={x[i], y[i]};
        dwn[{x[i], y[i]}]={x[i], y[i]};
    }

    set<int> xx, yy;
    map<int, vector<int>> xr, yr;

    for(int i=1; i<=n; i++)
    {
        xx.insert(x[i]);
        yy.insert(y[i]);
        xr[x[i]].push_back(y[i]);
        yr[y[i]].push_back(x[i]);
    }

    for(int cx: xx)
    {
        sort(xr[cx].begin(), xr[cx].end());
        int len = xr[cx].size();
        for(int i=1; i<len; i++)
        {
            int cy = xr[cx][i];
            int py = xr[cx][i-1];
            int dif = cy-py;
            if(dif>k) continue;
            lft[{cx, cy}] = {cx, py};
            rht[{cx, py}] = {cx, cy};
        }
    }

    for(int cy: yy)
    {
        sort(yr[cy].begin(), yr[cy].end());
        int len = yr[cy].size();
        for(int i=1; i<len; i++)
        {
            int cx = yr[cy][i];
            int px = yr[cy][i-1];
            int dif = cx-px;
            if(dif>k) continue;
            dwn[{cx, cy}] = {px, cy};
            up[{px, cy}] = {cx, cy};
        }
    }

    for(int i=1; i<=n; i++)
    {
        if(vis[{x[i], y[i]}]) continue;
        val.push_back(dfs({x[i], y[i]}));
    }

    sort(val.begin(), val.end());

    int l=-1, r=1e9;
    while(l+1!=r)
    {
        int mid = (l+r)/2;
        if(check(mid)) r=mid;
        else l=mid;
    }

    cout<<r<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}