#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using s64 = long long;
using u64 = unsigned long long;

using r32 = double;
using r64 = long double;

inline int getint() {
  static char c;
  while (((c = getchar()) < '0' || c > '9') && c != '-');

  if (c == '-') {
    int res = 0;
    while ((c = getchar()) >= '0' && c <= '9') {
      res = res * 10 + c - '0';
    }
    return -res;
  } else {
    int res = c - '0';
    while ((c = getchar()) >= '0' && c <= '9') {
      res = res * 10 + c - '0';
    }
    return res;
  }
}

const int MaxN = 20;
const int D = 10;

char s[MaxN + 1];
int n, g[D];

s64 fac[MaxN + 1];

inline s64 binom(int n, int m) {
  return fac[n] / fac[m] / fac[n - m];
}

s64 f[D + 1][MaxN + 1];

inline s64 calc(int d) {
  int m = n - d, cur = 0;
  memset(f, 0, sizeof(f));
  f[D][0] = 1;
  for (int i = D - 1; i >= 0; --i) {
    int s = g[i];
    if (s == 0) {
      for (int j = 0; j <= cur; ++j) {
        f[i][j] = f[i + 1][j];
      }
      continue;
    }

    cur += s;
    for (int j = 1; j <= cur; ++j) {
      int l = d && i == 0 ? 0 : 1;
      for (int k = l; k <= min(s, j); ++k) {
        f[i][j] += f[i + 1][j - k] * binom(j, k);
      }
    }
  }

  s64 sum = 0;
  for (int i = 0; i <= cur; ++i) {
    sum += f[0][i];
  }
  return sum;
}

int main() {
  fac[0] = 1;
  for (int i = 1; i <= 19; ++i) {
    fac[i] = fac[i - 1] * i;
  }

  cin >> s;
  n = strlen(s);
  for (int i = 0; i < n; ++i) {
    ++g[s[i] - '0'];
  }

  s64 res = calc(0);
  if (g[0]) {
    --g[0], res -= calc(1);
  }

  cout << res << endl;

  return 0;
}