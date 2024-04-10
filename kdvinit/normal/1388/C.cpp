/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define int long long

void do_peo_pas(vector< vector<int> >& adj,int par,int chi,int peo[])
{
    for(int i=0;i<adj[chi].size();i++)
    {
        if(adj[chi][i]==par) continue;
        do_peo_pas(adj,chi,adj[chi][i],peo);
        peo[chi]+=peo[adj[chi][i]];
    }
}

bool hap_pos(vector< vector<int> >& adj,int par,int chi,int tru_hap[])
{
    int hap_pass=0;
    for(int i=0;i<adj[chi].size();i++)
    {
        if(adj[chi][i]==par) continue;
        if(hap_pos(adj,chi,adj[chi][i],tru_hap)) { hap_pass+=tru_hap[adj[chi][i]]; continue; }
        return false;
    }

    if(tru_hap[chi]<hap_pass) return false;
    return true;
}

void solve()
{
    int n,m,x,y;
    cin>>n>>m;

    int peo[n+1],hap_ind[n+1],tru_hap[n+1];
    for(int i=1;i<=n;i++) cin>>peo[i];
    for(int i=1;i<=n;i++) cin>>hap_ind[i];

    vector< vector<int> > adj(n+1);
    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    do_peo_pas(adj,0,1,peo);
    for(int i=1;i<=n;i++) tru_hap[i]=hap_ind[i]+peo[i];

    for(int i=1;i<=n;i++)
    {
        if(tru_hap[i]%2==1 || tru_hap[i]<0 || tru_hap[i]>2*peo[i]) { cout<<"NO"<<endl; return; }
        tru_hap[i]/=2;
    }

    if(hap_pos(adj,0,1,tru_hap)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}