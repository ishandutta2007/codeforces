#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  scanf("%d",&n);
  int t[1000],c[1000];
  for(int i=0;i<n;i++){
    scanf("%d%d",t+i,c+i);
  }
  int L=0,M=0;
  for(int i=0;i<n;i++){
    L+=c[i];
    M=max(M,L);
    if(i+1<n){
      L=max(L-(t[i+1]-t[i]),0);
    }
  }
  printf("%d %d\n",t[n-1]+L,M);
  return 0;
}