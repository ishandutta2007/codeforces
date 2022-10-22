#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const ll mod=998244353;
const int mn=1e6+10;
ll dp[10001],c[1001];
int num[1001];
int main(){
    int n,w,b,x;
    scanf("%d%d%d%d",&n,&w,&b,&x);
    for(int i=1;i<=n;i++)scanf("%d",num+i);
    for(int i=1;i<=n;i++)scanf("%lld",c+i);
    memset(dp,0xc0,sizeof(dp));
    dp[0]=w;
    for(int i=1;i<=n;i++){
        if(i!=1)for(int j=0;j<=10000;j++)dp[j]+=x,dp[j]=min(dp[j],w+1LL*j*b);
        for(int j=10000;j>=0;j--){
            for(int k=1;k<=num[i]&&j-k>=0;k++){
                dp[j]=max(dp[j],dp[j-k]-k*c[i]);
            }
            if(dp[j]<0)dp[j]=0xc0c0c0c0c0c0c0c0;
        }

    }
    int ans=0;
    for(int i=0;i<=10000;i++)if(dp[i]>=0)ans=i;
    printf("%d",ans);
}