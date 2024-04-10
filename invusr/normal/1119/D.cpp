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

const int N = 123456;

int n, q;
s64 a[N], b[N], c[N];

int main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);

  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &a[i]);
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i < n; ++i) {
    b[i] = a[i + 1] - a[i];
  }
  sort(b + 1, b + n);
  for (int i = 1; i < n; ++i) {
    c[i] = c[i - 1] + b[i];
  }
  scanf("%d", &q);
  while (q--) {
    s64 l, r;
    scanf("%lld%lld", &l, &r);
    int k = lower_bound(b + 1, b + n, r - l + 1) - b;
    s64 answer = (r - l + 1) * (n - k + 1) + c[k - 1];
    printf("%lld ", answer);
    // [1, k-1]
    // x<=l, l<x<=r
  }

  return 0;
}