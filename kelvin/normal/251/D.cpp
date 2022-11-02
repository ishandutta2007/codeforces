#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#define MAXR 63
#define MAXN 100500

using namespace std;

const int maxb=62;
long long tp[MAXR];

int n;
long long s[MAXN];
int bcnt[MAXR];

int rn;
bool mat[MAXR][MAXN];
int pivot[MAXR];

inline void subtract(int r1,int r2) {
   for(int j=0;j<=n;j++)
      mat[r1][j]^=mat[r2][j];
}

void solve() {
   vector<int> bis;
   for(int bi=maxb;bi>=0;bi--)
      for(int i=0;i<n;i++)
         if(s[i]&tp[bi]) bcnt[bi]++;
   for(int bi=maxb;bi>=0;bi--)
      if(!(bcnt[bi]&1)) bis.push_back(bi);
   for(int bi=maxb;bi>=0;bi--)
      if(bcnt[bi]&1) bis.push_back(bi);
   rn=0;
   for(int bii=0;bii<bis.size();bii++) {
      int bi=bis[bii];
      long long b=tp[bi];
      //puts("?");
      // try to satisfy
      for(int i=0;i<n;i++)
         mat[rn][i]=(s[i]&b)?1:0;
      if(bcnt[bi]&1) mat[rn][n]=0;
      else mat[rn][n]=1;
      //
      /*for(int i=0;i<=rn;i++) {
         for(int j=0;j<=n;j++)
            printf("%d ",(int)mat[i][j]); puts("");
      } puts("--");*/
      // test possibility
      for(int i=0;i<rn;i++) {
         int c=pivot[i];
         if(mat[rn][c]) subtract(rn,i);
      }
      pivot[rn]=-1;
      for(int j=0;j<n;j++)
         if(mat[rn][j]&&pivot[rn]<0) pivot[rn]=j;
      if(pivot[rn]<0) continue;
      for(int i=0;i<rn;i++)
         if(mat[i][pivot[rn]]) subtract(i,rn);
      rn++;
   }
   vector<int> ans(n,2);
   for(int i=0;i<rn;i++)
      if(mat[i][n]) ans[pivot[i]]=1;
   for(int i=0;i<n;i++)
      printf("%d ",ans[i]); puts("");
}

int main(void)
{
   for(int i=0;i<MAXR;i++)
      tp[i]=1LL<<i;
   cin >> n;
   for(int i=0;i<n;i++)
      cin >> s[i];
   solve();
   return 0;
}