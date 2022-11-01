#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a,long long b)
{
  return b==0?a:gcd(b,a%b);
}


int main()
{
  int n;
  long long k;
  scanf("%d%lld",&n,&k);
  long long a=1;
  for(int i=0;i<n;i++){
    long long c;
    scanf("%lld",&c);
    long long g=gcd(c,k);
    a*=g/gcd(g,a);
  }
  puts(a==k?"Yes":"No");
  return 0;
}