/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define int long long

int mxl;

int do_mxl(vector< vector<int> >& adj,int par,int chi) // '&' is veru Important here;
{
    int mx1=0,mx2=0,temp;
    for(int i=0;i<adj[chi].size();i++)
    {
        if(adj[chi][i]==par) continue;
        temp=do_mxl(adj,chi,adj[chi][i]);
        if(temp>=mx1)
        {
            mx2=mx1;
            mx1=temp;
        }
        else if(temp>mx2)
        {
            mx2=temp;
        }
    }
    mx1++;
    mx2+=mx1;
    mxl=max(mxl,mx2);
    return mx1;
}

void do_bob(vector< vector<int> >& adj,int par,int chi,int b_dist[],int b_can[],int b_loc) // '&' is veru Important here;
{
    if(chi==b_loc)
    {
        b_can[chi]=1;
        b_dist[chi]=0;
        return;
    }
    for(int i=0;i<adj[chi].size();i++)
    {
        if(adj[chi][i]==par) continue;
        do_bob(adj,chi,adj[chi][i],b_dist,b_can,b_loc);
        if(b_can[adj[chi][i]]==1)
        {
            b_can[chi]=1;
            b_dist[chi]=b_dist[adj[chi][i]]+1;
        }
    }
}

void solve()
{
    mxl=0;
    int n,da,db,x,y,a_loc,b_loc;
    cin>>n>>a_loc>>b_loc>>da>>db;

    vector< vector<int> > adj(n+1);
    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int temp= do_mxl(adj,0,1);

    int xx=(2*da+1);
    if(db<xx) { cout<<"Alice"<<endl; return; }
    xx++;
    if(mxl<xx) { cout<<"Alice"<<endl; return; }

    int b_dist[n+1]={0},b_can[n+1]={0};
    int a_dist[n+1]={0},a_can[n+1]={0};

    do_bob(adj,0,1,b_dist,b_can,b_loc);
    do_bob(adj,0,1,a_dist,a_can,a_loc);

    int dist=n+1;
    for(int i=1;i<=n;i++)
    {
        if(a_can[i]==0 || b_can[i]==0) continue;
        temp=a_dist[i]+b_dist[i];
        dist=min(dist,temp);
    }

    if(dist<=da) { cout<<"Alice"<<endl; return; }
    cout<<"Bob"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}