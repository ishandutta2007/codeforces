#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const ll mod=1e9+7;
const int mn=1e4+10;
ll dp[2][mn],a[mn],b[mn];
int main(){
    memset(dp,0x3f,sizeof(dp));
    dp[0][0]=0;
    int n;
    ll c;
    scanf("%d%lld",&n,&c);
    for(int i=1;i<=n;i++)scanf("%lld",a+i);
    for(int i=1;i<=n;i++)scanf("%lld",b+i);
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            dp[1][j]=min(dp[1][j],dp[0][j]+a[i]+c*j);
        }
        for(int j=0;j<i;j++){
            dp[1][j+1]=min(dp[1][j+1],dp[0][j]+b[i]);
        }
        memcpy(dp[0],dp[1],sizeof(dp[0]));
        memset(dp[1],0x3f,sizeof(dp[1]));
    }
    ll ans=LLONG_MAX;
    for(int i=0;i<=n;i++)ans=min(ans,dp[0][i]);
    printf("%lld",ans);
}