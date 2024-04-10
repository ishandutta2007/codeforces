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
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;

    bool can = false;
    for (int i = 0; i < n; ++i) {
      bool ok = true;
      for (int j = 0; j < n; ++j) {
        if (abs(a[i].first - a[j].first) + abs(a[i].second - a[j].second) > k) {
          ok = false;
          break;
        }
      }
      can |= ok;
    }

    cout << (can ? 1 : -1) << "\n";
  }

  return 0;
}