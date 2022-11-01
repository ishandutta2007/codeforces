#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int ll;

ll gcd(ll a, ll b)
{
  while(b)
  {
    a %= b;
    swap(a, b);
  }

  return a;
}

ll next(ll a, ll x)
{
  return a - a % x + x;
}

int main(int argc, char** argv)
{
  ll x, y, A, l, r;
  cin >> l >> r >> x >> y;
  A = x * y;

  ll counter = 0;

  for(ll i = max(A / r, l); i * l <= A && i <= r; i = next(i, x))
  {
    if(A % i == 0)
    {
      ll j = A / i;

      if(j % x != 0)
        continue;

      if(gcd(i, j) != x)
        continue;

      // cout << "i,j=" << i << "," << j << endl;

      if(i < j)
      {
        counter += 2;
      }
      else if(i == j)
      {
        ++counter;
        break;
      }
      else
      {
        break;
      }
    }
  }

  cout << counter << endl;

  return 0;
}