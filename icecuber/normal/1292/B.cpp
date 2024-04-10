#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define x first
#define y second

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll x0, y0, ax, ay, bx, by;
  cin >> x0 >> y0 >> ax >> ay >> bx >> by;
  ll sx, sy, t;
  cin >> sx >> sy >> t;
  vector<pair<ll,ll>> p = {{x0, y0}};
  while (1) {
    auto [x,y] = p.back();
    x = x*ax+bx;
    y = y*ay+by;
    if (abs(x) > 2e16 || abs(y) > 2e16) break;
    p.emplace_back(x, y);
  }
  //#warning Print
  //for (auto [x,y] : p) cout << x << ' ' << y << endl;
  int n = p.size();
  int ans = 0;
  for (int l = 0; l < n; l++) {
    for (int r = 0; r < n; r++) {
      ll dl = abs(p[l].x-sx)+abs(p[l].y-sy);
      ll dr = abs(p[r].x-sx)+abs(p[r].y-sy);
      ll dlr = abs(p[l].x-p[r].x)+abs(p[l].y-p[r].y);
      if (min(dl,dr)+dlr <= t)
	ans = max(ans, r-l+1);
    }
  }
  cout << ans << endl;
}