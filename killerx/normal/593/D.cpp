#include<bits/stdc++.h>
using namespace std;
const int N=1<<18;
typedef long long ll;
const ll linf=1.5e18;
int n,q;
int dep[N],fa[N],sz[N];
int id[N],top[N],dfn[N],Tm,cnt;
int head[N],nxt[N<<1],to[N<<1],tot;
ll cst[N<<1];
void dfs(int u,int p){
    sz[u]=1;fa[u]=p;
    for(int e=head[u];~e;e=nxt[e]){
        int v=to[e];
        if(v!=p){
            dep[v]=dep[u]+1;
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
    id[u]=cnt;dfn[u]=Tm++;
    if(!~top[cnt])top[cnt]=u;
    if(~mx)hld(mx,u);
    for(int e=head[u];~e;e=nxt[e]){
        int v=to[e];
        if(v!=p&&v!=mx)++cnt,hld(v,u);
    }
}
void add(int u,int v,ll w){
    nxt[tot]=head[u];head[u]=tot;
    to[tot]=v;cst[tot]=w;++tot;
}
ll Mul(ll x,ll y){
    if(x==linf)return linf;
    if(y==linf)return linf;
    if(log10(x)+log10(y)>18.2)return linf;
    if(x*y>linf)return linf;
    return x*y;
}
struct SegT{
    ll mul[N<<1];
    SegT(){
        for(int i=1;i<(N<<1);++i)
            mul[i]=1;
    }
    void upd(int i,ll x){
        mul[i+=N]=x;
        for(i>>=1;i;i>>=1){
            mul[i]=Mul(mul[i<<1],mul[i<<1|1]);
        }
    }
    ll qry(int l,int r){
        ll ans=1LL;
        for(l+=N,r+=N;l^r;l>>=1,r>>=1){
            if(l&1)ans=Mul(ans,mul[l++]);
            if(r&1)ans=Mul(ans,mul[--r]);
        }
        return ans;
    }
}segt;
ll qry(int u,int v){
    ll ans=1LL;
    while(id[u]!=id[v]){
        if(dep[top[id[u]]]<dep[top[id[v]]])swap(u,v);
        ans=Mul(ans,segt.qry(dfn[top[id[u]]],dfn[u]+1));
        u=fa[top[id[u]]];
    }
    if(dep[u]>dep[v])swap(u,v);
    ans=Mul(ans,segt.qry(dfn[u]+1,dfn[v]+1));
    return ans;
}
int main(){
    memset(head,-1,sizeof head);
    memset(top,-1,sizeof top);
    scanf("%d%d",&n,&q);
    for(int i=1;i<n;++i){
        int u,v;ll w;scanf("%d%d%lld",&u,&v,&w);
        --u,--v;add(u,v,w);add(v,u,w);
    }
    dfs(0,-1);
    hld(0,-1);
    for(int i=0;i<n;++i){
        for(int e=head[i];~e;e=nxt[e]){
            int j=to[e];
            if(j!=fa[i]){
                segt.upd(dfn[j],cst[e]);
            }
        }
    }
    for(;q--;){
        int tp;scanf("%d",&tp);
        if(tp==1){
            int a,b;ll y;scanf("%d%d%lld",&a,&b,&y);
            --a,--b;printf("%lld\n",y/qry(a,b));
        }else{
            int p;ll x;scanf("%d%lld",&p,&x);
            --p;int u=to[p<<1],v=to[p<<1|1];
            if(u==fa[v])swap(u,v);
            segt.upd(dfn[u],x);
        }
        // for(int i=0;i<n;++i)cerr<<segt.qry(dfn[i],dfn[i]+1)<<" ";cerr<<endl;
    }
    return 0;
}