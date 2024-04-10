#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAXN 100500
#define MAXVAL 100500

using namespace std;

//int pn;
//int pr[MAXVAL];
//bool np[MAXVAL];
vector<int> fac[MAXVAL];

int n;
int s[MAXN];
int dp[MAXVAL];

void gen() {
   //pn=0;
   for(int i=2;i<MAXVAL;i++) {
      //if(np[i]) continue;
      if(fac[i].size()) continue;
      //pr[pn++]=i;
      for(int j=i;j<MAXVAL;j+=i)
         fac[j].push_back(i);
   }
}

int solve() {
   int opt=0;
   for(int i=0;i<n;i++) {
      int x=s[i];
      int l=1;
      for(int j=0;j<fac[x].size();j++)
         l=max(l,dp[fac[x][j]]+1);
      opt=max(opt,l);
      for(int j=0;j<fac[x].size();j++)
         dp[fac[x][j]]=max(dp[fac[x][j]],l);
   }
   return opt;
}

int main(void)
{
   gen();
   scanf("%d",&n);
   for(int i=0;i<n;i++)
      scanf("%d",s+i);
   printf("%d\n",solve());
   return 0;
}