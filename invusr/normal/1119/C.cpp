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

const int N = 511;

int n, m, a[N][N];

int main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);

  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int x;
      cin >> x;
      a[i][j] ^= x;
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i][j]) {
        if (i == n || j == m) {
          puts("No");
          return 0;
        }
        a[i][j] ^= 1;
        a[i + 1][j] ^= 1;
        a[i][j + 1] ^= 1;
        a[i + 1][j + 1] ^= 1;
      }
    }
  }
  puts("Yes");

  return 0;
}