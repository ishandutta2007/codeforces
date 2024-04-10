#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 500050
#define MAXK 28

using namespace std;

const int inf=100000000;

typedef pair<int,int> pii;

int n,k;
char s[MAXN];
pii dp[MAXN][MAXK];
pii bb[MAXK+1],tt[MAXK+1];
//int bp[MAXK+1],tp[MAXK+1];
char ans[MAXN];

void solve() {
   for(int i=0;i<=n;i++)
      for(int j=0;j<k;j++)
         dp[i][k]=make_pair(inf,-1);
   for(int j=0;j<k;j++)
      dp[0][j]=make_pair(1,-1);
   dp[0][s[0]]=make_pair(0,-1);
   for(int i=1;i<n;i++) {
      bb[0]=make_pair(inf,-1);
      for(int j=0;j<k;j++)
         bb[j+1]=min(bb[j],make_pair(dp[i-1][j].first,j));
      tt[k]=make_pair(inf,-1);
      for(int j=k-1;j>=0;j--)
         tt[j]=min(tt[j+1],make_pair(dp[i-1][j].first,j));
      for(int j=0;j<k;j++) {
         dp[i][j]=min(bb[j],tt[j+1]);
         dp[i][j].first+=(s[i]==j?0:1);
      }
   }
   int bestj;
   pii opt=make_pair(inf,-1);
   for(int j=0;j<k;j++) {
      if(dp[n-1][j]<opt) {
         opt=dp[n-1][j];
         bestj=j;
      }
   }
   printf("%d\n",opt.first);
   ans[n]='\0';
   for(int i=n-1,j=bestj;i>=0;i--) {
      ans[i]='A'+j;
      j=dp[i][j].second;
   }
   puts(ans);
}

int main(void)
{
   scanf("%d %d",&n,&k);
   scanf("%s",s);
   for(int i=0;i<n;i++)
      s[i]-='A';
   solve();
   return 0;
}