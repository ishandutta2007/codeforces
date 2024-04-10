#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int mod=1e9+7;
ll kpow(ll x,ll y,ll rex=1){
    for(;y;y>>=1,x=x*x)if(y&1)rex=x*rex;
    return rex;
}
int exgcd(int a,int b,int &x,int &y){
    int t=b?exgcd(b,a%b,y,x):a;
    if(!b)x=1,y=0;
    else y-=a/b*x;
    return t;
}
const int M=5e5+9;
int n;
int df,dfn[M],low[M],siz[M],ord[M],f[M],val[M],v1[M];
vector<pii>g[M];
set<int>s[M];
ll ans=0;
void pfs(int u,int fa,int w){
    siz[u]=1;
    dfn[u]=++df;
    ord[df]=u;
    if(w)s[w].insert(dfn[u]);
    for(auto o:g[u]){
        int v=o.fi,w=o.se;
        if(v!=fa){
            pfs(v,u,w);
            siz[u]+=siz[v];
        }
    }
    low[u]=df;
}
void dfs(int u,int fa,int w){
    for(auto o:g[u]){
        int v=o.fi,w=o.se;
        if(v!=fa)dfs(v,u,w);
    }
    auto it=s[w].lower_bound(dfn[u]);
    vector<int>e;

    if(it==s[w].end())return;
    it++;
    val[u]=siz[u];
    while(it!=s[w].end()){
        int v=ord[*it];
        if(dfn[v]>low[u])break;
        e.eb(dfn[v]);
        f[v]=u;
        val[u]-=siz[v];
        it++;
    }
    for(auto o:e)s[w].erase(o);
}
void solve(int u,int fa,int w){
    if(u>1){
        if(f[u]>1)ans=ans+1ll*val[u]*val[f[u]];
        else ans=ans+1ll*val[u]*v1[w];
    }
    for(auto o:g[u]){
        int v=o.fi,w=o.se;
        if(v!=fa)solve(v,u,w);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;++i){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        g[u].eb(v,w);
        g[v].eb(u,w);
    }
    pfs(1,0,0);
    dfs(1,0,0);
    for(int i=1;i<=n;++i){
        auto it=s[i].lower_bound(dfn[1]);
        if(it==s[i].end())continue;
        v1[i]=siz[1];
        while(it!=s[i].end()){
            int v=ord[*it];
            if(dfn[v]>low[1])break;
            f[v]=1;
            v1[i]-=siz[v];
            it++;
        }
    }
    solve(1,0,0);
    printf("%lld\n",ans);
    return 0;
}