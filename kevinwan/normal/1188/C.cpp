#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
const int mn=1e3+10;
int a[mn],bac[100*mn];
ll sum[mn][mn],dp[mn];
int main()
{
    int n,k,i,j,d;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)scanf("%d",a+i);
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++)bac[a[i]]=i;
    for(i=1;i<100*mn;i++)if(!bac[i])bac[i]=bac[i-1];
    ll ans=0;
    sum[0][0]=1;
    for(d=1;d*(k-1)<100000;d++){
        for(i=1;i<=n;i++){
            for(j=1;j<=k;j++){
                if(a[i]-d<0)dp[j]=sum[0][j-1];
                else dp[j]=sum[bac[a[i]-d]][j-1];
                sum[i][j]=(sum[i-1][j]+dp[j])%mod;
            }
            sum[i][0]=sum[i-1][0];
        }
        ans+=sum[n][k];
        ans%=mod;
    }
    printf("%lld",ans);
}