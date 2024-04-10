#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  scanf("%d",&n);
  static long long a[100000];
  for(int i=0;i<n;i++){
    scanf("%lld",a+i);
  }
  int c[41]={0},b[41]={0};
  for(int k=0,j=0;k<=40;k++){
    while(j<n&&a[j]<(1ll<<k)){
      j++;
      b[k]++;
    }
    while(j<n&&a[j]==(1ll<<k)){
      j++;
      c[k]++;
    }
  }
  int mc[41];
  mc[0]=c[0];
  for(int k=1;k<=40;k++){
    mc[k]=min(mc[k-1],c[k]);
  }
  bool F=0;
  for(int m=0;m<=c[0];m++){
    bool G=0;
    int R=0;
    for(int k=40;k>=0;k--){
      int t=min(m,mc[k])-(k==40?0:min(m,mc[k+1]));
      R+=c[k]-min(m,mc[k])-t;
      if(R>0){
	G=1;break;
      }
      R+=b[k];
    }
    if(!G){
      if(!F){
	F=1;
      }
      else{
	putchar(' ');
      }
      printf("%d",m);
    }
  }
  if(!F){
    puts("-1");
  }
  else{
    putchar('\n');
  }
  return 0;
}