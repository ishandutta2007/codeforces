#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int MAX_N=1e5;
const int INF=1e9;
int n;
LL a[MAX_N];
int dp[2][MAX_N+1];
int main(){
    scanf("%d",&n);
    LL mx=0;
    for(int i=0;i<n;++i){
        scanf("%lld",&a[i]);
        mx=max(mx,a[i]);
    }
    for(int i=0;i<n;++i){
        a[i]=mx-a[i];
    }
    for(int i=1;i<=n;++i){
        dp[0][i]=INF;
    }
    int cur=0;
    for(int k=1;k<=62;++k){
        cur^=1;
        for(int i=0;i<=n;++i){
            dp[cur][i]=INF;
        }
        int tot=0;
        for(int i=0;i<n;++i){
            if(a[i]>>(k-1)&1){
                ++tot;
            }
        }
        for(int i=0,j=0;i<=n;++i){
            dp[cur][j]=min(dp[cur][j],dp[cur^1][i]+i-j+tot-j);
            dp[cur][i-j+tot]=min(dp[cur][i-j+tot],dp[cur^1][i]+n-tot-i+j+j);
            if(i<n&&(a[i]>>(k-1)&1)){
                ++j;
            }
        }
        sort(a,a+n,[&](LL x,LL y){
            return (x&((1ll<<k)-1))>(y&((1ll<<k)-1));
        });
    }
    int ans=INF;
    for(int i=0;i<=n;++i){
        ans=min(ans,dp[cur][i]+i);
    }
    printf("%d\n",ans);
    return 0;
}