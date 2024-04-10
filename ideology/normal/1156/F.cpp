#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 5010, P = 998244353;

int n;
int cnt[N], prod[N];
int dp[N];

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  int n;
  scanf("%d", &n);
  for (int rep = 0; rep < n; ++rep) {
    int x;
    scanf("%d", &x);
    ++cnt[x];
  }
  dp[0] = 1;
  prod[1] = 1;
  for (int i = 2; i <= n; ++i)
    prod[i] = -(P / i) * (ll)prod[P % i] % P + P;
  for (int i = n - 1; i; --i)
    prod[i] = prod[i + 1] * (ll)prod[i] % P;
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (!cnt[i])
      continue;
    if (cnt[i] >= 2) {
      for (int j = 0; j <= n - 2; ++j)
        ans = (ans + ((ll)cnt[i] * (cnt[i] - 1)) % P * dp[j] % P * prod[n - j - 1]) % P;
    }
    for (int j = n; j; --j)
      dp[j] = (dp[j] + dp[j - 1] * (ll)cnt[i]) % P;
  }
  printf("%d\n", ans);

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}