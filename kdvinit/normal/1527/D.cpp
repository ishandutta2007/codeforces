/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5+1;

int par[N];
int siz[N];
int spc[N]={0};
vector<int> adj[N];

void dfs(int p, int c)
{
    par[c]=p;
    siz[c]=1;

    if(c!=0)
    {
        if(p==0) spc[c]=c;
        else spc[c]=spc[p];
    }

    for(auto x: adj[c])
    {
        if(x==p) continue;
        dfs(c, x);
        siz[c]+=siz[x];
    }
}

void solve()
{
    int n;
    cin>>n;

    for(int i=0; i<=n; i++) adj[i].clear();

    for(int i=1; i<n; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(-1, 0);

    int ans[n+1]={0};

    for(auto c: adj[0])
    {
        int x = siz[c];
        ans[0] += (x*(x-1))/2;
    }

    int sc1 = spc[1];

    int x = siz[sc1]-siz[1];
    int y = (x*(x-1))/2;
    int tmp = x;

    for(auto c: adj[0])
    {
        if(c==sc1) continue;
        x=siz[c];
        tmp += x;
        y += (x*(x-1))/2;
    }

    tmp++;
    ans[1] = (tmp*(tmp-1))/2;
    ans[1] -= y;

    siz[0]-=siz[sc1];

    int vis[n+1]={0};
    vis[0]=1;

    int x1 = 1;
    while(par[x1]!=-1)
    {
        vis[x1]=1;
        x1 = par[x1];
    }

    int nd1=1, nd2=0;

    for(int i=2; i<n; i++)
    {
        if(vis[i]==1) continue;

        vis[i]=1;
        x1 = i;
        while(vis[par[x1]]==0)
        {
            x1 = par[x1];
            vis[x1]=1;
        }

        int x2 = par[x1];

        //cout<<i<<" "<<x1<<" "<<x2<<" "<<nd1<<" "<<nd2<<endl;

        if(x2==nd1)
        {
            //cout<<i<<" "<<nd1<<" "<<nd2<<" "<<x2<<endl;

            x = siz[nd2];
            y = siz[nd1]-siz[i];
            ans[i] = x*y;
            nd1=i;
            continue;
        }

        if(x2==nd2)
        {
            //cout<<i<<" "<<nd1<<" "<<nd2<<" "<<x2<<endl;

            x = siz[nd1];
            y = siz[nd2]-siz[i];
            ans[i] = x*y;
            nd2=i;
            continue;
        }

        //cout<<i<<" "<<"Hello"<<endl;

        ans[i] = siz[nd1]*siz[nd2];
        break;
    }

    ans[n]=1;
    for(int i=0; i<n; i++)
    {
        x = adj[i].size();
        if(x>2) ans[n]=0;
    }

    for(int i=0; i<=n; i++) cout<<ans[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}