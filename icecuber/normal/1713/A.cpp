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
    int maxx = 0, minx = 0, maxy = 0, miny = 0;
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      maxx = max(maxx, x);
      maxy = max(maxy, y);
      minx = min(minx, x);
      miny = min(miny, y);
    }
    cout << (maxx+maxy-minx-miny)*2 << endl;
  }
}