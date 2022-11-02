#include <stdio.h>
#include <vector>
#include <map>
#define MAXL 505

using namespace std;

int an,bn,z;
int a[MAXL],b[MAXL];
int next[MAXL*2][MAXL];
int dp[MAXL][MAXL]={0};
pair<int,int> pred[MAXL][MAXL];
map<int,int> rmp;

inline void relax(int ni,int nj,int x,int i,int j) {
   if(x>dp[ni][nj]) {
      dp[ni][nj]=x;
      pred[ni][nj]=make_pair(i,j);
   }
}

inline void pre() {
   map<int,int> mp;
   for(int i=0;i<an;i++)
      mp[a[i]]=0;
   for(int i=0;i<bn;i++)
      mp[b[i]]=0;
   z=0;
   rmp.clear();
   for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++) {
      it->second=z;
      rmp[z++]=it->first;
   }
   for(int i=0;i<an;i++)
      a[i]=mp[a[i]];
   for(int i=0;i<bn;i++)
      b[i]=mp[b[i]];
}

inline void pre2() {
   for(int i=0;i<z;i++) {
      next[i][bn]=bn;
      for(int j=bn-1;j>=0;j--) {
         if(b[j]==i) next[i][j]=j;
         else next[i][j]=next[i][j+1];
      }
   }
}

inline void trace() {
   int i=pred[an][bn].first,j=pred[an][bn].second;
   vector<int> sol;
   while(i>=0) {
      int ti=i,tj=j;
      sol.push_back(rmp[a[i]]);
      i=pred[ti][tj].first;
      j=pred[ti][tj].second;
   }
   for(int i=sol.size()-1;i>=0;i--)
      printf("%d%c",sol[i],i?' ':'\n');
}

inline void solve() {
   pre();
   pre2();
   dp[an][bn]=0;
   pred[an][bn]=make_pair(-1,-1);
   for(int i=0;i<an;i++) {
      for(int j=0;j<bn;j++) {
         if(a[i]!=b[j]) continue;
         relax(i,j,1,-1,-1);
         relax(an,bn,dp[i][j],i,j);
         for(int ni=i+1;ni<an;ni++) {
            if(a[ni]<=a[i]) continue;
            int nj=next[a[ni]][j+1];
            if(nj>=bn) continue;
            relax(ni,nj,dp[i][j]+1,i,j);
         }
      }
   }
   printf("%d\n",dp[an][bn]);
   trace();
}

int main(void)
{
   scanf("%d",&an);
   for(int i=0;i<an;i++)
      scanf("%d",a+i);
   scanf("%d",&bn);
   for(int i=0;i<bn;i++)
      scanf("%d",b+i);
   solve();
   return 0;
}