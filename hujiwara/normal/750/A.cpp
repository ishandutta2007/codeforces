#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,k;
  scanf("%d%d",&n,&k);
  int t=4*60-k;
  int i=0;
  while(i+1<=n&&5*(i+1)<=t){
    t-=5*(i+1);
    i++;
  }
  printf("%d\n",i);
  return 0;
}