#include <bits/stdc++.h>
using namespace std;

const int INF=1000000000;

int main()
{
  int n;
  scanf("%d",&n);
  int m=-INF,M=INF;
  for(int i=0;i<n;i++){
    int a,d;
    scanf("%d%d",&a,&d);
    if(d==1){
      m=max(m,1900);
    }
    else if(d==2){
      M=min(M,1899);
    }
    m+=a;
    M+=a;
  }
  if(m>M){
    puts("Impossible");
  }
  else if(M>INF/2){
    puts("Infinity");
  }
  else{
    printf("%d\n",M);
  }
  return 0;
}