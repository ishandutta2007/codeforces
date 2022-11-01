#include <cstdio>

int main()
{
  long long n;
  scanf("%I64d",&n);
  int a=0;
  while(!(n%3)){
    n/=3;
    a++;
  }
  printf("%I64d\n",n/3+1);
  return 0;
}