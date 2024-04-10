#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int x = abs(x2-x1), y = abs(y2-y1);
  int dx, dy;
  cin >> dx >> dy;
  if (x%dx || y%dy || (x/dx+y/dy)%2)
    cout << "NO" << endl;
  else cout << "YES" << endl;
}