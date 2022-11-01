#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,tot,head[N],d[N],f[N],sum[N],nex[N<<1],to[N<<1];
void add(int u,int v){to[++tot]=v;nex[tot]=head[u];head[u]=tot;}
bool vis[N];
void dfs(int u,int p)
{
    for(int i=head[u];i;i=nex[i])
    {
        int v=to[i];
        if(d[v]==1) sum[u]++;
        if(v==p)continue;
        f[v]=f[u]^1;
        dfs(v,u);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int u,v;scanf("%d%d",&u,&v);
        add(u,v);add(v,u);d[u]++;d[v]++;
    }
    f[1]=2;
    dfs(1,0);
    int mn=0,mx=n-1;
    for(int i=1;i<=n;i++)
        if(d[i]!=1&&sum[i])
            mx-=sum[i]-1;
        else if(d[i]==1) mn|=f[i]-1;
    if(mn!=3) mn=1;
    printf("%d %d\n",mn,mx);
}