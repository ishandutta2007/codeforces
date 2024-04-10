#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,sz[210000]; ll ans,dp[210000];
vector<int> vec[210000];
void dfs(int u,int f){
    sz[u]=1; dp[u]=0;
    for (int v:vec[u]){
        if (v==f) continue;
        dfs(v,u);
        sz[u]+=sz[v]; dp[u]+=dp[v];
    }
    dp[u]+=sz[u];
}
void change(int u,int v){
    dp[u]-=dp[v]+sz[v]; sz[u]-=sz[v];
    dp[v]+=dp[u]+sz[u]; sz[v]+=sz[u];
}
void dfs2(int u,int f){
    ans=max(ans,dp[u]);
    for (int v:vec[u]){
        if (v==f) continue;
        change(u,v);
        dfs2(v,u);
        change(v,u);
    }
}
int main(){
    scanf("%d",&n); int u,v;
    for (int i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        vec[u].push_back(v); vec[v].push_back(u);
    }
    dfs(1,0);
    dfs2(1,0);
    printf("%lld\n",ans);
    return 0;
}