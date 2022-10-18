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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      --a[i];
    }

    vector<int> c(n);
    int ret = 0;
    int p = 0;
    for (int i = 1; i < n; ++i) {
      if (a[i] == a[i - 1]) {
        c[a[p]]++;
        c[a[i - 1]]++;
        p = i;
        ret++;
      }
    }

    c[a[p]]++;
    c[a[n - 1]]++;

    int m = max_element(c.begin(), c.end()) - c.begin();
    int maxExtra = 0;
    for (int i = 1; i < n; ++i) {
      if (a[i - 1] != m && a[i] != m && a[i] != a[i - 1]) maxExtra++;
    }
    if (ret < c[m] - 2) {
      if (ret + maxExtra >= c[m] - 2) {
        ret = c[m] - 2;
      } else {
        ret = -1;
      }
    }

    cout << ret << '\n';
  }

  return 0;
}