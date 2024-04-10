#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  int N=1;
  for(int t=0;t<n;t++){
    N*=2;
    if(N>m)break;
  }
  printf("%d\n",m%N);
  return 0;
}