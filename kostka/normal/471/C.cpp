#include "bits/stdc++.h"

using namespace std;

long long n;
int st = 81;

long long suma(long long x)
{
  return x*(x+1)/2;
}

bool check(int a, int i)
{
  long long x = st*a+i;
  long long floors = 3*suma(x)-x;
  long long res = n-floors;
  if(res>=0 && res%3==0)
    return true;
  return false;
}

int main()
{
  scanf("%I64d", &n);
  long long ile = 0;
  for(int i=0; i<st; i++)
  {
    int a = -1, b = 1000007;
    while(b-a>1)
    {
      int m = (a+b)/2;
      if(check(m,i))
        a = m;
      else
        b = m;
    }
    ile += a+1;
  }
  if(n%3==0)
    ile = max(ile-1, 0LL);
  printf("%I64d\n", ile);
  return 0;
}