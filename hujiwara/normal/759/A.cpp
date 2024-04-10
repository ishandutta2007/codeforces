#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  static int P[200000],b[200000];
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",P+i);
    P[i]--;
  }
  for(int i=0;i<n;i++){
    scanf("%d",b+i);
  }
  static bool v[200000]={0};
  int C=0;
  for(int i=0;i<n;i++){
    if(v[i]){
      continue;
    }
    C++;
    v[i]=1;
    int j=P[i];
    while(j!=i){
      v[j]=1;
      j=P[j];
    }
  }
  if(C==1){
    C=0;
  }
  int K=0;
  for(int i=0;i<n;i++){
    K+=b[i];
  }
  if(K%2==0){
    C++;
  }
  printf("%d\n",C);
  return 0;
}