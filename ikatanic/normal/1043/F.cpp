#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int inf = 1e9;
const int M = 300001;

int c[M];
bool good[M];
int sgn[M];

int main(void) {
  ios_base::sync_with_stdio(false);

  c[1] = 1;
  for (int i = 2; i * i < M; ++i)
    if (!c[i])
      for (int j = i * i; j < M; j += i) c[j] = i;

  int count = 0;
  for (int x = 1; x < M; ++x) {
    good[x] = true;
    sgn[x] = 1;
    int y = x;
    while (y > 1) {
      int p = c[y] == 0 ? y : c[y];
      y /= p;
      if (y % p == 0) {
        good[x] = false;
        break;
      }
      sgn[x] *= -1;
    }
    if (good[x]) count++;
  }

  int N;
  cin >> N;

  static int B[M];
  for (int i = 0; i < N; ++i) {
    int x;
    cin >> x;

    int y = x;
    while (y > 1) {
      int p = c[y] == 0 ? y : c[y];
      y /= p;
      while (y % p == 0) {
        y /= p;
        x /= p;
      }
    }

    assert(good[x]);

    if (B[x] == 0) {
      B[x] = 1;
    }
  }

  vector<int> f(M, inf);
  f[1] = 0;
  int ret = inf;
  for (int x = 1; x < M; ++x) {
    if (!good[x] || f[x] >= ret) continue;

    if (B[x]) {
      ret = min(ret, f[x] + 1);
    }

    static int h[M];
    static int g[M];

    int n = (M - 1) / x;

    for (int i = 0; i <= n; ++i) h[i] = g[i] = 0;

    for (int i = 1; i <= n; ++i) {
      if (!good[i * x]) continue;
      for (int j = 1; i * j <= n; ++j) {
        h[i] += B[i * j * x];
      }
    }

    for (int i = 1; i <= n; ++i) {
      if (!good[i * x]) continue;

      for (int j = 1; i * j <= n; ++j) {
        g[i * j] += sgn[i] * h[i];
      }
    }

    for (int i = 2; i <= n; ++i) {
      if (g[i]) {
        f[i * x] = min(f[i * x], f[x] + 1);
      }
    }
  }

  if (ret == inf) ret = -1;

  cout << ret << "\n";
  return 0;
}