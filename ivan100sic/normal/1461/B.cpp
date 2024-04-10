// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    vector<vector<int>> d(n, vector<int>(m, 0));

    auto g = [&](int x, int y) {
      if (x >= 0 && y >= 0 && x < n && y < m) return d[x][y];
      return 0;
    };

    for (int i=0; i<n; i++) {
      for (int j=0; j<m; j++) {
        if (a[i][j] == '.') {
          continue;
        }

        d[i][j] = 1 + min({g(i-1, j), g(i, j-1), g(i, j+1)});
      }

      for (int r=0; r<500; r++) {
        for (int j=m-1; j>=0; j--) {
          if (a[i][j] == '.') {
            continue;
          }
          d[i][j] = max(d[i][j], 1 + min({g(i-1, j), g(i, j-1), g(i, j+1)}));
        }

        for (int j=0; j<m; j++) {
          if (a[i][j] == '.') {
            continue;
          }
          d[i][j] = max(d[i][j], 1 + min({g(i-1, j), g(i, j-1), g(i, j+1)}));
        }
      }
    }

    int z = 0;

    for (int i=0; i<n; i++) {
      for (int j=0; j<m; j++) {
        z += d[i][j];
      }
    }

    cout << z << '\n';
  }
}