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
    vector<int> a(n);
    for (int&v : a) cin >> v;
    int ans = n;
    if (n <= 2) ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        int cost = 0;
        for (int k = 0; k < n; k++) {
          cost += ((j-i)*(a[k]-a[i]) != (k-i)*(a[j]-a[i]));
        }
        ans = min(ans, cost);
      }
    }
    cout << ans << endl;
  }
}