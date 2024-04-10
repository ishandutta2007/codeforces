#include<bits/stdc++.h>
using namespace std;
const int mn=2e5+10;
typedef pair<int,int>pii;
pii a[mn];
int dp[mn],bac[mn],num[mn],ans[mn];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].first);
        a[i].second=i;
    }
    sort(a+1,a+n+1);
    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    for(int i=3;i<=n;i++){
        for(int j=i-3;j>=max(i-5,0);j--){
            if(dp[i]>dp[j]+a[i].first-a[j+1].first){
                dp[i]=dp[j]+a[i].first-a[j+1].first;
                bac[i]=j;
                num[i]=num[j]+1;
            }
        }
    }
    printf("%d %d\n",dp[n],num[n]);
    int x=n;
    while(x){
        for(int i=x;i>bac[x];i--)ans[a[i].second]=num[x];
        x=bac[x];
    }
    for(int i=1;i<=n;i++)printf("%d ",ans[i]);
}