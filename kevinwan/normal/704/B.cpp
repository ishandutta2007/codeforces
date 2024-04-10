//Oshvleiki Svlaiyoska Ranasku sachi
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=5e3+10;
const ll mod=1e9+7;
ll x[mn],a[mn],b[mn],c[mn],d[mn];
ll dp[2][mn];
int main(){
    int n,s,e;
    scanf("%d%d%d",&n,&s,&e);
    for(int i=1;i<=n;i++)scanf("%lld",x+i);
    for(int i=1;i<=n;i++)scanf("%lld",a+i);
    for(int i=1;i<=n;i++)scanf("%lld",b+i);
    for(int i=1;i<=n;i++)scanf("%lld",c+i);
    for(int i=1;i<=n;i++)scanf("%lld",d+i);
    memset(dp,0x3f,sizeof(dp));
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        memset(dp[1],0x3f,sizeof(dp[1]));

        for(int j=0;j<=n;j++){
            if(s>e) {
                if (j && i != s)dp[1][j] = min(dp[1][j], dp[0][j - 1] + b[i] + d[i] - 2 * x[i]);
                if (i != s && i != e)dp[1][j] = min(dp[1][j], dp[0][j] + b[i] + c[i]);
                if(i>=s||i<=e||j>1)dp[1][j] = min(dp[1][j], dp[0][j] + a[i] + d[i]);
                if (i != e)dp[1][j] = min(dp[1][j], dp[0][j + 1] + a[i] + c[i] + 2 * x[i]);
            }
            else{
                if (j && i != e)dp[1][j] = min(dp[1][j], dp[0][j - 1] + b[i] + d[i] - 2 * x[i]);
                if(i<=s||i>=e||j>1)dp[1][j] = min(dp[1][j], dp[0][j] + b[i] + c[i]);
                if (i != s && i != e)dp[1][j] = min(dp[1][j], dp[0][j] + a[i] + d[i]);
                if (i != s)dp[1][j] = min(dp[1][j], dp[0][j + 1] + a[i] + c[i] + 2 * x[i]);
            }
        }
        if(i!=n)dp[1][0]=0x3f3f3f3f3f3f3f3f;
        memcpy(dp[0],dp[1],sizeof(dp[0]));
    }
    if(s<e)dp[0][0]-=c[e]+b[s]+abs(x[e]-x[s]);
    else dp[0][0]-=d[e]+a[s]+abs(x[e]-x[s]);
    printf("%lld",dp[0][0]);
}