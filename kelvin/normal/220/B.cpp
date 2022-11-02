#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define MAXN 100050
#define MAXK 475

using namespace std;

int n,qn;
int s[MAXN];
int occ[MAXK][MAXN];
int cnt[MAXN];
int an,arr[MAXK];

void pre() {
   for(int i=0;i<an;i++) {
      int x=arr[i];
      occ[i][0]=0;
      for(int j=0;j<n;j++)
         occ[i][j+1]=occ[i][j]+(s[j]==x?1:0);
   }
}

inline int find(int l,int r,int i) {
   return occ[i][r]-occ[i][l-1];
}

inline int solve(int l,int r) {
   int s=0;
   for(int i=0;i<an;i++)
      if(find(l,r,i)==arr[i]) s++;
   return s;
}

int main(void)
{
   scanf("%d %d",&n,&qn);
   for(int i=0;i<n;i++) {
      scanf("%d",s+i);
      if(s[i]<=n) cnt[s[i]]++;
   }
   for(int i=1;i<=n;i++)
      if(cnt[i]>=i) arr[an++]=i;
   pre();
   for(int t=0;t<qn;t++) {
      int l,r;
      scanf("%d %d",&l,&r);
      printf("%d\n",solve(l,r));
   }
   return 0;
}