#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 100050

using namespace std;

int n,atleast;
int a[MAXN],b[MAXN];

int solve() {
   int i,j,c=0;
   sort(a,a+n);
   sort(b,b+n);
   for(i=n-1,j=0;i>=0;i--) {
      while(j<n&&a[i]+b[j]<atleast) j++;
      if(j<n) {
         c++;
         j++;
      }
   }
   return c;
}

int main(void)
{
   scanf("%d %d",&n,&atleast);
   for(int i=0;i<n;i++)
      scanf("%d",a+i);
   for(int i=0;i<n;i++)
      scanf("%d",b+i);
   printf("1 %d\n",solve());
   return 0;
}