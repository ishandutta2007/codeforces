#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using s64 = long long;
using u64 = unsigned long long;
using r32 = double;
using r64 = long double;

template <class T>
inline bool relax(T &a, T b) {
  return b > a ? a = b, true : false;
}
template <class T>
inline bool tense(T &a, T b) {
  return b < a ? a = b, true : false;
}

const int N = 1234;

int n, m;
int a[N], b[N];

int main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);

  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  for (int i = 1; i <= n; ++i) {
    int mx = 0;
    for (int j = 1; j <= i; ++j) {
      b[j] = a[j];
    }
    sort(b + 1, b + i + 1);
    for (int j = 1; j <= i; j += 2) {
      if (j < i) {
        mx += b[j + 1];
      } else {
        mx += b[j];
      }
    }

    if (i & 1) {
      int tmp = b[1];
      for (int j = 2; j <= i; j += 2) {
        tmp += b[j + 1];
      }
      mx = min(mx, tmp);
    }

    if (mx > m) {
      cout << i - 1 << endl;
      return 0;
    }
  }
  cout << n << endl;

  return 0;
}