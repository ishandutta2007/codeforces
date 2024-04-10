#include <iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

typedef pair<int,int> pii;
vector<pii>e;
const int MOD=1e9+7,MAXN=200000;
bool mark1,mark[MAXN];
int n,m,h[MAXN],c[MAXN],t,ind;
long long ans;
vector<int>G[MAXN],G1[MAXN];

void dfs1(int v)
{
    mark[v]=true;
    for(int i=0;i<G1[v].size();i++)
    {
        int u=G1[v][i];
        if(!mark[u])
        {
            h[u]=1-h[v];
            dfs1(u);
        }
        else if(h[v]==h[u])
            mark1=true;
    }
}

void dfs(int v)
{
    mark[v]=true;
    c[v]=ind;
    for(int i=0;i<G[v].size();i++)
    {
        int u=G[v][i];
        if(!mark[u])
            dfs(u);
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int v,u,w;
        cin>>v>>u>>w;
        if(w==1)
        {
            G[v].push_back(u);
            G[u].push_back(v);
        }
        else
            e.push_back(pii(v,u));
    }
    for(int i=1;i<=n;i++)
        if(!mark[i])
        {
            ind++;
            dfs(i);
        }
    for(int i=0;i<e.size();i++)
    {
        int v=e[i].first,u=e[i].second;
        if(c[v]==c[u])
        {
            cout<<0<<endl;
            return 0;
        }
        G1[c[v]].push_back(c[u]);
        G1[c[u]].push_back(c[v]);
    }
    memset(mark,false,sizeof mark);
    for(int i=1;i<=ind;i++)
        if(!mark[i])
            dfs1(i),t++;
    if(mark1)
        cout<<0<<endl;
    else
    {
        ans=1;
        for(int i=1;i<t;i++)
            ans=(ans*2)%MOD;
        cout<<ans<<endl;
    }
}