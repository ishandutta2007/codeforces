#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <algorithm>

typedef long double f128;

const int N = 100 + 10;

int n;
f128 p[N];

int main() {
  std::cin >> n;
  for (int i = 1; i <= n; ++i) std::cin >> p[i], p[i] = 1. - p[i] / 100.;
  f128 ans = 1.;
  static int cnt[N];
  static f128 cur[N], mem[N];
  for (int i = 1; i <= n; ++i) mem[i] = 1.;
  while (clock() < 1.7 * CLOCKS_PER_SEC) {
    for (int i = 1; i <= n; ++i) cur[i] = (1. - mem[i]) / (1. - mem[i] * p[i]);
    int k = std::min_element(cur + 1, cur + n + 1) - cur;
    for (int i = 1; i <= n; ++i) {
      if (mem[i] == 1.) {
        k = i;
        break;
      }
    }
    mem[k] *= p[k];
    f128 temp = 1.;
    for (int i = 1; i <= n; ++i) temp *= 1. - mem[i];
    ans += 1. - temp;
  }
  std::cout << std::setprecision(12) << std::fixed << ans << std::endl;
  return 0;
}