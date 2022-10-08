//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

unordered_map <long long, long long> CO;

int poziom(long long x)
{
  return 63-__builtin_clzll(x);
}

int main()
{
  int q;
  cin >> q;
  while(q--)
  {
    int a;
    cin >> a;
    if(a == 1)
    {
      long long p,q;
      int r;
      cin >> p >> q >> r;
      if(poziom(p) < poziom(q))
        swap(p,q);
      while(poziom(p) != poziom(q))
      {
        CO[p] += r;
        p = p/2;
      }
      while(p != q)
      {
        CO[p] += r;
        p = p/2;
        CO[q] += r;
        q = q/2;
      }
    }
    else
    {
      long long p, q;
      cin >> p >> q;
      long long res = 0;
      if(poziom(p) < poziom(q))
        swap(p,q);
      while(poziom(p) != poziom(q))
      {
        res += CO[p];
        p = p/2;
      }
      while(p != q)
      {
        res += CO[p];
        p = p/2;
        res += CO[q];
        q = q/2;
      }
      cout << res << "\n";
    }
  }
  return 0;
}