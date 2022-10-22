#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int&v : a) cin >> v;
    vector<int> cost(k*2+2);
    auto add = [&](int l, int r, int v) {
      cost[l] += v;
      cost[r] -= v;
    };
    for (int i = 0; i < n/2; i++) {
      int x = a[i], y = a[n-1-i];
      add(2, k*2 +1, 2);
      add(min(x,y)+1, max(x,y)+k +1, -1);
      add(x+y, x+y +1, -1);
    }
    int ans = n;
    for (int i = 1; i < k*2+2; i++)
      cost[i] += cost[i-1];
    for (int i = 2; i <= k*2; i++) {
      ans = min(ans, cost[i]);
    }
    cout << ans << endl;
  }
}