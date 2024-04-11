#include "bits/stdc++.h"

using namespace std;

bool ccc(int a)
{
  for(int i=2; i*i<=a; i++)
    if(a%i==0)
      return true;
  return false;
}

int main()
{
  int n;
  scanf("%d", &n);
  int a = n/2, b = (n+1)/2;
  while(true)
  {
    if(ccc(a) && ccc(b))
    {
      printf("%d %d\n", a, b);
      return 0;
    }
    a--;
    b++;
  }
  return 0;
}