#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int s[5]={0};

int main(void)
{
   scanf("%d",&n);
   for(int i=0;i<n;i++) {
      int x;
      scanf("%d",&x);
      s[x]++;
   }
   int taxi=s[3];
   s[1]-=min(s[3],s[1]);
   taxi+=(s[1]+s[2]*2+s[4]*4+3)/4;
   printf("%d\n",taxi);
   return 0;
}