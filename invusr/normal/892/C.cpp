#include <bits/stdc++.h>
using namespace std;

inline int getint() {
  static char c;
  while ((c = getchar()) < '0' || c > '9');

  int res = c - '0';
  while ((c = getchar()) >= '0' && c <= '9') {
    res = res * 10 + c - '0';
  }
  return res;
}

inline int gcd(const int &a, const int &b) {
  return b ? gcd(b, a % b) : a;
}

const int MaxN = 100000;
const int MaxLogN = 16;

int n;
int a[MaxN + 1];

int g[MaxN + 1];
int f[MaxLogN + 1][MaxN + 1];

inline void preprocess() {
  g[1] = 0;
  for (int i = 2; i <= n; ++i) {
    g[i] = g[i >> 1] + 1;
  }

  copy(a, a + n + 1, f[0]);
  for (int k = 0; k < g[n]; ++k) {
    int l = 1 << k + 1;
    for (int i = 1; i + l - 1 <= n; ++i) {
      int a = f[k][i];
      int b = f[k][i + (1 << k)];
      f[k + 1][i] = gcd(a, b);
    }
  }
}

inline int query(int l, int r) {
  int k = g[r - l + 1];
  int a = f[k][l];
  int b = f[k][r - (1 << k) + 1];
  return gcd(a, b);
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    a[i] = getint();
  }

  int l = count(a + 1, a + n + 1, 1);
  if (l > 0) {
    cout << n - l << endl;
    return 0;
  }

  preprocess();

  int res = n + 1;
  for (int i = 1; i <= n; ++i) {
    int l = i, r = n;
    while (l <= r) {
      int mid = l + r >> 1;
      if (query(i, mid) == 1) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }

    if (l <= n) {
      res = min(res, l - i + 1);
    }
  }

  cout << (res <= n ? res + n - 2 : -1) << endl;

  return 0;
}