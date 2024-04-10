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

const int MaxN = 100;
const int L[] = {0, 1, 1, 2};

char s[2][MaxN + 2];

int f[MaxN + 1][4];

inline int get(int k) {
  int a = s[0][k] == 'X';
  int b = s[1][k] == 'X';
  return (b << 1) | a;
}

int main() {
  cin >> s[0] + 1;
  cin >> s[1] + 1;

  int n = strlen(s[0] + 1);

  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j < 4; ++j) {
      f[i][j] = -1000000000;
    }
  }
  f[1][get(1)] = 0;
  for (int i = 2; i <= n; ++i) {
    int p = get(i);

    f[i][p] = 0;
    for (int s = 0; s < 4; ++s) {
      f[i][p] = max(f[i][p], f[i - 1][s]);
    }

    for (int s = 0; s < 4; ++s) {
      int d = f[i - 1][s] + 1;
      if (L[s] + L[p] == 0) {
        for (int j = 1; j < 4; ++j) {
          f[i][j] = max(f[i][j], d);
        }
      } else {
        if (L[s] + L[p] == 1) {
          f[i][3] = max(f[i][3], d);
        }
      }
    }
  }

  int res = 0;
  for (int i = 0; i < 4; ++i) {
    res = max(res, f[n][i]);
  }
  cout << res << endl;

  return 0;
}