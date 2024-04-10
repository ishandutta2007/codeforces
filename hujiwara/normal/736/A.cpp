#include <bits/stdc++.h>

using namespace std;

int main()
{
  long long A;
  scanf("%I64d",&A);
  long long F[100];
  F[0]=1,F[1]=2;
  int t=2;
  while(F[t-1]+F[t-2]<=A){
    F[t]=F[t-1]+F[t-2];
    t++;
  }
  printf("%d\n",t-1);
  return 0;
}