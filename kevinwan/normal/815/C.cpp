#include<bits/stdc++.h>
using namespace std;
const int mn=5003;
const int inf=0x3f3f3f3f;
int dp[mn][2][mn];
vector<int>g[mn];
int c[mn],d[mn],s[mn];
void dfs(int x,int p){
    s[x]=1;
    int lar=0;
    for(int y:g[x]){
        if(y==p)continue;
        dfs(y,x);
        s[x]+=s[y];
        if(s[y]>s[lar])lar=y;
    }
    int num=s[lar];
    for(int y:g[x]){
        if(y==p||y==lar)continue;
        num+=s[y];
        for(int i=num;i>=1;i--){
            for(int j=1;j<=min(i,s[y]);j++){
                dp[lar][0][i]=min(dp[lar][0][i],min(dp[lar][0][i-j]+dp[y][0][j],inf));
                dp[lar][1][i]=min(dp[lar][1][i],min(dp[lar][1][i-j]+dp[y][1][j],inf));
            }
        }
    }
    for(int i=s[x];i;i--)dp[x][0][i]=min(dp[lar][0][i],dp[lar][0][i-1]+c[x]);
    for(int i=s[x];i;i--)dp[x][1][i]=min(dp[lar][0][i],dp[lar][1][i-1]+c[x]-d[x]);
    dp[x][0][0]=dp[x][1][0]=0;
}
int main(){
    int n,b;
    scanf("%d%d",&n,&b);
    scanf("%d%d",c+1,d+1);
    int p;
    for(int i=2;i<=n;i++)scanf("%d%d%d",c+i,d+i,&p),g[p].push_back(i);
    memset(dp,0x3f,sizeof(dp));
    dp[0][0][0]=dp[0][1][0]=0;
    dfs(1,0);
    for(int i=0;i<=n+1;i++){
        if(dp[1][1][i]>b){
            printf("%d",i-1);
            return 0;
        }
    }
}