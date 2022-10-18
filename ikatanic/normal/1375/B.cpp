#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>

#define TRACE(x) std::cout << #x << " = " << x << "\n"
#define _ << " _ " <<

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (i > 0) a[i][j]++;
        if (j > 0) a[i][j]++;
        if (i < n - 1) a[i][j]++;
        if (j < m - 1) a[i][j]++;
      }
    }

    bool ok = true;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int x;
        cin >> x;
        ok &= x <= a[i][j];
      }
    }

    if (!ok) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          cout << a[i][j] << ' ';
        }
        cout << '\n';
      }
    }
  }
  return 0;
}