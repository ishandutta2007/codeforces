#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using s64 = long long;
using u64 = unsigned long long;

using r32 = double;
using r64 = long double;

const int MaxN = 100000;

int n;
int a[MaxN * 2 + 1];

int main() {
  cin >> n;
  for (int i = 1; i <= n * 2; ++i) {
    scanf("%d", &a[i]);
  }

  sort(a + 1, a + n * 2 + 1);

  s64 res = LONG_LONG_MAX;
  res = min(res, (s64)(a[n] - a[1]) * (a[n * 2] - a[n + 1]));
  res = min(res, (s64)(a[n * 2] - a[1]) * (a[n * 2 - 1] - a[n]));
  for (int i = n + 1; i < n * 2; ++i) {
    int l = n - (n * 2 - i);
    res = min(res, (s64)(a[i] - a[1]) * (a[n * 2] - a[i - l]));
    res = min(res, (s64)(a[n * 2] - a[1]) * (a[i] - a[i - n + 1]));
  }
  cout << res << endl;

  return 0;
}