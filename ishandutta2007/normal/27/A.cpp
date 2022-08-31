#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[3002];
int main(){
  int n,v;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&v);
    a[v]=1;
  }
  for(int i=1;i<=3001;i++)
    if(a[i]==0){
      printf("%d\n",i);break;}
//  system("PAUSE");
  return 0;
  }