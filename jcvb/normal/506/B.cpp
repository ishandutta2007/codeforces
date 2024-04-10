#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
int n,m;
struct edge{
    int v,next;
}e[100005];int etot=0;
int g[100005];
void ae(int u,int v){
    e[etot].v=v;e[etot].next=g[u];g[u]=etot++;
}
int id[100005]={0};
int dfn[100005]={0},low[100005]={0};
int stk[100005],inst[100005]={0},top=0;
int ind=0;
int sz[100005]={0};
int sccnum=0;
void dfs(int u){
    dfn[u]=low[u]=++ind;
    inst[stk[++top]=u]=1;
    for (int i=g[u];~i;i=e[i].next){
        int v=e[i].v;
        if(!dfn[v]){
            dfs(v);
            low[u]=min(low[u],low[v]);
        }else if(inst[v]) low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u]){
        ++sccnum;
        while(stk[top]!=u){
            id[stk[top]]=sccnum;
            inst[stk[top--]]=0;
            sz[sccnum]++;
        }
        id[u]=sccnum;
        sz[sccnum]++;
        inst[stk[top--]]=0;
    }
}


int fa[100005];
int gf(int x){
    return x==fa[x]?x:fa[x]=gf(fa[x]);
}
int icnt[100005]={0};
int main()
{
    memset(g,-1,sizeof(g));
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++){
        int x,y;scanf("%d%d",&x,&y);
        ae(x,y);
    }
    for (int i=1;i<=n;i++)if(!dfn[i])dfs(i);
    int ans=0;
    for (int i=1;i<=sccnum;i++){
        if(sz[i]>1)ans+=sz[i];
        fa[i]=i;
    }
    for (int u=1;u<=n;u++){
        for (int i=g[u];~i;i=e[i].next){
            int v=e[i].v;
            if(id[u]==id[v])continue;
            fa[gf(id[u])]=gf(id[v]);
        }
    }
    for (int i=1;i<=sccnum;i++)icnt[gf(i)]|=(sz[i]>1);
    ans=n;
    for (int i=1;i<=sccnum;i++)if(gf(i)==i && !icnt[i])ans--;
    printf("%d\n",ans);
    return 0;
}