#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  scanf("%d",&n);
  int a,b;
  printf("? %d\n",1);
  fflush(stdout);
  scanf("%d",&a);
  printf("? %d\n",1+n/2);
  fflush(stdout);
  scanf("%d",&b);
  if((a+1000000000)%2!=(b+1000000000)%2){
    printf("! -1\n");
    fflush(stdout);
    return 0;
  }
  if(a==b){
    printf("! 1\n");
    fflush(stdout);
    return 0;
  }
  bool F=(a<b);
  int L=2,R=1+n/2;
  while(1){
    int M=(L+R)/2;
    printf("? %d\n",M);
    fflush(stdout);
    scanf("%d",&a);
    printf("? %d\n",M+n/2);
    fflush(stdout);
    scanf("%d",&b);
    if(a==b){
      printf("! %d\n",M);
      fflush(stdout);
      break;
    }
    if((a<b)==F){
      L=M+1;
    }
    else{
      R=M;
    }
  }
  return 0;
}