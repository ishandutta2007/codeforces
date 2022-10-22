#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      if (a == x) ans = 1;
      ans = min(ans, max((x+a-1)/a, 2));
    }
    cout << ans << endl;
  }
}