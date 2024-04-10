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
    int c[2] = {};
    for (int&v : a) {
      cin >> v;
      v %= 2;
      c[v]++;
    }
    if (abs(c[0]-c[1]) > 1) {
      cout << -1 << endl;
    } else {
      ll ans = 1e18;
      for (int k : {0,1}) {
        if (c[k] < c[!k]) continue;
        int j = 0;
        ll cnt = 0;
        for (int i = 0; i < n; i++) {
          if (a[i] == k) cnt += abs(i-j*2), j++;
        }
        ans = min(ans, cnt);
      }
      cout << ans << endl;
    }
  }
}