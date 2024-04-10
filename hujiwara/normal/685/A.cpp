#include <bits/stdc++.h>
using namespace std;


int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  int N=1,M=1;
  long long P1=1,P2=1;
  while(P1*7<n){
    P1*=7;
    N++;
  }
  while(P2*7<m){
    P2*=7;
    M++;
  }
  if(N+M>7){
    printf("%d\n",0);
    return 0;
  }
  int b[7];
  for(int i=0;i<7;i++){
    b[i]=i;
  }
  int C=0;
  do{
    int A=0,B=0;
    for(int i=0;i<N;i++){
      A*=7;
      A+=b[i];
    }
    for(int j=0;j<M;j++){
      B*=7;
      B+=b[N+j];
    }
    if(A<n&&B<m){
      C++;
    }
  }while(next_permutation(b,b+7));
  for(int i=1;i<=7-N-M;i++){
    C/=i;
  }
  printf("%d\n",C);
  return 0;
}