#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
using namespace std;
typedef long long ll;
typedef double db;
void gn(int &x){
    int sg=1;char tmp;while(((tmp=getchar())<'0'||tmp>'9')&&tmp!='-');
    if(tmp=='-')sg=-1,x=0;else x=tmp-'0';
    while((tmp=getchar())>='0'&&tmp<='9')x=x*10+tmp-'0';
    x*=sg;
}
void gn(ll &x){
    int sg=1;char tmp;while(((tmp=getchar())<'0'||tmp>'9')&&tmp!='-');
    if(tmp=='-')sg=-1,x=0;else x=tmp-'0';
    while((tmp=getchar())>='0'&&tmp<='9')x=x*10+tmp-'0';
    x*=sg;
}
const int mo=1000000007;
int qp(int a,ll b){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}

int n,m;
struct edge{int v,next;}e[400005];int etot=0;int g[200005];
void ae(int u,int v){e[etot].v=v;e[etot].next=g[u];g[u]=etot++;}
int dfn[200005]={0},low[200005];int ind=0;
int stk[200005],inst[200005]={0},top=0;
int id[200005]={0};int bcctot=0;
void dfs(int u,int ii=-1){
    dfn[u]=low[u]=++ind;
    inst[u]=1;stk[++top]=u;
    for (int i=g[u];~i;i=e[i].next)if(i!=ii){
        if(!dfn[e[i].v]){
            dfs(e[i].v,i^1);            
            low[u]=min(low[u],low[e[i].v]);
        }else if(inst[e[i].v])low[u]=min(low[u],dfn[e[i].v]);
    }
    if(dfn[u]==low[u]){
        bcctot++;
        while(stk[top]!=u){
            inst[stk[top]]=0;
            id[stk[top--]]=bcctot;
        }
        inst[stk[top]]=0;
        id[stk[top--]]=bcctot;
    }
}
int uu[222222],vv[222222];


int vis[222222];int vtot=0;
int qu[222222];
int pre[222222][20];
int h[222222];
void bfs(int rt){
    int p=0,q=0;
    pre[rt][0]=h[rt]=0;
    vtot++;
    qu[q++]=rt;
    vis[rt]=vtot;
    while(p!=q){
        int u=qu[p++];
        for (int i=g[u];~i;i=e[i].next)if(e[i].v!=pre[u][0]){
            qu[q++]=e[i].v;
            vis[e[i].v]=vtot;
            pre[e[i].v][0]=u;
            h[e[i].v]=h[u]+1;
        }
    }
}

int fa[222222];
struct quer{
    int x,y;
}qr[222222];
int lca(int a,int b){
    if(h[a]<h[b])swap(a,b);
    for (int i=0;h[a]-h[b];i++)if(h[a]-h[b]&1<<i)a=pre[a][i];
    if(a==b)return a;
    for (int i=19;i>=0;i--)if(pre[a][i]!=pre[b][i])a=pre[a][i],b=pre[b][i];
    return pre[a][0];
}

int up[222222]={0};

int gf(int x){return x==fa[x]?x:fa[x]=gf(fa[x]);}
int main()
{
    int q;
    memset(g,-1,sizeof(g));
    scanf("%d%d%d",&n,&m,&q);
    while(m--){
        int x,y;
        scanf("%d%d",&x,&y);
        ae(x,y);
        ae(y,x);
    }
    m=0;
    for (int i=1;i<=n;i++)if(!dfn[i])dfs(i);
    for (int u=1;u<=n;u++)
        for (int i=g[u];~i;i=e[i].next)if(u<e[i].v && id[u]!=id[e[i].v]){
            uu[++m]=id[u];vv[m]=id[e[i].v];
        }
    memset(g,-1,sizeof(g));
    etot=0;
    for (int i=1;i<=m;i++)ae(uu[i],vv[i]),ae(vv[i],uu[i]);
    n=bcctot;
    for (int i=1;i<=n;i++)if(!vis[i]){
        bfs(i);
    }
    for (int i=1;i<=19;i++)
        for (int u=1;u<=n;u++)pre[u][i]=pre[pre[u][i-1]][i-1];

    for (int i=1;i<=q;i++){
        scanf("%d%d",&qr[i].x,&qr[i].y);
        qr[i].x=id[qr[i].x];
        qr[i].y=id[qr[i].y];
        if(vis[qr[i].x]!=vis[qr[i].y]){
            printf("No\n");
            return 0;
        }
    }
    for (int i=1;i<=n;i++)fa[i]=i;
    for (int i=1;i<=q;i++){
        int l=lca(qr[i].x,qr[i].y),x=qr[i].x;
        while(h[x]>h[l]){
            if(gf(x)==x){
                up[x]|=1;
                fa[x]=gf(pre[x][0]);
            }
            x=gf(x);
        }
    }
    for (int i=1;i<=n;i++)fa[i]=i;
    for (int i=1;i<=q;i++){
        int l=lca(qr[i].x,qr[i].y),x=qr[i].y;
        while(h[x]>h[l]){
            if(gf(x)==x){
                up[x]|=2;
                fa[x]=gf(pre[x][0]);
            }
            x=gf(x);
        }
    }
    for (int i=1;i<=n;i++)if(up[i]==3){
        printf("No\n");
        return 0;
    }
    printf("Yes\n");
    return 0;
}