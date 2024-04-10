#include <cstdio>

int main()
{
  long long a,b;
  scanf("%I64d%I64d",&a,&b);
  long long k=0ll;
  while(a&&b){
    k+=a/b;
    long long c=a%b;
    a=b;
    b=c;
  }
  printf("%I64d\n",k);
}