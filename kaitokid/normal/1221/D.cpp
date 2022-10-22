#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n,q;
ll dp[300009][3];
int a[300009],b[300009];
int main()
{

scanf("%d",&q);

while(q--)
{
    //memset(dp,-1,sizeof dp);
scanf("%d",&n);

for(int i=0;i<n;i++){scanf("%d%d",&a[i],&b[i]);}
dp[0][0]=0;
dp[0][1]=b[0];
dp[0][2]=b[0]+b[0];
for(int i=1;i<n;i++)
{
    for(int j=0;j<3;j++)
    {
        dp[i][j]=2000000000000000000;
        for(int q=0;q<3;q++)
        {
            if(a[i-1]+q==a[i]+j)continue;

      dp[i][j]=min(dp[i][j],dp[i-1][q]+b[i]*j);
        }
    }
}
ll ans=2000000000000000000;
for(int j=0;j<3;j++)
{


 ans=min(ans,dp[n-1][j]);}

//cout<<ans<<endl;
printf("%I64d\n",ans);
}
  return 0;
}