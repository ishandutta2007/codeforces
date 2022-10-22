#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<array<int,2>> b;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int l;
        cin >> l;
        b.push_back({l,i});
      }
    }
    sort(b.begin(), b.end());
    vector<vector<int>> ans(n, vector<int>(m));
    for (int j = 0; j < m; j++) {
      auto [l,i] = b[j];
      ans[i][j] = l;
    }
    vector<int> ind(n);
    for (int j = m; j < n*m; j++) {
      auto [l,i] = b[j];
      while (ans[i][ind[i]]) ind[i]++;
      ans[i][ind[i]] = l;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        cout << ans[i][j] << ' ';
      cout << endl;
    }
  }
}