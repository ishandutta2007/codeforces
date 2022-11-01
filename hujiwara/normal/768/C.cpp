#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,k,x;
  scanf("%d%d%d",&n,&k,&x);
  static int a[100000];
  for(int i=0;i<n;i++){
    scanf("%d",a+i);
  }
  static int T[2][1<<10]={0};
  bool b=0;
  for(int i=0;i<n;i++){
    T[b][a[i]]++;
  }
  for(int tt=0;tt<k;tt++){
    int p=0;
    for(int i=0;i<1<<10;i++){
      T[!b][i]+=(T[b][i]+p%2)/2;
      T[!b][i^x]+=(T[b][i]+(p+1)%2)/2;
      p+=T[b][i];
      T[b][i]=0;
    }
    b=!b;
  }
  int mx=-1,mn=(1<<10);
  for(int i=0;i<1<<10;i++){
    if(T[b][i]!=0){
      mx=max(mx,i);
      mn=min(mn,i);
    }
  }
  printf("%d %d\n",mx,mn);
  return 0;
}