#include <cstdio>

int main()
{
  long long n;
  char c;
  scanf("%lld%c",&n,&c);
  printf("%lld\n",((n-1)/4)*16+(n%4==2||n%4==0?7:0)+(c<='c'?c-'a'+4:'f'-c+1));
  return 0;
}