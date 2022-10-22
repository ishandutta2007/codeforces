#include<bits/stdc++.h>
using namespace std;
int a[210];
typedef long long ll;
const int mod=1e9+7;
ll dp[2][210][2010];
int main(){
    int n,kk;
    scanf("%d%d,",&n,&kk);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    sort(a+1,a+1+n);
    dp[0][0][0]=1;
    for(int i=1;i<=n;i++){
        memset(dp[i&1],0,sizeof(dp[i&1]));
        for(int j=0;j<=i;j++){
            for(int k=0;k<=kk;k++){
                if(k+j*(a[i]-a[i-1])<=kk){
                    dp[i&1][j][k+j*(a[i]-a[i-1])]+=dp[i&1^1][j][k]*(j+1),dp[i&1][j][k+j*(a[i]-a[i-1])]%=mod;
                    dp[i&1][j+1][k+j*(a[i]-a[i-1])]+=dp[i&1^1][j][k],dp[i&1][j+1][k+j*(a[i]-a[i-1])]%=mod;
                    if(j)dp[i&1][j-1][k+j*(a[i]-a[i-1])]+=dp[i&1^1][j][k]*j,dp[i&1][j-1][k+j*(a[i]-a[i-1])]%=mod;
                }
            }
        }
    }
    ll ans=0;
    for(int i=0;i<=kk;i++)ans+=dp[n&1][0][i],ans%=mod;
    printf("%lld",ans);
}