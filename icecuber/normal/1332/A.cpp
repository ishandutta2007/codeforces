#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, d;
    int x, y, x1, y1, x2, y2;
    cin >> a >> b >> c >> d;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;
    x1 -= x, y1 -= y, x2 -= x, y2 -= y;
    int ex = b-a, ey = d-c;
    if (ex > x2 || ex < x1 || ey > y2 || ey < y1 || x1==x2 && a || y1==y2 && c)
      cout << "No" << endl;
    else cout << "Yes" << endl;
  }
}