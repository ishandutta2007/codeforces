#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

bool prime(int x) {
  if (x%2 == 0) return false;
  for (int j = 3; j*j <= x; j += 2)
    if (x%j == 0) return false;
  return true;
}

llint gcd(llint a, llint b) {
  return !b ? a : gcd(b, a%b);
}

int main(void) {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    
    llint p2 = n+1, p1 = n;
    while (!prime(p1)) p1--;
    while (!prime(p2)) p2++;
    
    llint b = p1*p2*2;
    llint a = p1*p2 - 2*p1 - 2*(p2 - n - 1);
    llint g = gcd(a, b);
    a /= g, b /= g;

    cout << a << "/" << b << endl;
  }
  return 0;
}