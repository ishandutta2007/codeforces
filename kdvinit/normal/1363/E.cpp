/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define int long long

int n,x,y,a[200001],b[200001],c[200001],cnt1b=0,cnt1c=0,cost[200001],ans=0,b1[200001],b0[200001];
vector< vector<int> > adj(200001);

void find_cost(int par,int chi) // '&' is veru Important here;
{
    cost[chi]=min(cost[par],a[chi]);
    for(int i=0;i<adj[chi].size();i++)
    {
        if(adj[chi][i]==par) continue;
        find_cost(chi,adj[chi][i]);
    }
}

void find_ans(int par,int chi) // '&' is veru Important here;
{
    for(int i=0;i<adj[chi].size();i++)
    {
        if(adj[chi][i]==par) continue;
        find_ans(chi,adj[chi][i]);
        b1[chi]+=b1[adj[chi][i]];
        b0[chi]+=b0[adj[chi][i]];
    }
    if(b[chi]!=c[chi])
    {
        if(b[chi]==1) b1[chi]++;
        else b0[chi]++;
    }
    int mn=min(b1[chi],b0[chi]);
    if(mn!=0)
    {
        ans+=mn*cost[chi]*2;
        b0[chi]-=mn;
        b1[chi]-=mn;
    }
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
        if(b[i]==1) cnt1b++;
        if(c[i]==1) cnt1c++;
    }

    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    if(cnt1b!=cnt1c) { cout<<-1<<endl; return; }

    cost[0]=a[1];
    find_cost(0,1);

    find_ans(0,1);
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}