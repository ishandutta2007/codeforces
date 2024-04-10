#include <bits/stdc++.h>
using namespace std;

const long long INF=10000000000ll;

int main()
{
  long long k,a,b;
  scanf("%lld%lld%lld",&k,&a,&b);
  if(a<k){
    printf("%lld\n",b>0&&b%k==0?b/k:-1);
  }
  else if(b<k){
    printf("%lld\n",a>0&&a%k==0?a/k:-1);
  }
  else{
    printf("%lld\n",a/k+b/k);
  }
  return 0;
}