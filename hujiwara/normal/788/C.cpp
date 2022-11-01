#include <bits/stdc++.h>
using namespace std;

const int MX=510*510,INF=10000000;

int main()
{
  int n,k;
  scanf("%d%d",&n,&k);
  bool B[1010]={0};
  for(int i=0;i<k;i++){
    int a;
    scanf("%d",&a);
    B[a]=1;
  }
  if(B[n]){
    printf("1\n");
    return 0;
  }
  static int A1[MX],A2[MX];
  A1[0]=A2[0]=0;
  for(int x=1;x<MX;x++){
    A1[x]=A2[x]=INF;
  }
  for(int i=0;i<n;i++){
    if(!B[i]){
      continue;
    }
    int d=n-i;
    for(int x=0;x+d<MX;x++){
      A1[x+d]=min(A1[x+d],A1[x]+1);
    }
  }
  for(int i=n+1;i<=1000;i++){
    if(!B[i]){
      continue;
    }
    int d=i-n;
    for(int x=0;x+d<MX;x++){
      A2[x+d]=min(A2[x+d],A2[x]+1);
    }
  }
  int ans=INF;
  for(int x=1;x<MX;x++){
    ans=min(ans,A1[x]+A2[x]);
  }
  printf("%d\n",ans<INF?ans:-1);
  return 0;
}