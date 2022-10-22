#include<bits/stdc++.h>
#define LL long long
#define PB push_back
#define PII pair<int,int>
using namespace std;
const int INF=0x3f3f3f3f;
const int N=5010,M=N*400,mod=1e9+7;
int n,m;
int a[N];
vector<int>G[N];
int siz[N],fa[N],son[N],de[N];
int cnt,dfn[N],top[N],ed[N];
void dfs1(int x){
    siz[x]=1;
    son[x]=-1;
    for(int i=0;i<G[x].size();i++){
        int &y=G[x][i];
        if(!de[y]){
            fa[y]=x;
            de[y]=de[x]+1;
            dfs1(y);
            siz[x]+=siz[y];
            if(son[x]==-1||siz[y]>siz[son[x]])son[x]=y;
        }
    }
}
void dfs2(int x,int t){
    top[x]=t;
    dfn[x]=++cnt;
    if(siz[x]==1){
        ed[x]=cnt;return;
    }
    dfs2(son[x],t);
    for(int i=0;i<G[x].size();i++){
        int &y=G[x][i];
        if(y!=fa[x]&&y!=son[x])dfs2(y,y);
    }
    ed[x]=cnt;
}
struct edge{
    int u,v;
}p[N];
struct node{
    int u,v,x;
}q[N];
int mn[N][N];
void upd(int u,int v,int x){
    while(u!=v){
        if(de[u]<de[v])swap(u,v);
        mn[u][fa[u]]=mn[fa[u]][u]=max(mn[u][fa[u]],x);
        u=fa[u];
    }
}
int query(int u,int v){
    int re=1e6;
    while(u!=v){
        if(de[u]<de[v])swap(u,v);
        re=min(re,mn[u][fa[u]]);
        u=fa[u];
        //mn[u][fa[u]]=mn[fa[u]][u]=max(mn[u][fa[u]],x);
    }
    return re;
}
int main()
{

    cin>>n;
    for(int i=1,u,v;i<n;i++){
        scanf("%d%d",&p[i].u,&p[i].v);
        G[p[i].u].PB(p[i].v);
        G[p[i].v].PB(p[i].u);
    }
    de[1]=1;
    dfs1(1);
    dfs2(1,1);
    cin>>m;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&q[i].u,&q[i].v,&q[i].x);
        upd(q[i].u,q[i].v,q[i].x);
    }
    for(int i=1,y;i<=m;i++){
        y=query(q[i].u,q[i].v);
        if(y!=q[i].x){
            cout<<-1;
            return 0;
        }
    }
    for(int i=1;i<n;i++){
        mn[p[i].u][p[i].v]=max(mn[p[i].u][p[i].v],1);
        printf("%d ",mn[p[i].u][p[i].v]);
    }
    return 0;
}
/*
*/