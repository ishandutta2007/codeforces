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

const int MaxN = 1000000;

int n;
int f[MaxN + 1];

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    ++f[max(1, i - getint())];
    --f[i];
  }

  int res = 0;
  for (int i = 1; i <= n; ++i) {
    f[i] += f[i - 1];
    res += f[i] == 0;
  }

  cout << res << endl;

  return 0;
}