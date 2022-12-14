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

const int N = 333333;

int n, a[N];

int main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);

  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  int l = 1;
  while (l < n && a[l + 1] == a[1]) {
    ++l;
  }
  int res = 0;
  for (int i = 2; i <= n; ++i) {
    if (a[i] != a[1]) {
      res = max(res, i - 1);
    } else {
      res = max(res, i - l - 1);
    }
  }
  cout << res << endl;

  return 0;
}