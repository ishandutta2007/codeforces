//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

// a_0 = 1
// b_0 = 0
// b_i = 2*a_(i-1) + b_(i-1)
// a_i = b_(i-1)

// 1 2
// 1 0

struct matrix
{
  int a, b, c, d;
  matrix(int _a, int _b, int _c, int _d)
  {
    a = _a;
    b = _b;
    c = _c;
    d = _d;
  }
};

const int MOD = 1000 * 1000 * 1000+7;

int pot(int a, long long b)
{
  if(b == 0)
    return 1;
  int q = pot(a, b/2);
  int qq = (1LL * q * q) % MOD;
  if(b % 2)
    return (1LL * qq * a) % MOD;
  else
    return qq;
}

inline matrix www(matrix a, matrix b)
{
  matrix c = matrix(0,0,0,0);
  c.a = (1LL * a.a * b.a % MOD + 1LL * a.b * b.c % MOD)%MOD;
  c.b = (1LL * a.a * b.b % MOD + 1LL * a.b * b.d % MOD)%MOD;
  c.c = (1LL * a.c * b.a % MOD + 1LL * a.d * b.c % MOD)%MOD;
  c.d = (1LL * a.c * b.b % MOD + 1LL * a.d * b.d % MOD)%MOD;
  return c;
}

inline matrix pot(matrix a, long long b)
{
  matrix res = matrix(1,0,0,1);
  while(b)
  {
    if(b%2)
      res = www(res, a);
    a = www(a, a);
    b /= 2;
  }
  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  matrix macierz = matrix(1,2,1,0);
  bool czy = false;
  for(int i=0; i<n; i++)
  {
    long long k;
    cin >> k;
    if(k > 1)
      czy = true;
    macierz = pot(macierz, k);
  }
  if(czy == false)
  {
    cout << "0/1\n";
    return 0;
  }
  macierz = www(macierz, pot(matrix(1,2,1,0), MOD-3));
  cout << macierz.a << "/" << (2LL*macierz.a + macierz.b)%MOD << "\n";
  return 0;
}