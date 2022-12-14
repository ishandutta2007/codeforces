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

int n;
int a[MaxN + 1], sum = 0;

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    sum += a[i] * 10;
  }

  sort(a + 1, a + n + 1);

  if (sum >= 45 * n) {
    cout << 0 << endl;
    return 0;
  }

  for (int i = 1; i <= n; ++i) {
    sum -= a[i] * 10;
    sum += 50;
    if (sum >= 45 * n) {
      cout << i << endl;
      break;
    }
  }

  return 0;
}