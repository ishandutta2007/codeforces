/*
K.D. Vinit  /,,/
Dont stalk my code : )
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

const int N = 4e6 + 100;
int nxt[N], vis[N], dep[N], siz[N], cyc=0, cyc_len, criti;

int DFS(int chi, int cd)
{
    if(vis[chi]) return siz[chi];
    int cur=1;
    dep[chi]=cd;

    int x = nxt[chi];
    if(x!=-1)
    {
        if(dep[x]!=0) { cyc=1; cyc_len=dep[chi]-dep[x]+1; criti=x; }
        else cur += DFS(x, cd+1);
    }

    if(cyc) cur=cyc_len;
    if(chi==criti) cyc=0;

    vis[chi]=1;
    dep[chi]=0;
    siz[chi]=cur;
    return cur;
}

int n, m;
inline int point(int x, int y)
{
    int cord = ((x-1)*m) + y;
    return cord;
}

void solve()
{
    cin>>n>>m;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            int x=i, y=j;
            char dir; cin>>dir;

            if(dir=='L') y--;
            if(dir=='R') y++;
            if(dir=='U') x--;
            if(dir=='D') x++;

            int cp = point(i, j);
            vis[cp]=0;
            dep[cp]=0;

            if(x<1 || x>n || y<1 || y>m) nxt[cp]=-1;
            else nxt[cp]=point(x, y);
        }
    }

    int ax=0, ay=0, alen=-1;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(vis[point(i, j)]==0) DFS(point(i, j), 1);
            if(siz[point(i, j)]>alen) { ax=i; ay=j; alen=siz[point(i, j)]; }
        }
    }

    cout<<ax<<" "<<ay<<" "<<alen<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}