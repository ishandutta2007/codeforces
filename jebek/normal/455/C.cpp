#include <iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cstdio>

using namespace std;

const long long MAXN=400000;
bool mark[MAXN],mark1[MAXN];
long long n,m,q,h[MAXN],par1[MAXN],MAX,v1,v2,t[MAXN];
vector<long long>G[MAXN];

long long findpar(long long v)
{
    if(par1[v]==v)
        return v;
    par1[v]=findpar(par1[v]);
    return par1[v];
}

void dfs1(long long v)
{
    mark1[v]=true;
    par1[v]=v2;
    if(h[v]>=MAX)
    {
        v1=v;
        MAX=h[v];
    }
    for(long long i=0;i<G[v].size();i++)
    {
        long long u=G[v][i];
        if(!mark1[u])
        {
            h[u]=h[v]+1;
            dfs1(u);
        }
    }
}

void dfs(long long v)
{
    mark[v]=true;
    if(h[v]>=MAX)
    {
        v1=v;
        MAX=h[v];
    }
    for(long long i=0;i<G[v].size();i++)
    {
        long long u=G[v][i];
        if(!mark[u])
        {
            h[u]=h[v]+1;
            dfs(u);
        }
    }
    h[v]=0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin>>n>>m>>q;
    for(long long i=0;i<m;i++)
    {
        long long v,u;
        cin>>v>>u;
        G[v].push_back(u);
        G[u].push_back(v);
    }
    for(long long i=1;i<=n;i++)
    {
        if(!mark[i])
        {
            MAX=0;
            dfs(i);
            h[v1]=0;
            v2=v1;
            MAX=0;
            dfs1(v1);
            t[v2]=MAX;
        }
    }
    for(long long i=0;i<q;i++)
    {
        long long t1;
        cin>>t1;
        if(t1==1)
        {
            long long v;
            cin>>v;
            v=findpar(v);
            cout<<t[v]<<endl;
            continue;
        }
        long long v,u;
        cin>>v>>u;
        v=findpar(v);
        u=findpar(u);
        if(v==u)
            continue;
        par1[v]=u;
        t[u]=max((t[v]+1)/2+(t[u]+1)/2+1,max(t[v],t[u]));
  //      cout<<u<<" "<<t[u]<<endl;
    }
}