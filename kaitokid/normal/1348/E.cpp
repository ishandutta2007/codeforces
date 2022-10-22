#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int ans,n,k,a[509],b[509];
int dp[509][509];
ll sum;
int main()
{
    //ios::sync_with_stdio(0);

    scanf("%d%d",&n,&k);
   //cin>>n>>k;
   for(int i=0;i<n;i++)
   {
       //cin>>a[i]>>b[i];
      scanf("%d%d",&a[i],&b[i]);
      sum+=a[i]+b[i];
   }
   memset(dp,-1,sizeof dp);
   dp[0][0]=0;
for(int i=0;i<n;i++)
    for(int j=0;j<k;j++)
{
    if(dp[i][j]==-1)continue;
for(int q=0;q<min(a[i]+1,k);q++)
{
    int x=a[i]-q;
    int y=b[i];
    int u=(x+y)%k;
    if(u>y)continue;
    int p=(dp[i][j]+u)%k;
    if(dp[i+1][(j+q)%k]==-1)dp[i+1][(j+q)%k]=p;
    dp[i+1][(j+q)%k]=min(dp[i+1][(j+q)%k],p);
}
}
int d=1e8;
for(int i=0;i<k;i++)
    if(dp[n][i]!=-1)d=min(d,i+dp[n][i]);
sum=(sum-d)/k;
//cout<<sum;
 printf("%I64d",sum);
   return 0;
}