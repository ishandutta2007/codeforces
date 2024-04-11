#include "bits/stdc++.h"

using namespace std;

int main()
{
  int n, x, y;
  scanf("%d%d%d", &n, &x, &y);
  while(n--)
  {
    int t;
    scanf("%d", &t);
    t %= (x+y);
    long long l = 0, r = 1LL*x*y;
    while(l < r)
    {
       long long m = (l+r)/2;
       long long a = m/x;
       long long b = m/y;
       if(a+b >= t)
      r = m;
       else
          l = m+1;
    }
    if(l%x==0 and l%y==0)
      puts("Both");
    else if(l%y==0)
      puts("Vanya");
    else
      puts("Vova");
  }
}