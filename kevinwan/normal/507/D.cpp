#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k;
ll dp[1001][101];
ll pm[1001],pk[1001];
int main(){
    scanf("%d%d%d",&n,&k,&m);
    for(int i=1;i<=9;i++)dp[1][i%k]++;
    dp[1][k]=1;
    pm[0]=pk[0]=1;
    for(int i=1;i<=n;i++)pm[i]=pm[i-1]*10%m,pk[i]=pk[i-1]*10%k;
    for(int i=2;i<=n;i++){
        for(int j=0;j<k;j++){
            for(int l=0;l<=9;l++){
                int t=((j-pk[i-1]*l)%k+k)%k;
                if(t)dp[i][j]+=dp[i-1][t],dp[i][j]%=m;
                else if(j||l)dp[i][j]+=dp[i-1][k],dp[i][j]%=m;
                else dp[i][k]+=dp[i-1][k],dp[i][k]%=m;
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++)ans+=pm[n-i]*dp[i][0],ans%=m;
    for(int i=1;i<=n-1;i++)ans-=pm[n-1-i]*dp[i][0],ans%=m;
    if(ans<0)ans+=m;
    printf("%lld",ans);
}