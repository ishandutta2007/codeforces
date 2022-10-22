#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int mn=2e5+10;
vector<int>g[mn];
vector<ll>pre[mn],suf[mn];
ll dp[mn],pd[mn],ans[mn];
void dfs(int x,int p){
    dp[x]=1;
    for(int y:g[x])if(y!=p)dfs(y,x),dp[x]*=dp[y]+1,dp[x]%=mod;
    pre[x].resize(g[x].size());
    suf[x].resize(g[x].size());
    for(int i=0;i<g[x].size();i++){
        if(g[x][i]==p)pre[x][i]=suf[x][i]=1;
        else pre[x][i]=suf[x][i]=dp[g[x][i]]+1;
        if(i)pre[x][i]*=pre[x][i-1],pre[x][i]%=mod;
    }
    for(int i=g[x].size()-2;i>=0;i--)suf[x][i]*=suf[x][i+1],suf[x][i]%=mod;
}
void dfs2(int x,int p){
    for(int i=0;i<g[x].size();i++){
        int y=g[x][i];
        if(y==p)continue;
        pd[y]=pd[x]*(i>0?pre[x][i-1]:1)%mod*(i+1<g[x].size()?suf[x][i+1]:1)%mod+1;
        ans[y]=pd[y]*dp[y]%mod;
        dfs2(y,x);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        int x;
        scanf("%d",&x);
        g[x].push_back(i);
    }
    dfs(1,0);
    pd[1]=1;
    ans[1]=dp[1];
    dfs2(1,0);
    for(int i=1;i<=n;i++)printf("%lld ",ans[i]);
}