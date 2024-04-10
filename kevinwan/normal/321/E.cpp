#include <bits/stdc++.h>
using namespace std;
const int mn=4e3+10;
int u[mn][mn],dp[mn][mn],c[mn][mn];
void solve(int lay,int l,int r,int a,int b){
    if(l>r)return;
    int mid=l+r>>1;
    int bes=a;
    dp[lay][mid]=dp[lay-1][a]+c[a][mid];
    for(int i=a+1;i<=min(b,mid);i++){
        if(dp[lay-1][i]+c[i][mid]<dp[lay][mid]){
            bes=i;
            dp[lay][mid]=dp[lay-1][i]+c[i][mid];
        }
    }
    solve(lay,l,mid-1,a,bes);
    solve(lay,mid+1,r,bes,b);
}
int main()
{
    int n,k,i,j;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            while((u[i][j]=getchar())<'0');
            u[i][j]-='0';
            u[i][j]+=u[i][j-1]+u[i-1][j]-u[i-1][j-1];
        }
    }
    for(i=0;i<=n;i++)for(j=0;j<=i;j++)c[j][i]=u[i][i]-u[i][j]-u[j][i]+u[j][j];
    memset(dp,0x3f,sizeof(dp));
    dp[0][0]=0;
    for(i=1;i<=k;i++){
        solve(i,1,n,0,n-1);
    }
    printf("%d",dp[k][n]/2);
}