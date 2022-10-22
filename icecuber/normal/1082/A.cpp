#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, x, y, d;
    cin >> n >> x >> y >> d;
    int ans = 2e9;
    if ((y-x)%d==0) ans = abs(y-x)/d;
    if ((y-1)%d==0)
      ans = min(ans, (y-1)/d+(x-1+d-1)/d);
    if ((y-n)%d==0)
      ans = min(ans, (n-y)/d+(n-x+d-1)/d);
    if (ans == 2e9) ans = -1;
    cout << ans << endl;
  }
}