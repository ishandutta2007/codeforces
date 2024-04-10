#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  scanf("%d",&n);
  static int f[100000];
  for(int i=0;i<n;i++){
    scanf("%d",f+i);
    f[i]--;
  }
  bool F=0;
  for(int i=0;i<n;i++){
    if(f[i]!=f[f[i]]){
      F=1;
      break;
    }
  }
  if(F){
    puts("-1");
    return 0;
  }
  int m=0;
  static int V[100000]={0};
  static int R[100000];
  for(int i=0;i<n;i++){
    if(!V[f[i]]){
      V[f[i]]=m+1;
      R[m]=f[i];
      m++;
    }
  }
  printf("%d\n",m);
  for(int i=0;i<n;i++){
    printf("%d%c",V[f[i]],i+1<n?' ':'\n');
  }
  for(int i=0;i<m;i++){
    printf("%d%c",R[i]+1,i+1<m?' ':'\n');
  }
  return 0;
}