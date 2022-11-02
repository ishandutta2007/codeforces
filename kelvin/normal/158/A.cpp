#include <stdio.h>
#include <algorithm>
#define MAXN 55

using namespace std;

int n,k;
int s[MAXN];

int main(void)
{
   scanf("%d %d",&n,&k);
   for(int i=0;i<n;i++)
      scanf("%d",s+i);
   sort(s,s+n);
   int m=max(1,s[n-k]);
   int sol=n-(lower_bound(s,s+n,m)-s);
   printf("%d\n",sol);
   return 0;
}