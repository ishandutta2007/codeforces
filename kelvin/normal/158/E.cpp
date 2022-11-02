#include <stdio.h>
#include <algorithm>
#define MAXN 4200

using namespace std;

typedef pair<int,int> pii;

const int theend=86401;

int n,maxab;
pii s[MAXN];
int dp[MAXN][MAXN];

inline int solve() {
   sort(s,s+n);
   for(int i=0;i<=n;i++)
      for(int j=0;j<=i;j++)
         dp[i][j]=theend;
   dp[0][0]=1;
   for(int i=0;i<n;i++) {
      for(int j=0;j<=i&&j<=maxab;j++) {
         dp[i+1][j]=min(dp[i+1][j],max(dp[i][j],s[i].first)+s[i].second);
         dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]);
      }
   }
   int opt=0;
   for(int i=0;i<=n;i++) {
      for(int j=0;j<=i&&j<=maxab;j++) {
         int lb=dp[i][j];
         int ind=i+(maxab-j);
         int rb=ind<n?s[ind].first:theend;
         opt=max(opt,rb-lb);
      }
   }
   return opt;
}

int main()
{
   scanf("%d %d",&n,&maxab);
   for(int i=0;i<n;i++)
      scanf("%d %d",&s[i].first,&s[i].second);
   printf("%d\n",solve());
   return 0;
}