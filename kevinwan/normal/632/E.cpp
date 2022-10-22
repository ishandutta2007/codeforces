#include<bits/stdc++.h>
using namespace std;
mt19937 rng(time(0));
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
const ll mod=1e9+7;
const int mn=1e6+10;
int a[mn],dp[mn];
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)scanf("%d",a+i);
    sort(a,a+n);
    for(int i=1;i<n;i++)a[i]-=a[0];
    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    for(int i=0;i<k*a[n-1];i++){
        if(dp[i]>=k)continue;
        for(int j=1;j<n;j++)dp[i+a[j]]=min(dp[i+a[j]],dp[i]+1);
    }
    for(int i=0;i<=k*a[n-1];i++)if(dp[i]<=k)printf("%d ",i+k*a[0]);
}