#include <bits/stdc++.h>
#ifdef LOCAL
#define dbg(args...) std::cerr << "\033[32;1m" << #args << " -> ", err(args)
#else
#define dbg(...)
#endif
inline void err() { std::cerr << "\033[0m\n"; }
template<class T, class... U>
inline void err(const T &x, const U &... a) { std::cerr << x << ' '; err(a...); }
template <class T>
inline void readInt(T &w) {
  char c, p = 0;
  while (!isdigit(c = getchar())) p = c == '-';
  for (w = c & 15; isdigit(c = getchar());) w = w * 10 + (c & 15);
  if (p) w = -w;
}
template <class T, class... U>
inline void readInt(T &w, U &... a) { readInt(w), readInt(a...); }
template <class T, class U>
inline bool smin(T &x, const U &y) { return y < x ? x = y, 1 : 0; }
template <class T, class U>
inline bool smax(T &x, const U &y) { return x < y ? x = y, 1 : 0; }

typedef long long LL;
typedef std::pair<int, int> PII;

constexpr int N(2e5 + 5);
int n, a[N];
LL dp[N][3][2];
int main() {
  readInt(n);
  for (int i = 1; i <= n; i++) readInt(a[i]);
  if (n == 1) return std::cout << a[1], 0;
  memset(dp, 0xcf, sizeof dp);
  dp[0][0][1] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 3; j++) {
      smax(dp[i][j][0], dp[i - 1][(j + 2) % 3][0] + a[i]);
      smax(dp[i][j][0], dp[i - 1][j][0] - a[i]);
      smax(dp[i][j][i & 1], dp[i - 1][(j + 2) % 3][1] + a[i]);
      smax(dp[i][j][i & 1 ^1], dp[i - 1][j][1] - a[i]);
    }
  }
  std::cout << dp[n][((5 - n % 3) % 3)][0];
  return 0;
}