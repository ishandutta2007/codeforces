#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int dp[100009][201][2];
int mod=998244353;
int main()
{
memset(dp,0,sizeof dp);
 int n,x;
 cin>>n;
 cin>>x;
 if(x==-1)for(int i=1;i<201;i++)dp[0][i][0]=i;
 else for(int i=x;i<201;i++)dp[0][i][0]=1;
 for(int i=1;i<n;i++)
 {//x=-1;
     cin>>x;
     if(x==-1)
     {
         for(int j=1;j<201;j++){
             int r=dp[i-1][j][0]-dp[i-1][j-1][0],r2=dp[i-1][200][1]-dp[i-1][j-1][1];
         if(r<0)r+=mod;
         if(r2<0)r2+=mod;
                dp[i][j][1]=(r2+r)%mod;

         dp[i][j][0]=(dp[i-1][j-1][1]+dp[i-1][j-1][0])%mod;
         dp[i][j][1]=(dp[i][j][1]+dp[i][j-1][1])%mod;
         dp[i][j][0]=(dp[i][j][0]+dp[i][j-1][0])%mod;


         }
              continue;
    }
    int j=x;
               int r=dp[i-1][j][0]-dp[i-1][j-1][0],r2=dp[i-1][200][1]-dp[i-1][j-1][1];
         if(r<0)r+=mod;
         if(r2<0)r2+=mod;
                dp[i][j][1]=(r2+r)%mod;

         dp[i][j][0]=(dp[i-1][j-1][1]+dp[i-1][j-1][0])%mod;
         for( j=x+1;j<201;j++){  dp[i][j][1]=dp[i][j-1][1];
         dp[i][j][0]=dp[i][j-1][0];}
 }

 cout<<dp[n-1][200][1];

    return 0;
}