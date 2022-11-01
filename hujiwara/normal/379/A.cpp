#include <cstdio>

int main()
{
  int a,b;
  scanf("%d%d",&a,&b);
  int c=0,k=a,p=0;
  while(k>0){
    c+=k;
    int K=(k+p)/b,P=(k+p)%b;
    k=K;
    p=P;
  }
  printf("%d\n",c);
  return 0;
}