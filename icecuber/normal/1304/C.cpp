#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, init;
    cin >> n >> init;
    int mi = init, ma = init;
    int lastt = 0;
    int ok = 1;
    for (int i = 0; i < n; i++) {
      int t, l, h;
      cin >> t >> l >> h;
      int dt = t-lastt;
      mi = max(mi-dt, l);
      ma = min(ma+dt, h);
      if (mi > ma) ok = 0;
      lastt = t;
    }
    cout << (ok ? "YES" : "NO") << endl;
  }
}