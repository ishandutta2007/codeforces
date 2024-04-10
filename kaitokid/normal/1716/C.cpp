#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[200009][2];
int dp[200009][2][2];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 int t;
 cin>>t;
 while(t--)
 {

 int n;
 cin>>n;
 for(int j=0;j<2;j++)
 for(int i=0;i<n;i++)
    {cin>>a[i][j];
    if((i!=0)||(j!=0))a[i][j]++;}

 dp[n-1][0][0]=dp[n-1][0][1]=max(a[n-1][0]+1,a[n-1][1]);
 dp[n-1][1][0]=dp[n-1][1][1]=max(a[n-1][1]+1,a[n-1][0]);

 for(int i=n-2;i>=0;i--)
 {
    int u=2*(n-i-1)-1;
    dp[i][0][0]=max(dp[i+1][1][0],max(a[i][0]+2,a[i][1]+1)+u);
    int tmp=max(dp[i+1][0][1]+1,a[i][1]);
    tmp=max(tmp,a[i][0]+2+u);
    dp[i][0][1]=tmp;
    dp[i][0][0]=min(dp[i][0][0],dp[i][0][1]);

   dp[i][1][0]=max(dp[i+1][0][0],max(a[i][1]+2,a[i][0]+1)+u);
 tmp=max(dp[i+1][1][1]+1,a[i][0]);
    tmp=max(tmp,a[i][1]+2+u);
    dp[i][1][1]=tmp;

    dp[i][1][0]=min(dp[i][1][0],dp[i][1][1]);
//cout<<i<<" "<<dp[i][0][0]<<" "<<dp[i][0][1]<<" "<<dp[i][1][0]<<" "<<dp[i][1][1]<<endl;
 }
 cout<<dp[0][0][0]<<endl;

 }
    return 0;
}