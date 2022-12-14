#include <iostream>
#include <algorithm>

typedef long long i64;

const int N = 50 + 10;
//const i64 INF = 1LL << 60;

int n;
i64 k;

int ans[N];

i64 f[N];

int main() {
  f[0] = f[1] = 1;
  for (int i = 2; i < N; ++i) {
    f[i] = f[i - 1] + f[i - 2];
    //    double temp = f[i - 1] + f[i - 2] * (i - 1.);
    //    if (temp >= INF) f[i] = INF; else f[i] = std::min(f[i - 1] + f[i - 2] * (i - 1), INF);
  }
  std::cin >> n >> k;
  static bool flag[N];
  int rem = n;
  for (int i = 1; i <= n; ++i) {
    if (ans[i]) continue;
    for (int j = i; j <= i + 1; ++j) {
      if (flag[j]) continue;
      ans[i] = j;
      ans[j] = i;
      int cur = rem - 1 - (i != j);
      if (f[cur] >= k) {
        flag[i] = flag[j] = true;
        rem = cur;
        break;
      } else {
        k -= f[cur];
        ans[i] = ans[j] = 0;
      }
    }
  }
  for (int i = 1; i <= n; ++i) std::cout << ans[i] << ' ';
  return 0;
}