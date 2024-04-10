#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while(t--) {
    int n, m;
    cin >> n >> m;

    int x[8], y[8];
    int a[9][9] = {};
    for(int i = 0; i < m; ++i) {
      cin >> x[i] >> y[i];
      for(int j = 1; j <= n; ++j) { ++a[j][y[i]]; ++a[x[i]][j]; }
    }
    int ans = 0;
    for(int i = 0; i < m; ++i) {
      for(int j = 1; j <= n; ++j) {
        --a[j][y[i]]; --a[x[i]][j];
        if(j != x[i] && !a[j][y[i]]) ans = 1;
        if(j != y[i] && !a[x[i]][j]) ans = 1;
      }
      for(int j = 1; j <= n; ++j) { ++a[j][y[i]]; ++a[x[i]][j]; }
    }
    cout << (ans ? "YES\n" : "NO\n");
  }

  return 0;
}