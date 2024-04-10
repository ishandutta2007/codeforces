#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int mn=6010;
int v[mn];
vector<int>g[mn];
int dp[mn][mn];
int solve(int x,int p);
int dfs(int x,int p,int o){
    int bes=0;
    if(v[x]>v[o])bes=max(bes,solve(x,p));
    for(int y:g[x])if(y!=p){
        bes=max(bes,dfs(y,x,o));
    }
    return bes;
}
int solve(int x,int p){
    if(dp[x][p]!=-1)return dp[x][p];
    return dp[x][p]=dfs(x,p,x)+1;
}
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",v+i);
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ans=0;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++)ans=max(ans,solve(i,i));
    printf("%d",ans);
}