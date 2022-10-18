#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>

#define TRACE(x) std::cerr << #x << " = " << x << "\n"
#define _ << " _ " <<

using namespace std;
using i64 = int64_t;

int main() {
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<i64> a(n), c(m);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      --a[i];
    }
    for (int i = 0; i < m; ++i) {
      cin >> c[i];
    }
    sort(a.begin(), a.end());

    i64 ps = 0;
    for (int i = 0; i < n; ++i) {
      ps += c[a[i]];
    }
    i64 ret = ps;

    i64 ms = 0;
    for (int k = n - 1; k >= 0 && n - k <= m; --k) {
      ms = max(ms, k - c[a[k]]);
      ps -= c[a[k]];
      ps += c[n - k - 1];
      if (ms <= k) {
        ret = min(ret, ps);
      }
    }

    cout << ret << '\n';
  }

  return 0;
}