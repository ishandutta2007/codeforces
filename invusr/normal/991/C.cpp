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

int main() {
  s64 n;
  cin >> n;

  s64 l = 1, r = n;
  while (l <= r) {
    s64 mid = l + r >> 1;

    s64 cur = n, sum = 0;
    while (cur > 0) {
      s64 d = min(cur, mid);
      sum += d, cur -= d;
      cur -= cur / 10;
    }

    if (sum * 2 >= n) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  cout << l << endl;

  return 0;
}