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
    vector<vector<int>> a(n, vector<int>(n));
    for (auto&v : a)
      for (int&x : v) cin >> x;

    int ans = 0;
    for (int s = 3; s < n; s += 4) 
      for (int i = 0; s+i < n; i += 2)
        ans ^= a[i][s+i]^a[n-1-i][s+i];
    for (int s = 1; s < n; s += 4) 
      for (int i = 0; s+i < n; i += 2)
        ans ^= a[s+i][i]^a[n-1-(s+i)][i];
    cout << ans << endl;
  }
}