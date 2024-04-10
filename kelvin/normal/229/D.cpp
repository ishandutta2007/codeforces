#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 5050

using namespace std;

const int inf=1000000000;

int n;
int h[MAXN],hs[MAXN];
int dp[MAXN][MAXN],ind[MAXN];

inline int hsum(int l,int r) { return hs[r+1]-hs[l]; }

inline void relax(int &x,int val) { if(val<x) x=val; }

int solve() {
   for(int i=0;i<n;i++)
      for(int j=i;j<n;j++)
         dp[i][j]=inf;
   /*for(int j=0;j<n;j++)
      dp[0][j]=j;*/
   dp[0][0]=0;
   for(int i=0;i<n;i++)
      ind[i]=n-1;
   int sol=inf;
   for(int i=0;i<n;i++) {
      for(int j=i;j<n;j++) {
         int ch=hsum(i,j);
         if(j==n-1) {
            sol=min(sol,dp[i][j]);
            continue;
         }
         // merge next
         relax(dp[i][j+1],dp[i][j]+1);
         //
         if(hsum(j+1,n-1)<ch) continue;
         while(ind[j+1]>j+1&&hsum(j+1,ind[j+1]-1)>=ch) ind[j+1]--;
         // update dp[j+1]['*'] | '*'>=ind[j+1]
         relax(dp[j+1][ind[j+1]],dp[i][j]+ind[j+1]-(j+1));
      }
   }
   return sol;
}

int main(void)
{
   scanf("%d",&n);
   hs[0]=0;
   for(int i=0;i<n;i++) {
      scanf("%d",h+i);
      hs[i+1]=hs[i]+h[i];
   }
   printf("%d\n",solve());
   return 0;
}