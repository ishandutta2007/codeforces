#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,q,C,c[51000],fa[51000],v[51000];
vector<int> vec[51000];

int cnt,sz[51000],son[51000],top[51000],dfn[51000];
void dfs(int u,int f){
    sz[u]=1;
    for (int v:vec[u]){
        if (v==f) continue;
        dfs(v,u); sz[u]+=sz[v];
        if (sz[v]>sz[son[u]]) son[u]=v;
    }
}
void dfs2(int u,int t){
    dfn[u]=++cnt; top[u]=t;
    if (son[u]) dfs2(son[u],t);
    for (int v:vec[u]){
        if (v==fa[u]||v==son[u]) continue;
        dfs2(v,v);
    }
}


int rt[51000]; int ls[11000000],rs[11000000];
ll sum1[11000000],sum2[11000000]; int tag[11000000];
void update(int now,int l,int r,ll v){
    sum2[now]+=2*sum1[now]*v+(r-l+1)*v*v;
    sum1[now]+=(r-l+1)*v;
}
void change(int &now,int l,int r,int x,int y,int v){
    if (!now) now=++cnt;
    if (x<=l&&r<=y){
        update(now,l,r,v); tag[now]+=v;
        return;
    }
    int mid=(l+r)>>1;
    if (x<=mid) change(ls[now],l,mid,x,y,v);
    if (y>mid) change(rs[now],mid+1,r,x,y,v);
    sum1[now]=sum1[ls[now]]+sum1[rs[now]];
    sum2[now]=sum2[ls[now]]+sum2[rs[now]];
    update(now,l,r,tag[now]);
}
void change(int x,int v){
    int c=::c[x];
    while (x){
        change(rt[c],1,n,dfn[top[x]],dfn[x],v);
        x=fa[top[x]];
    }
}
double query(int x){
    return 1.0*(1ll*n*C*C-2ll*v[x]*C*sum1[rt[x]]+1ll*v[x]*v[x]*sum2[rt[x]])/n;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>m>>q>>C;
    for (int i=1;i<=n;i++) cin>>c[i];
    for (int i=2;i<=n;i++){
        cin>>fa[i];
        vec[fa[i]].push_back(i);
    }
    for (int i=1;i<=m;i++) cin>>v[i];
    dfs(1,0); dfs2(1,1);

    for (int i=1;i<=n;i++) change(i,1);
    int op,x,y; cout<<fixed<<setprecision(10);
    while (q--){
        cin>>op;
        if (op==1){
            cin>>x>>y;
            change(x,-1);
            c[x]=y; change(x,1);
        } else{
            cin>>x;
            cout<<query(x)<<'\n';
        }
    }
    return 0;
}