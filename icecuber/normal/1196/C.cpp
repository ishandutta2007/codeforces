#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int xmax = 1e5, xmin = -1e5, ymax = 1e5, ymin = -1e5;
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      int mx, py, px, my;
      cin >> mx >> py >> px >> my;
      if (!mx) xmin = max(xmin, x);
      if (!my) ymin = max(ymin, y);
      if (!px) xmax = min(xmax, x);
      if (!py) ymax = min(ymax, y);
    }
    if (xmax < xmin || ymax < ymin) {
      cout << 0 << '\n';
    } else {
      cout << 1 << ' ' << xmin << ' ' << ymin << '\n';
    }
  }
}