#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,q,dep[N],lg[N],fa[N][20],tot,head[N],nex[N<<1],to[N<<1];
void add(int u,int v){to[++tot]=v;nex[tot]=head[u];head[u]=tot;}
void dfs(int u,int p)
{
    dep[u]=dep[p]+1;
    fa[u][0]=p;
    for(int i=1;1<<i<=dep[p];i++)
        fa[u][i]=fa[fa[u][i-1]][i-1];
    for(int i=head[u];i;i=nex[i])
    {
        int v=to[i];if(v==p)continue;
        dfs(v,u);
    }
}
int LCA(int u,int v)
{
    if(dep[u]<dep[v]) swap(u,v);
    while(dep[u]>dep[v])
        u=fa[u][lg[dep[u]-dep[v]]];
    if(u==v) return u;
    for(int i=lg[dep[u]];i>=0;i--)
        if(fa[u][i]!=fa[v][i])
        u=fa[u][i],v=fa[v][i];
    return fa[u][0];
}
int dis(int x,int y)
{
    return dep[x]+dep[y]-2*dep[LCA(x,y)];
}
bool judge(int x,int k)
{
    return x<=k&&(x%2==k%2);
}
int main()
{
    for(int i=1;i<N;i++) lg[i]=lg[i-1]+(1<<lg[i-1]==i);
    for(int i=1;i<N;i++) lg[i]--;
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int u,v;scanf("%d%d",&u,&v);
        add(u,v);add(v,u);
    }
    dfs(1,0);
    scanf("%d",&q);
    while(q--)
    {
        int x,y,a,b,k;
        scanf("%d%d%d%d%d",&x,&y,&a,&b,&k);
        int xy=dis(x,y),ax=dis(a,x);
        int bx=dis(b,x),ab=dis(a,b);
        int by=dis(b,y),ay=dis(a,y);
        bool flag=false;
        //cout<<ax<<' '<<by<<' '<<dep[b]+dep[y]<<' '<<LCA(b,y)<<endl;
        if(judge(ab,k)) flag=true;
        if(judge(ax+xy+by,k)) flag=true;
        if(judge(ax+1+by,k)) flag=true;
        if(judge(ay+xy+bx,k)) flag=true;
        if(judge(ay+1+bx,k)) flag=true;
        if(judge(ax+bx,k)) flag=true;
        if(judge(ay+by,k)) flag=true;
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
}