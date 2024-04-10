#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int w, h, u1, d1, u2, d2;
  cin >> w >> h >> u1 >> d1 >> u2 >> d2;
  while (h) {
    w += h;
    if (h == d1) w = max(w-u1,0);
    if (h == d2) w = max(w-u2,0);
    h--;
  }
  cout << w << endl;
}