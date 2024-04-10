#include <cstdio>
#include <algorithm>
#define MAXN 100500

using namespace std;

int s[MAXN];

int main(void)
{
   int m,n,per;
   scanf("%d",&m);
   per=MAXN;
   for(int i=0;i<m;i++) {
      int k;
      scanf("%d",&k);
      per=min(per,k);
   }
   scanf("%d",&n);
   for(int i=0;i<n;i++)
      scanf("%d",s+i);
   sort(s,s+n);
   int j,c=0;
   for(j=n;j>0;j-=per+2) {
      for(int i=0;i<per;i++)
         if(j-i-1>=0) c+=s[j-i-1];
   }
   printf("%d\n",c);
   return 0;
}