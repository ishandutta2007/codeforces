#include <bits/stdc++.h>
using namespace std;
const int mn=2e3+10;
int a[mn];
void kill(){
    printf("0");
    exit(0);
}
typedef long long ll;
ll dp[mn][mn];
const ll mod=1e9+7;
int main()
{
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)scanf("%d",a+i),a[i]=m-a[i];
    for(i=1;i<=n;i++)a[i]-=a[i+1];
    for(i=1;i<=n;i++)if(abs(a[i])>1)kill();
    dp[0][0]=dp[0][1]=1;
    for(i=1;i<=n;i++){
        for(j=0;j<=n;j++){
            if(a[i]==1){
                if(j)dp[i][j-1]=dp[i-1][j]*j,dp[i][j-1]%=mod;
            }
            else if(a[i]==0){
                dp[i][j]+=dp[i-1][j]*(j+1),dp[i][j]%=mod;
            }
            else{
                dp[i][j+1]=dp[i-1][j],dp[i][j+1]%=mod;
            }
        }
    }
    printf("%lld",dp[n][0]);
}