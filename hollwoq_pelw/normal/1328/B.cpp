#include <bits/stdc++.h>

using namespace std;

#define pb push_back

#define int long long

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int l = n - 1;
    while (k - (n - l - 1) > 0) {
      k -= (n - l - 1);
      l--;
    }
    int r = (n - k);
    for (int i = 0; i < n; ++i) {
      if (i == l || i == r)
        cout << 'b';
      else
        cout << 'a';
    }
    cout << '\n';
  }
  return 0;
}