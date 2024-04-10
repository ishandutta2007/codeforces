#include <iostream>

typedef long long i64;

const int N = 10000000 + 10;

int p, q;
int pi[N], rub[N];

void sieve() {
  static bool flag[N];
  static int prime[N];
  int m = 0;
  for (int i = 2; i < N; ++i) {
    if (!flag[i]) prime[++m] = i;
    for (int j = 1; j <= m && i * prime[j] < N; ++j) {
      flag[i * prime[j]] = true;
      if (i % prime[j] == 0) break;
    }
  }
  for (int i = 2; i < N; ++i) pi[i] = pi[i - 1] + !flag[i];
}

bool ispal(int x) {
  int t = x, y = 0;
  for (; x; x /= 10) y = 10 * y + x % 10;
  return y == t;
}

int main() {
  std::cin >> p >> q;
  sieve();
  for (int i = 1; i < N; ++i) rub[i] = rub[i - 1] + ispal(i);
  for (int i = N - 1; i > 0; --i) if ((i64)pi[i] * q <= (i64)rub[i] * p) return std::cout << i << '\n', 0;
  std::cout << "Palindromic tree is better than splay tree\n";
  return 0;
}