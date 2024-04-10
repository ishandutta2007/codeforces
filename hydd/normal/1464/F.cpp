//
// Created by hydd on 2022/7/4.
//
/* LCAd
 */
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,q; multiset<pii> s;
vector<int> vec[210000];
int dep[210000],sz[210000];
int cnt,dfn[210000],num[210000],fa[20][210000];
int jump(int u,int d){
    if (d>=dep[u]) return 1;
    for (int i=18;i>=0;i--)
        if (d&(1<<i)) u=fa[i][u];
    return u;
}
int LCA(int u,int v){
    if (dep[u]<dep[v]) swap(u,v);
    u=jump(u,dep[u]-dep[v]);
    if (u==v) return u;

    for (int i=18;i>=0;i--)
        if (fa[i][u]!=fa[i][v]) u=fa[i][u],v=fa[i][v];
    return fa[0][u];
}
int dis(int u,int v){ return dep[u]+dep[v]-(dep[LCA(u,v)]<<1);}
struct FenwickTree{
    int tree[210000];
    void add(int u,int c){
        int x=dfn[u];
        for (;x<=n;x+=x&-x) tree[x]+=c;
    }
    int query(int u){
        int res=0,x;
        for (x=dfn[u]+sz[u]-1;x;x-=x&-x) res+=tree[x];
        for (x=dfn[u]-1;x;x-=x&-x) res-=tree[x];
        return res;
    }
} T1;
struct node{
    int x,y,d;
    node(){}
    node(int _x,int _y,int _d):x(_x),y(_y),d(_d){}
    bool operator<(const node &a) const{ return d<a.d;}
    node operator+(const node &a){
        if (!x) return a; if (!a.x) return *this;
        node res=max(*this,a);
        res=max(res,node(x,a.x,dis(x,a.x)));
        res=max(res,node(x,a.y,dis(x,a.y)));
        res=max(res,node(y,a.x,dis(y,a.x)));
        res=max(res,node(y,a.y,dis(y,a.y)));
        return res;
    }
};
struct SegmentTree{
#define ls now<<1
#define rs now<<1|1
    node tree[810000]; int tot[210000];
    void change(int now,int l,int r,int x,int c){
        if (l==r){
            tot[l]+=c;
            if (tot[l]) tree[now]=node(num[l],num[l],0);
            else tree[now]=node(0,0,0);
            return;
        }
        int mid=(l+r)>>1;
        if (x<=mid) change(ls,l,mid,x,c);
        else change(rs,mid+1,r,x,c);
        tree[now]=tree[ls]+tree[rs];
    }
    node query(int now,int l,int r,int x,int y){
        if (x<=l&&r<=y) return tree[now];
        int mid=(l+r)>>1; node res=node(0,0,0);
        if (x<=mid) res=res+query(ls,l,mid,x,y);
        if (y>mid) res=res+query(rs,mid+1,r,x,y);
        return res;
    }

    void add(int u,int c){ change(1,1,n,dfn[u],c);}
    node query(int u){
        return query(1,1,n,dfn[u],dfn[u]+sz[u]-1);
    }
#undef ls
#undef rs
} T2;
void dfs(int u,int f){
    fa[0][u]=f; dep[u]=dep[f]+1;
    for (int i=1;i<=18;i++) fa[i][u]=fa[i-1][fa[i-1][u]];
    dfn[u]=++cnt; num[cnt]=u; sz[u]=1;
    for (int v:vec[u]){
        if (v==f) continue;
        dfs(v,u); sz[u]+=sz[v];
    }
}
void change(int op){
    int u,v; cin>>u>>v;
    int w=LCA(u,v);
    if (op==1) s.insert(pii(dep[w],w));
    else s.erase(s.find(pii(dep[w],w)));

    cnt+=op;
    T1.add(u,op); T1.add(v,op); T1.add(w,-op);
    T2.add(w,op);
}
int query(){
    int d; cin>>d;
    int u=jump(s.rbegin()->second,d),v=jump(u,d);
    if (T1.query(v)!=cnt) return false;

    node res=T2.query(v);
    return dis(u,res.x)<=d&&dis(u,res.y)<=d;
}
int main(){
    cin>>n>>q; int u,v;
    for (int i=1;i<n;i++){
        cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    dfs(1,0);
    int op; cnt=0;
    while (q--){
        cin>>op;
        if (op==3) cout<<(query()?"Yes":"No")<<'\n';
        else change(op==1?1:-1);
    }
    return 0;
}