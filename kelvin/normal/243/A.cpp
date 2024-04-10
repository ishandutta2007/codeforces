#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#define MAXN 100050

using namespace std;

const int maxpow=21;
int tp[maxpow+1];

int n,s[MAXN];
int next[MAXN][maxpow];

int main(void)
{
   for(int i=0;i<=maxpow;i++)
      tp[i]=1<<i;
   scanf("%d",&n);
   for(int i=0;i<n;i++)
      scanf("%d",s+i);
   set<int> vals;
   for(int j=0;j<maxpow;j++)
      next[n][j]=n;
   for(int i=n-1;i>=0;i--) {
      for(int j=0;j<maxpow;j++) {
         next[i][j]=next[i+1][j];
         if(s[i]&tp[j]) next[i][j]=i;
         //printf("%d %d : %d\n",i,j,next[i][j]);
      }
   }
   int full=tp[maxpow]-1;
   for(int i=0;i<n;i++) {
      int x=i,v=s[i];
      while(x<n&&v!=full) {
         vals.insert(v);
         //printf("<%d>\n",v);
         int nx=n;
         for(int j=0;j<maxpow;j++)
            if(!(v&tp[j])) nx=min(nx,next[x][j]);
         x=nx;
         v|=s[x];
      }
   }
   int sol=vals.size();
   printf("%d\n",sol);
   return 0;
}