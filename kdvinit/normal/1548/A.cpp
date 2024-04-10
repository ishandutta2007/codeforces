/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 1;
set<int> adj[N];

int ans;

int check(int u)
{
    if(adj[u].size()==0) return 0;
    int mx = *adj[u].rbegin();
    if(mx>u) return 1;
    else return 0;
}

void add(int u, int v)
{
    ans+=check(u);
    ans+=check(v);
    adj[u].insert(v);
    adj[v].insert(u);
    ans-=check(u);
    ans-=check(v);
}

void del(int u, int v)
{
    ans+=check(u);
    ans+=check(v);
    adj[u].erase(v);
    adj[v].erase(u);
    ans-=check(u);
    ans-=check(v);
}

void solve()
{
    int n, m;
    cin>>n>>m;

    ans=n;

    int u, v;
    for(int i=1; i<=m; i++)
    {
        cin>>u>>v;
        add(u, v);
    }

    int q; cin>>q;
    while(q--)
    {
        int typ;
        cin>>typ;
        if(typ==1)
        {
            cin>>u>>v;
            add(u, v);
        }
        if(typ==2)
        {
            cin>>u>>v;
            del(u, v);
        }
        if(typ==3)
        {
            cout<<ans<<endl;
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}