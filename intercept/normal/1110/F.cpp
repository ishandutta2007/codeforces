#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
using namespace std;
const ll inf=1ll<<60;
const int M=500009;
int n,q;
int L[M],R[M];
struct Segment_tree{
    ll vis[M<<2],mi[M<<2];
    void pu(int now,int l,int r){
        ll &v=vis[now];
        if(v){
            int ls=now<<1,rs=now<<1|1,mid=l+r>>1;
            vis[ls]+=v;
            vis[rs]+=v;
            mi[ls]+=v;
            mi[rs]+=v;
            v=0;
        }
    }
    void pd(int now){
        mi[now]=min(mi[now<<1],mi[now<<1|1]);
    }
    void update(int now,int l,int r,int x,int y,ll v){
        if(x>y)return;
        if(x<=l&&r<=y){
            vis[now]+=v;
            mi[now]+=v;
            return;
        }
        pu(now,l,r);
        int mid=l+r>>1;
        if(x<=mid)update(now<<1,l,mid,x,y,v);
        if(y>mid)update(now<<1|1,mid+1,r,x,y,v);
        pd(now);
    }
    ll query(int now,int l,int r,int x,int y){
        if(x>y)return 0;
        if(x<=l&&r<=y){
            return mi[now];
        }
        pu(now,l,r);
        int mid=l+r>>1;
        ll rex=inf;
        if(x<=mid)rex=min(rex,query(now<<1,l,mid,x,y));
        if(y>mid)rex=min(rex,query(now<<1|1,mid+1,r,x,y));
        return rex;
    }
}T;
vector<int>g[M];
int w[M];
void dfs(int u,ll val){
    L[u]=R[u]=u;
    if(g[u].size()==0)T.update(1,1,n,u,u,val-inf);
    for(auto v:g[u]){
        dfs(v,val+w[v]);
        L[u]=min(L[u],L[v]);
        R[u]=max(R[u],R[v]);
    }
}
struct P{
    int l,r,id;
};
vector<P>op[M];
ll ans[M];
void solve(int u){
    for(auto o:op[u]){
        ans[o.id]=T.query(1,1,n,o.l,o.r);
    }
    for(auto v:g[u]){
        T.update(1,1,n,1,L[v]-1,w[v]);
        T.update(1,1,n,R[v]+1,n,w[v]);
        T.update(1,1,n,L[v],R[v],-w[v]);
        solve(v);
        T.update(1,1,n,1,L[v]-1,-w[v]);
        T.update(1,1,n,R[v]+1,n,-w[v]);
        T.update(1,1,n,L[v],R[v],w[v]);
    }
}
int main(){
    scanf("%d%d",&n,&q);
    for(int i=2;i<=n;++i){
        int p;
        scanf("%d%d",&p,&w[i]);
        g[p].eb(i);
    }
    for(int i=1;i<=n;++i)T.update(1,1,n,i,i,inf);
    dfs(1,0);
    for(int i=1;i<=q;++i){
        int u,l,r;
        scanf("%d%d%d",&u,&l,&r);
        op[u].eb(P{l,r,i});
    }
    solve(1);
    for(int i=1;i<=q;++i)printf("%lld\n",ans[i]);
    return 0;
}
/*
3
1 1 2

*/