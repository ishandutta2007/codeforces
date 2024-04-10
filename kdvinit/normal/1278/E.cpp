/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

#define mxn 500001

int dc[mxn];
int tc[mxn];
int l[mxn],r[mxn];
int seq[2*mxn];

void do_tc(vector< vector<int> >& adj,int par,int chi)
{
    int tmp=0;
    for(int i=0;i<adj[chi].size();i++)
    {
        if(adj[chi][i]==par) continue;
        do_tc(adj,chi,adj[chi][i]);
        tmp+=tc[adj[chi][i]];
        tmp++;
    }
    tc[chi]=tmp;
}

int pos;
void do_seg(vector< vector<int> >& adj,int par,int chi)
{
    for(int i=0;i<adj[chi].size();i++)
    {
        if(adj[chi][i]==par) continue;
        l[adj[chi][i]]=++pos;
    }
    r[chi]=++pos;

    for(int i=adj[chi].size()-1;i>=0;i--)
    {
        if(adj[chi][i]==par) continue;
        do_seg(adj,chi,adj[chi][i]);
    }
}

void solve()
{
    int n,x,y;
    cin>>n;

    if(n==1)
    {
        cout<<1<<" "<<2<<endl;
        return;
    }

    vector< vector<int> > adj(n+1);
    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dc[1]=adj[1].size();
    for(int i=2;i<=n;i++)
    {
        dc[i]=adj[i].size()-1;
    }

    do_tc(adj,0,1);

    l[1]=1;
    pos=1;
    do_seg(adj,0,1);

    for(int i=1;i<=n;i++)
    {
        cout<<l[i]<<" "<<r[i]<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}