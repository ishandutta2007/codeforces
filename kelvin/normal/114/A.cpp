#include <stdio.h>
#include <iostream>

using namespace std;

int main(void)
{
   long long k,m;
   cin >> k >> m;
   int c=0;
   while(m%k==0) {
      m/=k;
      c++;
   }
   if(m==1) {
      puts("YES");
      printf("%d\n",c-1);
   } else puts("NO");
}