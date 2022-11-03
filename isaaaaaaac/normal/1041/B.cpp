#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

long long a, b, x, y;

int main() {
  cin >> a >> b >> x >> y;
  long long d = __gcd(x, y);
  x /= d; y /= d;
  printf("%lld\n", min(a / x, b / y));
  return 0;
}