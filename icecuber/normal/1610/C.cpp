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
    vector<array<int,2>> a(n);
    for (auto&[x,y] : a) cin >> x >> y;

    int pass = 0, fail = n+1;
    while (fail-pass > 1) {
      int m = (pass+fail)/2;
      int has = 0;
      for (auto [x,y] : a) {
        if (y >= has && x >= m-has-1) has++;
      }
      if (has >= m) pass = m;
      else fail = m;
    }
    cout << pass << endl;
  }
}