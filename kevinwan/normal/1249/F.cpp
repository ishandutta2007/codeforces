#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
const int inf=0x3f3f3f3f;
const int mn=210;
int a[mn],dp[mn][mn],n,k;
vector<int>g[mn];
void dfs(int x,int p){
    vector<int>sum(k+2,0);
    for(int y:g[x]){
        if(y==p)continue;
        dfs(y,x);
        for(int i=0;i<=k+1;i++)sum[i]+=dp[y][i];
    }
    for(int y:g[x]){
        if(y==p)continue;
        for(int i=0;i<=k+1;i++){
            for(int j=i;j<=k+1;j++){
                if(i+j<=k)continue;
                dp[x][min(i,j)]=max(dp[x][min(i,j)],dp[y][i]+sum[j]-dp[y][j]);
            }
        }
    }
    dp[x][0]=max(dp[x][0],dp[x][k+1]+a[x]);
    for(int i=k;i>=0;i--)dp[x][i]=max(dp[x][i],dp[x][i+1]);
    dp[x][k+1]=max(dp[x][k+1],dp[x][k]);
    for(int i=k;i>0;i--)dp[x][i]=dp[x][i-1];
    dp[x][0]=0;
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0);
    printf("%d",dp[1][1]);
}