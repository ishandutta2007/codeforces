#include<bits/stdc++.h>
using namespace std;
const int mn=2e5+10;
vector<int>g[mn];//0 is max 1 is min
int dp[mn][2];
int m;
void dfs(int x,int p,int k){
    if(g[x].size()<=1&&x!=1)dp[x][0]=dp[x][1]=1,m++;
    else dp[x][k]=0x3f3f3f3f;
    for(int y:g[x]){
        if(y==p)continue;
        dfs(y,x,k^1);
        dp[x][k]=min(dp[x][k],dp[y][k]);
        dp[x][k^1]+=dp[y][k^1];
    }
}
int main(){
    int n;
    scanf("%d",&n);
    if(n==1){
        printf("1 1");
        return 0;
    }
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0,0);
    printf("%d %d",m+1-dp[1][0],dp[1][1]);
}