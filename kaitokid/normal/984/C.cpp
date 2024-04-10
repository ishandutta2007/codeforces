#include <bits/stdc++.h>

using namespace std;

int main()
{
    //ios::sync_with_stdio(0);
    int n;
    long long p,q,b;
  scanf("%d", &n);
  while(n--)
  {
      scanf("%I64d %I64d %I64d", &p, &q, &b);
      q/=__gcd(p,q);
    long long h=__gcd(q,b);
    while(h>1){while(q%h==0)q/=h;h=__gcd(q,b);}
      if(q==1)
      printf("Finite\n");
      else printf("Infinite\n");



  }
    return 0;
}