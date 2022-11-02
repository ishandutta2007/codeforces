#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAXN 500050
#define MAXL 12

using namespace std;

const int inf=1000000000;

int n;
char s[MAXN][MAXL];
int first[MAXN],last[MAXN],len[MAXN];
int dp[200];

inline int solve() {
   int opt=0;
   for(char c='a';c<='z';c++) {
      for(char z='a';z<='z';z++)
         dp[z]=-inf;
      for(int i=0;i<n;i++) {
         dp[last[i]]=max(dp[last[i]],dp[first[i]]+len[i]);
         if(first[i]==c) dp[last[i]]=max(dp[last[i]],len[i]);
         if(last[i]==c) opt=max(opt,dp[c]);
      }
   }
   return opt;
}

int main(void)
{
   scanf("%d",&n);
   for(int i=0;i<n;i++) {
      scanf("%s",s[i]);
      len[i]=strlen(s[i]);
      first[i]=s[i][0];
      last[i]=s[i][len[i]-1];
   }
   printf("%d\n",solve());
   return 0;
}