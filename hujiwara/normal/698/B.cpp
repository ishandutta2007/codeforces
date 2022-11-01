#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  scanf("%d",&n);
  static int a[200000];
  for(int i=0;i<n;i++){
    scanf("%d",a+i);
    a[i]--;
  }
  static int b[200000]={0};
  int C=0,R=-1;
  for(int i=0;i<n;i++){
    if(a[i]==i){
      b[i]=i+1;
      R=i;
      break;
    }
  }
  for(int i=0;i<n;i++){
    if(b[i]){
      continue;
    }
    int s=i;
    while(b[s]==0){
      b[s]=i+1;
      s=a[s];
    }
    if(b[s]!=i+1){
      continue;
    }
    if(R==-1){
      R=s;
      a[s]=s;
      C++;
    }
    else{
      a[s]=R;
      C++;
    }
  }
  printf("%d\n",C);
  for(int i=0;i<n;i++){
    printf("%d%c",a[i]+1,i==n-1?'\n':' ');
  }
  return 0;
}