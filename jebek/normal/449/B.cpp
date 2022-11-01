#include <iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>
#include<cstdio>

using namespace std;
typedef pair<long long,long long> pii;
set<pii>s;
const long long MAXN=200000;
long long dis[MAXN],n,m,q,a[MAXN],b[MAXN],t[MAXN],MIN[MAXN],ans;
vector<long long>G[MAXN],par[MAXN],W[MAXN];

void dijkstra()
{
    memset(dis,127,sizeof dis);
    dis[1]=0;
    s.insert(pii(dis[1],1));
    while(s.size())
    {
        long long v=s.begin()->second;
        s.erase(s.begin());
        for(long long i=0;i<G[v].size();i++)
        {
            long long u=G[v][i],w=W[v][i];
            if(dis[v]+w<dis[u])
            {
                s.erase(pii(dis[u],u));
                dis[u]=dis[v]+w;
                s.insert(pii(dis[u],u));
                par[u].clear();
            }
            if(dis[v]+w==dis[u])
                par[u].push_back(v);
        }
    }
}

int main()
{
    scanf("%lld %lld %lld",&n,&m,&q);
    for(long long i=0;i<m;i++)
    {
        long long v,u,w;
        scanf("%lld %lld %lld",&v,&u,&w);
        G[v].push_back(u);
        G[u].push_back(v);
        W[v].push_back(w);
        W[u].push_back(w);
    }
    memset(MIN,127,sizeof MIN);
    memset(t,-1,sizeof t);
    for(long long i=0;i<q;i++)
    {
        long long u,w;
        scanf("%lld %lld",&u,&w);
        a[i]=u,b[i]=w;
        MIN[u]=min(MIN[u],w);
        if(t[u]!=-1)
            ans++;
        t[u]=i;
    }
    for(long long i=2;i<=n;i++)
        if(t[i]!=-1)
        {
            long long v=1,u=i,w=MIN[i];
            G[v].push_back(u);
            G[u].push_back(v);
            W[v].push_back(w);
            W[u].push_back(w);
        }
    dijkstra();
    for(long long i=0;i<q;i++)
        if(t[a[i]]==i)
            if(dis[a[i]]<MIN[a[i]] || par[a[i]].size()>1)
                ans++;
    printf("%lld\n",ans);
}