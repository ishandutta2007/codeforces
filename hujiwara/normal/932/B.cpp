#include <bits/stdc++.h>
using namespace std;

int main()
{
  static int g[1000010];
  for(int i=0;i<10;i++){
    g[i]=i;
  }
  for(int i=10;i<=1000000;i++){
    int f=1;
    int a=i;
    while(a>0){
      f*=(a%10==0?1:a%10);
      a/=10;
    }
    g[i]=g[f];
  }
  static int c[10][1000010];
  for(int t=0;t<10;t++){
    c[t][0]=0;
    for(int i=0;i<=1000000;i++){
      c[t][i+1]=c[t][i]+(g[i]==t);
    }
  }
  int n;
  scanf("%d",&n);
  while(n--){
    int l,r,k;
    scanf("%d%d%d",&l,&r,&k);
    printf("%d\n",c[k][r+1]-c[k][l]);
  }
  return 0;
}