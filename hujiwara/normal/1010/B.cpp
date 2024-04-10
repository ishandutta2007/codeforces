#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long m;
  int n;
  scanf("%lld%d",&m,&n);
  int p[100];
  for(int i=0;i<n;i++){
    printf("1\n");
    fflush(stdout);
    scanf("%d",p+i);
    if(p[i]==0){
      return 0;
    }
  }
  long long L=0,R=m+1;
  for(int i=0;;i=(i+1)%n){
    long long M=(L+R)/2;
    printf("%lld\n",M);
    fflush(stdout);
    int q;
    scanf("%d",&q);
    if(q==0)return 0;
    q*=p[i];
    if(q>0){
      L=M;
    }
    else{
      R=M;
    }
  }
  return 0;
}