#include <cmath>
#include<bits/stdc++.h>

using namespace std;
#define int long long

void find_deg(vector< vector<int> >& adj,int par,int chi,int p[])
{
    p[chi]=par;
    for(int i=0;i<adj[chi].size();i++)
    {
        if(adj[chi][i]==par) continue;
        find_deg(adj,chi,adj[chi][i],p);
    }
}

void solve()
{
    int n,x,y;
    cin>>n;

    int w[n+1],sum=0;
    for(int i=1;i<=n;i++) { cin>>w[i]; sum+=w[i]; }

    vector< vector<int> > adj(n+1);
    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int par[n+1]={0};
    find_deg(adj,0,1,par);

    int deg[n+1]={0};
    for(int i=2;i<=n;i++) deg[i]=1;

    for(int i=1;i<=n;i++) deg[par[i]]++;

    int ans[n],cnt=0;
    for(int i=1;i<=n;i++)
    {
        int x=deg[i];
        x--;
        while(x--)
        {
            ans[++cnt]=w[i];
        }
    }

    sort(ans+1,ans+cnt+1);

    cout<<sum<<" ";
    while(cnt!=0)
    {
        sum+=ans[cnt];
        cout<<sum<<" ";
        cnt--;
    }
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}