//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

unordered_map <long long, long long> D, J;

long long dl(long long x)
{
  if(x <= 1)
  {
    J[x] = (x%2);
    return D[x] = 1;
  }
  if(D.find(x) != D.end())
    return D[x];
  D[x] = 2 * dl(x/2) + 1;
  J[x] = 2 * J[x/2] + (x%2 ? 1 : 0);
  return D[x];
}

long long foo(long long x, long long val)
{
  if(x == 0)
    return 0;
  if(val <= 1)
    return val;
  if(D[val/2] > x)
    return foo(x, val/2);
  if(D[val/2] == x)
    return J[val/2];
  if(D[val/2]+1 == x)
    return J[val/2] + (val % 2 ? 1 : 0);
  return J[val/2] + (val % 2 ? 1 : 0) + foo(x - D[val/2] - 1, val/2);
}

int main()
{
  long long n;
  cin >> n;
  long long l, r;
  cin >> l >> r;
  dl(n);
  cout << foo(r, n) - foo(l-1, n) << "\n";
  return 0;
}