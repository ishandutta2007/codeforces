#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=2e5+10;
ll a[mn],dp[mn];
int x[mn],y[mn];
int main()
{
    int n,m,k,i,j;
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=n;i++)scanf("%lld",a+i);
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++)a[i]+=a[i-1];
    for(i=0;i<m;i++)scanf("%d%d",x+i,y+i);
    for(i=1;i<=k;i++){
        dp[i]=dp[i-1]+a[i]-a[i-1];
        for(j=0;j<m;j++){
            if(i>=x[j]){
                dp[i]=min(dp[i],dp[i-x[j]]+a[i]-a[i-x[j]+y[j]]);
            }
        }
    }
    printf("%lld",dp[k]);
}