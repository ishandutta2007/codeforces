#include <iostream>
#include <algorithm>

typedef long long i64;

i64 solve(int a, int b, int c, int l) {
  int t = std::min(c - a - b + l, 2 * l);
  if (t < 0) return 0;
  t /= 2;
  return (t + 1LL) * (t + 2LL) / 2;
}

int a, b, c, l;

int main() {
  std::cin >> a >> b >> c >> l;
  if (a > b) std::swap(a, b);
  if (a > c) std::swap(a, c);
  if (b > c) std::swap(b, c);
  i64 ans = 0;
  for (int i = 0; i <= l; ++i) {
    ans += (i + 2LL) * (i + 1LL) / 2;
    ans -= solve(a, b, c, i);
    ans -= solve(a, c, b, i);
    ans -= solve(b, c, a, i);
  }
  std::cout << ans << '\n';
  return 0;
}