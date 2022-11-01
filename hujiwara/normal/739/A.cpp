#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  static int L[100010],R[100010];
  int M=n;
  for(int i=0;i<m;i++){
    scanf("%d%d",L+i,R+i);
    M=min(M,R[i]-L[i]+1);
  }
  printf("%d\n",M);
  for(int i=0;i<n;i++){
    printf("%d%c",i%M,i==n-1?'\n':' ');
  }
  return 0;
}