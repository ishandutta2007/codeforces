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

const int N = 200010;

int n, z;
int x[N];

bool pred(int x) {
  for (int i = 1; i <= x; ++i) {
    if (::x[n - x + i] - ::x[i] < z)
      return false;
  }
  return true;
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d%d", &n, &z);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &x[i]);
  sort(x + 1, x + n + 1);
  int l = 0, r = n / 2;
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    if (pred(mid))
      l = mid;
    else
      r = mid - 1;
  }
  printf("%d\n", l);

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}