/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int N = 2e5+10;

vector<int> adj[N];
int a[N], sub[N];
int n, k;
int xxr;

void DFS1(int chi, int par)
{
    int cur = a[chi];
    for(auto x: adj[chi])
    {
        if(x==par) continue;
        DFS1(x, chi);
        cur^=sub[x];
    }
    sub[chi]=cur;
}

int DFS2(int chi, int par)
{
    int cnt[3]={0};
    for(auto x: adj[chi])
    {
        if(x==par) continue;
        cnt[DFS2(x, chi)]++;
    }

    if(cnt[2]!=0) return 2;
    if(cnt[1]>1) return 2;
    if(sub[chi]==0 && cnt[1]==1) return 2;
    if(cnt[1]==1 || sub[chi]==xxr) return 1;
    return 0;
}

bool chk3()
{
    int xr=0;
    for(int i=1; i<=n; i++) xr^=a[i];
    DFS1(1, -1);
    xxr=xr;
    int val = DFS2(1, -1);
    return (val==2);
}

bool chk2()
{
    int xr=0;
    for(int i=1; i<=n; i++) xr^=a[i];
    return (xr==0);
}

bool solve()
{
    cin>>n>>k;
    for(int i=1; i<=n; i++) adj[i].clear();
    for(int i=1; i<=n; i++) cin>>a[i];

    for(int i=1; i<=n-1; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(chk2()) return true;
    if(k==2) return false;
    return chk3();
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--)
    {
        if(solve()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}