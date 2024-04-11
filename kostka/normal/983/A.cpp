//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define SZ(x) int(x.size())
#define ll long long
#define pii pair <int, int>
#define vi vector <int>

bool test() {
  ll p, q, b;
  cin >> p >> q >> b;
  if(p == 0) return true;
  q /= __gcd(p, q);
  while(q>1) {
    ll e = __gcd(q, b);
    if(e == 1) return false;
    else {
      while(q%e == 0) q /= e;
    }

  }
  return true;
}

int main()
{
  ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while(t--) puts(test() ? "Finite" : "Infinite");
  return 0;
}