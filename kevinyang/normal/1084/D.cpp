#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll w[300010];
vector<pair<int,int>> g[300010];
ll toEnd[300010],toBeg[300010];
ll ans=0;
void dfs(int u,int p,int ww){
    toBeg[u]=max(w[u],toEnd[p]-ww+w[u]);
    toEnd[u]=w[u];
    for(pair<int,int> v:g[u]){
        if(v.first!=p){
            dfs(v.first,u,v.second);
            toEnd[u]=max(toEnd[u],toEnd[v.first]-v.second+w[u]);
        }
    }
    ans=max(ans,toBeg[u]+toEnd[u]-w[u]);
}

int main() {
    int n;
    scanf("%d",&n);
    for(int i=1,a; i<=n; i++){
        scanf("%d",&w[i]);
    }
    for(int i=0,u,v,c; i<n-1; i++){
        scanf("%d %d %d",&u,&v,&c);
        g[u].push_back({v,c});
        g[v].push_back({u,c});
    }
    dfs(1,0,0);
    // for(int i=1,a; i<=n; i++){
    //     printf("%lld ",toBeg[i]);
    // }
    // printf("\n");
    // for(int i=1,a; i<=n; i++){
    //     printf("%lld ",toEnd[i]);
    // }
    // printf("\n");
    printf("%lld\n",ans);
    return 0;
}