#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll sx, sy;
    cin >> sx >> sy;
    ll ca, cb;
    cin >> ca >> cb;
    ll wa, wb;
    cin >> wa >> wb;
    if (wa > wb) swap(wa, wb), swap(ca, cb);

    ll ans = 0;
    for (int ax = 0; ax <= ca && ax*wa <= sx; ax++) {
      ll bx = min(cb, (sx-ax*wa)/wb);

      ll ay = min(ca-ax, sy/wa);
      ll by = min(cb-bx, (sy-ay*wa)/wb);
      ans = max(ans, ax+bx+ay+by);
    }
    cout << ans << endl;
  }
}