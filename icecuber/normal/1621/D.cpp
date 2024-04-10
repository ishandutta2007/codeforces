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
    vector<vector<ll>> cost(n*2, vector<ll>(n*2));
    ll base = 0;
    for (int i = 0; i < n*2; i++) {
      for (int j = 0; j < n*2; j++) {
        cin >> cost[i][j];
        if (i >= n && j >= n) {
          base += cost[i][j];
          cost[i][j] = 0;
        }
      }
    }
    ll ans = 1e18;
    for (int i : {0,1}) {
      for (int j : {0,1}) {
        ans = min(ans, cost[i?n:n*2-1][j?0:n-1]);
        ans = min(ans, cost[i?0:n-1][j?n:n*2-1]);
      }
    }
    cout << base + ans << endl;
  }
}