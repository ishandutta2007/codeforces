#include <bits/stdc++.h>
#define perr(a...) fprintf(stderr, a)
#define dbg(a...) perr("\033[32;1m"), perr(a), perr("\033[0m")
template <class T, class U>
inline bool smin(T &x, const U &y) {
  return y < x ? x = y, 1 : 0;
}
template <class T, class U>
inline bool smax(T &x, const U &y) {
  return x < y ? x = y, 1 : 0;
}

using LL = long long;
using PII = std::pair<int, int>;


constexpr int Primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};

constexpr int P(1e9 + 7);

int p[20];
int ins(int x) {
  for (int i = 19; i >= 0; i--) {
    if (x >> i & 1 ^ 1) continue;
    if (!p[i]) return p[i] = x, i;
    x ^= p[i];
  }
  return -1;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  int ans = 1;
  while (n--) {
    int x, a = 0;
    std::cin >> x;
    for (int i = 0; x > 1; i++) {
      while (x % Primes[i] == 0) x /= Primes[i], a ^= 1 << i;
    }
    if (ins(a) == -1) ans = 2LL * ans % P;
  }
  ans = (ans + P - 1) % P;
  std::cout << ans << "\n";
  return 0;
}