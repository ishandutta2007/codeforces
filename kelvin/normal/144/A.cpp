#include <stdio.h>
#include <algorithm>
#define MAXN 105

using namespace std;

int n;
int s[MAXN];

int main(void)
{
   int ma=-1,mi=10000;
   int xa,xi;
   scanf("%d",&n);
   for(int i=0;i<n;i++) {
      scanf("%d",s+i);
      mi=min(mi,s[i]);
      ma=max(ma,s[i]);
   }
   for(int i=n-1;i>=0;i--)
      if(s[i]==ma) xa=i;
   for(int i=0;i<n;i++)
      if(s[i]==mi) xi=i;
   int z=xa+(n-1-xi)-(xa>xi?1:0);
   printf("%d\n",z);
   return 0;
}