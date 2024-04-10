#include <bits/stdc++.h>
using namespace std;

long long rec(int n,long long A,long long p)
{
  //printf("%d %lld %d\n",n,A,p);
  if(n==1){
    return p==0?0:A;
  }
  if(p<=(1ll<<(n-1))-1ll){
    return rec(n-1,A/2,p);
  }
  return A/2+A%2+rec(n-1,A/2,p-(1ll<<(n-1)));
}

int main()
{
  long long A;
  long long l,r;
  scanf("%lld%lld%lld",&A,&l,&r);
  l--;
  int n=1;
  while((1ll<<n)<=A){
    n++;
  }
  printf("%lld\n",rec(n,A,r)-rec(n,A,l));
  return 0;
}