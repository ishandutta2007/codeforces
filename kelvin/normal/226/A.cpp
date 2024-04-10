#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

inline int add(int a,int b,int mod) {
   return a+b<mod?a+b:a+b-mod;
}

inline int power(int x,int p,int mod) {
   int m=x,r=1;
   while(p) {
      if(p&1) r=(long long)r*m%mod;
      m=(long long)m*m%mod;
      p>>=1;
   }
   return r;
}

int main(void)
{
   int n,m,f;
   scanf("%d %d",&n,&m);
   f=add(power(3,n,m),m-1,m);
   printf("%d\n",f);
   return 0;
}