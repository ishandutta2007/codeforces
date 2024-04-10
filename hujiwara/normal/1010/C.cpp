#include <bits/stdc++.h>

int gcd(int a,int b)
{
  return b==0?a:gcd(b,a%b);
}

int main()
{
  int n,k;
  scanf("%d%d",&n,&k);
  int g=k;
  for(int i=0;i<n;i++){
    int a;
    scanf("%d",&a);
    g=gcd(g,a);
  }
  printf("%d\n",k/g);
  for(int i=0;i<k;i+=g){
    printf("%d%c",i,i==k-g?'\n':' ');
  }
  return 0;
}