#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=1e5+10;
ll dp[mn];
int a[mn],bes[mn][17];
inline int big(int x,int y){return a[x]>a[y]?x:y;}
inline int qu(int x,int y){
    y-=x-1;
    int ans=0;
    for(int i=16;i>=0;i--)if((y>>i)&1)ans=big(ans,bes[x][i]),x+=1<<i;
    return ans;
}
int main()
{
    int n,i,j;
    scanf("%d",&n);
    ll ans=0;
    for(i=1;i<n;i++){
        scanf("%d",a+i);
        bes[i][0]=i;
    }
    for(i=1;i<17;i++){
        for(j=1;j+(1<<i-1)<=n;j++)bes[j][i]=big(bes[j][i-1],bes[j+(1<<i-1)][i-1]);
    }
    dp[n]=0;
    for(i=n-1;i;i--){
        if(a[i]==n)dp[i]=n-i;
        else{
            int x=qu(i+1,a[i]);
            dp[i]=dp[x]+(x-i)+n-a[i];
        }
        ans+=dp[i];
    }
    printf("%lld",ans);
}