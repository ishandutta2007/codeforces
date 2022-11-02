#include <cstdio>
#include <algorithm>

using namespace std;

int main(void)
{
   int k,b,n,t;
   scanf("%d %d %d %d",&k,&b,&n,&t);
   int m=1,i=0;
   for(i=0;(long long)m*k+b<=t;i++)
      m=k*m+b;
   int sol=max(n-i,0);
   printf("%d\n",sol);
   return 0;
}