#include<bits/stdc++.h>
using namespace std;
const int N=1<<17;
int head[N],nxt[N<<1],to[N<<1],tot;
int fa[N],n,k,dep[N],sz[N];
int dfn[N],id[N],top[N],cnt,Tm;
void add(int u,int v){
    nxt[tot]=head[u];head[u]=tot;
    to[tot]=v;++tot;
}
void dfs(int u,int p){
    dep[u]=dep[p]+1;
    fa[u]=p;sz[u]=1;
    for(int e=head[u];~e;e=nxt[e]){
        int v=to[e];
        if(v!=p){
            dfs(v,u);
            sz[u]+=sz[v];
        }
    }
}
void hld(int u,int p){
    int mx=-1;
    for(int e=head[u];~e;e=nxt[e]){
        int v=to[e];
        if(v!=p){
            if(!~mx||sz[v]>sz[mx])mx=v;
        }
    }
    id[u]=cnt;
    dfn[u]=Tm++;
    if(!~top[cnt])top[cnt]=u;
    if(~mx)hld(mx,u);
    for(int e=head[u];~e;e=nxt[e]){
        int v=to[e];
        if(v!=p&&v!=mx){
            ++cnt;hld(v,u);
        }
    }
}
struct BIT{
    int sum[N];
    BIT(){memset(sum,0,sizeof sum);}
    void upd(int x,int v){for(++x;x<N;x+=x&-x)sum[x]+=v;}
    int qry(int x){int ans=0;for(++x;x;x-=x&-x)ans+=sum[x];return ans;}
}bit;
void work(int u,int v){
    while(id[u]!=id[v]){
        if(dep[top[id[u]]]<dep[top[id[v]]])swap(u,v);
        // printf("%d %d\n",top[id[u]],u);
        bit.upd(dfn[top[id[u]]],1);
        bit.upd(dfn[u]+1,-1);
        u=fa[top[id[u]]];
    }
    if(dep[u]>dep[v])swap(u,v);
    // printf("%d %d\n",u,v);
    bit.upd(dfn[u]+1,1);
    bit.upd(dfn[v]+1,-1);
}
int ans[N];
int main(){
    memset(top,-1,sizeof top);
    memset(head,-1,sizeof head);
    scanf("%d",&n);
    for(int i=1;i<n;++i){
        int u,v;scanf("%d%d",&u,&v);
        --u,--v;add(u,v);add(v,u);
    }
    dfs(0,-1);
    hld(0,-1);
    scanf("%d",&k);
    for(;k--;){
        int u,v;scanf("%d%d",&u,&v);
        --u,--v;work(u,v);
    }
    for(int i=0;i<n;++i){
        for(int e=head[i];~e;e=nxt[e]){
            int j=to[e];
            if(i==fa[j]){
                // printf("%d %d %d\n",i,j,e);
                ans[e>>1]=bit.qry(dfn[j]);
            }
        }
    }
    for(int i=0;i<n-1;++i){
        printf("%d",ans[i]);
        if(i+1==n-1)putchar('\n');
        else putchar(' ');
    }
    return 0;
}