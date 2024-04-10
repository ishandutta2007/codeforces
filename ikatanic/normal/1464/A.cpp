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

    vector<int> a(n, -1);
    for (int i = 0; i < m; ++i) {
      int x, y;
      cin >> x >> y;
      --x, --y;
      a[x] = y;
    }

    int ret = 0;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) {
      if (a[i] == -1 || visited[i]) continue;

      int x = i;
      int cnt = 0;
      while (x != -1 && !visited[x]) {
        visited[x] = true;
        cnt++;
        x = a[x];
      }
      if (x == -1) {
        ret += cnt - 1;
        continue;
      }

      if (x != i) {
        ret += cnt;
        continue;
      }
      assert(x == i);
      if (cnt > 1) ret += cnt + 1;
    }

    cout << ret << '\n';
  }

  return 0;
}