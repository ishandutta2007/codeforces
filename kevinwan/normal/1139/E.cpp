#pragma GCC optimize "O3"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,avx2,mmx,popcnt,tune=native"
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(423978);
typedef long long ll;
typedef pair<ll,ll>pll;
const ll mod=1e9+7;
const int mn=5e3+10;
vector<int>g[mn];
int qu[mn],pr[mn],par[mn];
int p[mn],c[mn];
bool fu[mn];
int ans;
bool vis[mn],don[mn];
int n,q,m;
int dfs(int x){
    if(!x){
        for(int i=1;i<=m;i++)if(!vis[i]&&!don[i])if(dfs(i))return 1;
        return 0;
    }
    vis[x]=1;
    for(int y:g[x]){
        if(par[y]==-1){
            if(y!=ans)continue;
            don[x]=1;
            par[y]=x;
            return 1;
        }
        if(!vis[par[y]]) {
            if (dfs(par[y])) {
                don[x] = 1;
                par[y] = x;
                return 1;
            }
        }
    }
    return 0;
}
int main(){

    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",p+i);
    for(int i=1;i<=n;i++)scanf("%d",c+i);
    for(int i=1;i<=m;i++)g[0].push_back(i);
    scanf("%d",&q);
    for(int i=0;i<q;i++)scanf("%d",qu+i),fu[qu[i]]=1;
    for(int i=1;i<=n;i++)if(!fu[i])g[c[i]].push_back(p[i]);
    memset(par,-1,sizeof(par));
    for(int i=q-1;i>=0;i--){
        while(dfs(0)){
            ans++;
            memset(vis,0,sizeof(vis));
        }
        memset(vis,0,sizeof(vis));
        pr[i]=ans;
        g[c[qu[i]]].push_back(p[qu[i]]);
    }
    for(int i=0;i<q;i++)printf("%d\n",pr[i]);
}