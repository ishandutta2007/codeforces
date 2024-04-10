#include <bits/stdc++.h>
using namespace std;

typedef long long s64;

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

const int MaxN = 200000;
const int L = 1000000000;

int n;
map<int, int> f, g;
map<s64, int> h;

int main() {
  cin >> n;

  s64 res = 0;
  for (int i = 0; i < n; ++i) {
    int x = getint(), y = getint();
    s64 z = (s64)x * L + y;
    res += f[x]++, res += g[y]++;
    res -= h[z]++;
  }

  cout << res << endl;

  return 0;
}