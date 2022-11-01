#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN=200000;
bool mark[MAXN];
vector<int>G[MAXN];
int n,m,par[MAXN][25],h[MAXN],t[MAXN],ans;

void dfs(int v)
{
    mark[v]=true;
    for(int i=0;i<G[v].size();i++)
    {
        int u=G[v][i];
        if(!mark[u])
        {
            par[u][0]=v;
            for(int j=1;j<=20;j++)
                par[u][j]=par[par[u][j-1]][j-1];
            h[u]=h[v]+1;
            dfs(u);
            t[v]+=t[u];
        }
    }
    t[v]++;
}

int findpar(int v,int u)
{
    for(int i=20;i>-1;i--)
        if(h[par[v][i]]>=h[u])
            v=par[v][i];
    for(int i=20;i>-1;i--)
        if(par[v][i]!=par[u][i])
            v=par[v][i],u=par[u][i];
    if(v!=u)
        v=par[v][0];
    return v;
}

int fpar(int v,int u)
{
    for(int i=20;i>-1;i--)
        if(h[par[v][i]]>u)
            v=par[v][i];
    return v;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int v,u;
        cin>>v>>u;
        G[v].push_back(u);
        G[u].push_back(v);
    }
    dfs(1);
    int q;
    cin>>q;
    for(int qw=0;qw<q;qw++)
    {
        int v,u,w,v1,u1;
        ans=0;
        cin>>v>>u;
        if(h[v]%2!=h[u]%2)
        {
            cout<<0<<endl;
            continue;
        }
        if(v==u)
        {
            cout<<n<<endl;
            continue;
        }
        if(h[v]<h[u])
            swap(v,u);
        w=findpar(v,u);
        if(h[v]==h[u])
        {
            ans=n;
            v1=fpar(v,h[w]);
            u1=fpar(u,h[w]);
            ans-=t[v1]+t[u1];
        }
        else
        {
            v1=fpar(v,h[w]+(h[v]-h[u])/2);
            w=par[v1][0];
            ans=t[w]-t[v1];
        }
        cout<<ans<<endl;
    }
}