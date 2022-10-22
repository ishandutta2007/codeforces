#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=2e3+10;
int a[mn],b[mn],dp[mn],dp2[mn],n,k;
bool solve(ll r){
    int i,j;
    for(i=1;i<n;i++)dp[i]=dp2[i]=i;
    for(i=1;i<n;i++){
        for(j=i-1;j>=0;j--){
            if(abs(a[i]-a[j])<=r*(i-j))dp[i]=min(dp[i],dp[j]+i-j-1);
            if(abs(b[i]-b[j])<=r*(i-j))dp2[i]=min(dp2[i],dp2[j]+i-j-1);
        }
    }
    int bes=0x3f3f3f3f;
    for(i=0;i<n;i++)bes=min(bes,dp[i]+dp2[n-i-1]);
    return bes<=k;
}
int main()
{
    int i;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)scanf("%d",a+i);
    memcpy(b,a,sizeof(b));
    reverse(b,b+n);
    int cur=-1;
    for(i=1<<30;i;i>>=1){
        if(!solve(cur+i))cur+=i;
    }
    printf("%d",cur+1);
}