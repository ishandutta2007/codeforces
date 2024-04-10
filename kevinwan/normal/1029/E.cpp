#include<bits/stdc++.h>
using namespace std;
const int mn=2e5+10;
vector<int>g[mn];
int dp[mn][3],dep[mn];
int ans;
void dfs(int x,int p){
    dp[x][2]=1;
    int bes=0x3f3f3f3f;
    for(int y:g[x]){
        if(y==p)continue;
        dep[y]=dep[x]+1;
        dfs(y,x);
        dp[x][0]+=min(dp[y][1],dp[y][2]);
        dp[x][1]+=min(dp[y][1],dp[y][2]);
        dp[x][2]+=min(dp[y][0],min(dp[y][1],dp[y][2]));
        bes=min(bes,dp[y][2]-min(dp[y][1],dp[y][2]));
    }
    dp[x][1]+=bes;
    if(dep[x]==2)ans+=min(dp[x][0],min(dp[x][1],dp[x][2]));
}
int main(){
    int n,a,b,i;
    scanf("%d",&n);
    for(i=0;i<n-1;i++){
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,-1);
    printf("%d",ans);
}