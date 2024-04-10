#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=10e5+10;
int k[mn],orig[mn];
int dp[mn][7][7];
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,m,i,j,l,x;
    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>x;
        k[x]++;
    }
    ll adj=0;
    for(i=1;i<=m;i++){
        adj+=max(k[i]/3-2,0);
        k[i]-=3*max(k[i]/3-2,0);
    }
    memset(dp,0xc0,sizeof(dp));
    dp[0][0][0]=0;
    for(i=1;i<=m;i++){
        for(j=0;j<7;j++){
            for(l=0;l<7;l++){
                int adj=0;
                if(k[i]>6)adj=1;
                dp[i][k[i]-adj*3][j]=max(dp[i][k[i]-adj*3][j],dp[i-1][j][l]+l/3+adj);
            }
            if(k[i]>=1&&j>=1){
                int adj=0;
                if(k[i]-1>6)adj=1;
                for(l=1;l<7;l++)dp[i][k[i]-1-adj*3][j-1]=max(dp[i][k[i]-adj*3-1][j-1],dp[i-1][j][l]+1+(l-1)/3+adj);
            }
            if(k[i]>=2&&j>=2){
                int adj=0;
                if(k[i]-2>6)adj=1;
                for(l=2;l<7;l++)dp[i][k[i]-2-adj*3][j-2]=max(dp[i][k[i]-adj*3-2][j-2],dp[i-1][j][l]+2+(l-2)/3+adj);
            }
        }
    }
    int ans=0xc0c0c0c0;
    for(i=0;i<7;i++)for(j=0;j<7;j++)ans=max(ans,dp[m][i][j]+i/3+j/3);
    printf("%lld",ans+adj);
}