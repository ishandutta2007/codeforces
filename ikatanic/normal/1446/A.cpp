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
    int N;
    i64 W;
    cin >> N >> W;
    vector<i64> a(N);
    for (int i = 0; i < N; ++i) {
      cin >> a[i];
    }

    vector<int> res;
    for (int i = 0; i < N; ++i) {
      if (a[i] <= W && a[i] * 2 >= W) {
        res = {i};
        break;
      }
    }

    if (!res.size()) {
      i64 sum = 0;
      for (int i = 0; i < N; ++i) {
        if (a[i] * 2 < W && sum + a[i] <= W) {
          sum += a[i];
          res.push_back(i);
        }
      }

      if (sum * 2 < W) {
        res.clear();
      }
    }

    if (!res.size()) {
      cout << "-1\n";
    } else {
      cout << res.size() << '\n';
      for (int x : res) cout << x + 1 << ' ';
      cout << '\n';
    }
  }

  return 0;
}