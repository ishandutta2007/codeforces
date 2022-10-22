#include <bits/stdc++.h>
using namespace std;
const int mn=1001;
typedef long long ll;
ll mod=1e9+7;
ll dp[2][mn];
int main()
{
    int n,m,k,i,j;
    scanf("%d%d%d",&n,&m,&k);
    if(n<m)swap(n,m);
    for(i=1;i<=n;i++)dp[0][i]=1;
    for(i=1;i<=k;i++){
        for(j=1;j<=n;j++){
            dp[i&1^1][j]+=dp[i&1^1][j-1];
            dp[i&1^1][j]%=mod;
        }
        for(j=1;j<=n;j++){
            dp[i&1^1][j]+=dp[i&1^1][j-1];
            dp[i&1^1][j]%=mod;
        }
        dp[i&1][1]=0;
        for(j=2;j<=n;j++)dp[i&1][j]=dp[i&1^1][j-2];
    }
    printf("%lld",dp[k&1][n]*dp[k&1][m]%mod);
}