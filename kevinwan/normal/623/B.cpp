#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=1e6+10;
ll dp[mn][3],c[mn];
int k[mn];
int n,a,b;
ll solve(int p){
    int i;
    for(i=1;i<=n;i++){
        if(k[i]%p==0)c[i]=0;
        else if(k[i]%p==1||k[i]%p==p-1)c[i]=b;
        else c[i]=0x3f3f3f3f3f3f3f3f;
    }
    memset(dp,0x3f3f3f3f3f3f3f3f,sizeof(dp));
    dp[0][0]=0;
    for(i=1;i<=n;i++){
        dp[i][0]=min(dp[i][0],dp[i-1][0]+c[i]);
        dp[i][1]=min(min(dp[i-1][0],dp[i-1][1])+a,dp[i][1]);
        dp[i][2]=min(min(dp[i-1][1],dp[i-1][2])+c[i],dp[i][2]);
    }
    return min(dp[n][0],min(dp[n][1],dp[n][2]));
}
ll hail(int x){
    ll ans=0x3f3f3f3f3f3f3f3f;
    int i;
    for(i=2;i*i<=x;i++){
        if(x%i==0){
            ans=min(ans,solve(i));
            while(x%i==0)x/=i;
        }
    }
    if(x!=1)ans=min(ans,solve(x));
    return ans;
}
int main()
{
    scanf("%d%d%d",&n,&a,&b);
    int i;
    for(i=1;i<=n;i++)scanf("%d",k+i);
    ll ans=0x3f3f3f3f3f3f3f3f;
    ans=min(ans,hail(k[1]));
    ans=min(ans,hail(k[n]));
    ans=min(ans,hail(k[1]-1));
    ans=min(ans,hail(k[n]-1));
    ans=min(ans,hail(k[1]+1));
    ans=min(ans,hail(k[n]+1));
    printf("%lld",ans);
}