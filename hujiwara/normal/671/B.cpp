#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  long long k;
  scanf("%d%lld",&n,&k);
  static long long c[500000],S=0;
  for(int i=0;i<n;i++){
    scanf("%lld",c+i);
    S+=c[i];
  }
  long long l1=0,r1=1000000010;
  while(l1+1<r1){
    double d=(l1+r1)/2;
    long long K=0,K2=0;
    for(int i=0;i<n;i++){
      if(c[i]<d){
	K+=d-c[i];
      }
      else{
	K2+=c[i]-d;
      }
    }
    if(K<=k&&K2>=K){
      l1=d;
    }
    else{
      r1=d;
    }
  }
  long long l2=-1,r2=1000000010;
  while(l2+1<r2){
    long long d=(l2+r2)/2;
    long long K=0,K2=0;
    for(int i=0;i<n;i++){
      if(c[i]>d){
	K+=c[i]-d;
      }
      else{
	K2+=d-c[i];
      }
    }
    if(K<=k&&K2>=K){
      r2=d;
    }
    else{
      l2=d;
    }
  }
  printf("%lld\n",r2-l1);
  return 0;
}