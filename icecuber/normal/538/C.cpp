#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  int lastd = -1, lasth = -1;
  int ok = 1, ans = -1e9;
  for (int i = 0; i < m; i++) {
    int d, h;
    cin >> d >> h;
    if (lastd != -1 && abs(h-lasth) > d-lastd) ok = 0;
    ans = max(ans, h);
    ans = max(ans, d-lastd+h+lasth >> 1);
    if (lastd == -1) ans = max(ans, h+d-1);
    lastd = d;
    lasth = h;
  }
  ans = max(ans, lasth+n-lastd);
  if (!ok) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  cout << ans << endl;
}