#include <stdio.h>
#include <limits.h>
#include <algorithm>
#define MAXN 450

const int inf=INT_MAX;

int n;
int wt[MAXN];

inline bool descmp(int a,int b) { return a>b; }

inline void greedy(int x,int &sz,int *arr) {
   sz=0;
   for(int i=0;i<n;i++) {
      arr[i]=x/wt[i];
      x-=arr[i]*wt[i];
      sz+=arr[i];
   }
}

inline int counter(int i,int j) {
   int c=0;
   int g[MAXN],m[MAXN],gsize,msize;
   greedy(wt[i-1]-1,msize,m);
   m[j]++;
   msize=0;
   for(int k=0;k<n;k++) {
      if(k<i||k>j) m[k]=0;
      c+=m[k]*wt[k];
      msize+=m[k];
   }
   greedy(c,gsize,g);
   if(gsize>msize) return c;
   if(gsize<msize) return 0;
   for(int k=0;k<n;k++) {
      if(m[k]>g[k]) return c;
      if(g[k]>m[k]) return 0;
   }
   return 0;
}

// return -1 if canonical
// otherwise return smallerst counter-example
inline int solve() {
   int cex=inf;
   // sort weights in descending order
   // TODO: redundant weights should be removed
   std::sort(wt,wt+n,descmp);
   if(wt[n-1]>1) return -1;
   for(int i=1;i<n;i++) {
      for(int j=i;j<n;j++) {
         int res=counter(i,j);
         if(res&&res<cex) cex=res;
      }
   }
   return cex==inf?-1:cex;
}

int main(void)
{
   while(scanf("%d",&n)==1) {
      for(int i=0;i<n;i++)
         scanf("%d",wt+i);
      printf("%d\n",solve());
   }
   return 0;
}