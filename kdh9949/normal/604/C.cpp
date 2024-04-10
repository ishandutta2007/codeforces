#include <stdio.h>
#include <algorithm>
using namespace std;

int n,ans;
char str[100010];
int dp[100010][2][2][2]; // [][][   ][ ]

int main(){
    scanf("%d",&n);
    scanf("%s",str+1);
    for(int i=1;i<=n;++i)str[i]-='0';
    for(int i=1;i<=n;++i){
        for(int j=0;j<2;++j){
            if(j==str[i])dp[i][j][0][0]=dp[i-1][!j][0][0]+1;
            else dp[i][j][0][0]=dp[i-1][j][0][0];
            if(j==!str[i])dp[i][j][1][0]=max(dp[i-1][!j][1][0],dp[i-1][!j][0][0])+1;
            else dp[i][j][1][0]=dp[i-1][j][1][0];
            if(j==str[i])dp[i][j][0][1]=max(dp[i-1][!j][1][0],dp[i-1][!j][0][1])+1;
            else dp[i][j][0][1]=dp[i-1][j][0][1];
        }
    }
    for(int j=0;j<2;++j)for(int k=0;k<2;++k)for(int l=0;l<2;++l)ans=max(ans,dp[n][j][k][l]);
    printf("%d",ans);
}