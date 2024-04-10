#include <bits/stdc++.h>
using namespace std;

int main()
{
  /*static bool E[1000010]={0};
  for(int i=2;i<=1000000;i++){
    if(E[i]){
      continue;
    }
    for(int j=2*i;j<=1000000;j+=i){
      E[j]=1;
    }
    }*/
  long long n,k;
  scanf("%lld%lld",&n,&k);
  while(n>1&&k>0){
    long long m=n;
    for(int i=2;(long long)i*i<=n;i++){
      if(n%i==0){
	n/=i;
	m/=i;
	m*=i-1;
	while(n%i==0){
	  n/=i;
	}
      }
    }
    if(n>1){
      m/=n;
      m*=n-1;
    }
    n=m;
    k-=2;
  }
  printf("%lld\n",n%1000000007ll);
  return 0;
}