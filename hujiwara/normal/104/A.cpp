#include <cstdio>

int main()
{
  int n;
  scanf("%d",&n);
  int a=0;
  if(n==20){
    a=15;
  }
  else if(1<=n-10&&n-10<=11){
    a=4;
  }
  printf("%d\n",a);
  return 0;
}