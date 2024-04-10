#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> p(n);
    vector<vector<int>> acc(n+1, vector<int>(n+1));
    for (int i = 0; i < n; i++) {
      cin >> p[i];
      p[i]--;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= n; j++) {
        acc[i+1][j] = acc[i][j]+(p[i]<j);
      }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i+1; j < n; j++) {
        ans += acc[i][p[j]]*(acc[n][p[i]]-acc[j+1][p[i]]);
      }
    }
    cout << ans << endl;
  }
}