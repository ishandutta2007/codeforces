#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int q;
  cin >> q;
  int maxx = 0, maxy = 0;
  while (q--) {
    char c;
    int x, y;
    cin >> c >> x >> y;
    if (x < y) swap(x,y);
    if (c == '+') {
      maxx = max(maxx, x);
      maxy = max(maxy, y);
    } else {
      cout << (maxx <= x && maxy <= y ? "YES" : "NO") << '\n';
    }
  }
}