#include<bits/stdc++.h>
#define ls now<<1
#define rs now<<1|1
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
int n,m,q,cnt;
vector<int> vec[210000],bcc[210000];
int w[210000]; multiset<int> s[210000];

namespace Tarjan{
    int tot,dfn[210000],low[210000];
    int top,s[210000];
    void tarjan(int u,int f){
        dfn[u]=low[u]=++tot;
        s[++top]=u;
        for (int v:vec[u]){
            if (v==f) continue;
            if (!dfn[v]){
                tarjan(v,u);
                low[u]=min(low[u],low[v]);
                if (low[v]>=dfn[u]){
                    int w; cnt++;
                    do{
                        w=s[top--];
                        bcc[cnt].push_back(w);
                    } while (w!=v);
                    bcc[cnt].push_back(u);
                }
            } else low[u]=min(low[u],dfn[v]);
        }
    }
}

int sz[210000],dep[210000],son[210000],fa[210000];
int tot,dfn[210000],num[210000],top[210000];
void dfs(int u,int f){
    sz[u]=1; dep[u]=dep[f]+1; fa[u]=f;
    for (int v:vec[u]){
        if (v==f) continue;
        dfs(v,u); sz[u]+=sz[v];
        if (sz[v]>sz[son[u]]) son[u]=v;
    }
}
void dfs2(int u,int t){
    dfn[u]=++tot; num[tot]=u; top[u]=t;
    if (son[u]) dfs2(son[u],t);
    for (int v:vec[u]){
        if (v==fa[u]||v==son[u]) continue;
        dfs2(v,v);
    }
}
int val[1210000];
void change(int now,int l,int r,int x){
    if (l==r){
        val[now]=(num[x]<=n?w[num[x]]:*s[num[x]].begin());
        return;
    }
    int mid=(l+r)>>1;
    if (x<=mid) change(ls,l,mid,x);
    else change(rs,mid+1,r,x);
    val[now]=min(val[ls],val[rs]);
}
int query(int now,int l,int r,int x,int y){
    if (x<=l&&r<=y) return val[now];
    int mid=(l+r)>>1,res=INF;
    if (x<=mid) res=min(res,query(ls,l,mid,x,y));
    if (y>mid) res=min(res,query(rs,mid+1,r,x,y));
    return res;
}
void update(int x){ change(1,1,cnt,x);}
int query(int x,int y){
    int res=INF;
    while (top[x]!=top[y]){
        if (dep[top[x]]<dep[top[y]]) swap(x,y);
        res=min(res,query(1,1,cnt,dfn[top[x]],dfn[x]));
        x=fa[top[x]];
    }
    if (dep[x]<dep[y]) swap(x,y);
    if (y>n&&fa[y]) res=min(res,w[fa[y]]);


    return min(res,query(1,1,cnt,dfn[y],dfn[x]));
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>m>>q; int u,v;
    for (int i=1;i<=n;i++) cin>>w[i];
    for (int i=1;i<=m;i++){
        cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    Tarjan::tarjan(1,0);

    for (int i=1;i<=n;i++) vec[i].clear();
    for (int i=1;i<=cnt;i++)
        for (int v:bcc[i]){
//            cerr<<"Edge: "<<i+n<<' '<<v<<'\n';
            vec[i+n].push_back(v);
            vec[v].push_back(i+n);
        }
    cnt+=n;
    dfs(1,0); dfs2(1,1);
    for (int i=1;i<=n;i++)
        if (fa[i]) s[fa[i]].insert(w[i]);
    for (int i=1;i<=cnt;i++) update(i);
    
    char op;
    while (q--){
        cin>>op>>u>>v;
        if (op=='A') cout<<query(u,v)<<'\n';
        else{
            if (fa[u]){
                s[fa[u]].erase(s[fa[u]].find(w[u]));
                s[fa[u]].insert(v); update(dfn[fa[u]]);
            }
            w[u]=v; update(dfn[u]);
        }
    }
    return 0;
}