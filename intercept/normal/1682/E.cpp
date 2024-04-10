#include<bits/stdc++.h>
#define ll long long 
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int mod=1e9+7;
int kpow(int x,ll y,int rex=1){
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*x*rex%mod;
    return rex;
}
int exgcd(int a,int b,int &x,int &y){
    int t=b?exgcd(b,a%b,y,x):a;
    if(!b)x=1,y=0;
    else y-=a/b*x;
    return t;
}

const int M=1e6+9;
int n,m,num;
int ans[M];
int a[M],b[M],id[M];
int p[M],vis[M],val[M],d[M],in[M];
vector<pii>g[M];
void dfs(int u){
    if(in[u])return;
    in[u]=1;
    for(auto o:g[u]){
        dfs(o.fi);
        ans[++num]=o.se;
        d[o.se]=1;
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)scanf("%d",&p[i]);
    for(int i=1;i<=n;++i){
        if(!vis[i]){
            vis[i]=1;
            int num=1;
            val[i]=1;
            int u=p[i];
            while(u!=i){
                vis[u]=1;
                val[u]=++num;
                u=p[u];
            }
        }
    }
    for(int i=1;i<=m;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        if(val[u]>val[v])swap(u,v);
        g[u].eb(v,i);
        id[i]=i;
        a[i]=u;
        b[i]=v;
    }
    sort(id+1,id+m+1,[&](const int&l,const int&r){
        return val[a[l]]!=val[a[r]]?val[a[l]]<val[a[r]]:val[b[l]]<val[b[r]];
    });
    for(int i=1;i<=n;++i){
        sort(g[i].begin(),g[i].end(),[&](const pii&l,const pii&r){
            return val[l.fi]<val[r.fi];
        });
    }
    for(int i=1;i<=m;++i){
        dfs(a[id[i]]);
    }
    for(int i=1;i<=m;++i)printf("%d%c",ans[i]," \n"[i==n]);
    return 0;
}