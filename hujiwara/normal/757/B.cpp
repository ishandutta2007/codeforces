#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  scanf("%d",&n);
  static int s[100000];
  for(int i=0;i<n;i++){
    scanf("%d",s+i);
  }
  static int C[100010]={0};
  for(int i=0;i<n;i++){
    C[s[i]]++;
  }
  int M=1;
  for(int i=2;i<=100000;i++){
    int m=0;
    for(int j=i;j<=100000;j+=i){
      m+=C[j];
    }
    M=max(M,m);
  }
  printf("%d\n",M);
  return 0;
}