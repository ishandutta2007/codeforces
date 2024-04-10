#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<array<int,2>> p(n);
    for (auto&[x,y] : p) cin >> x >> y;
    int ans = -1;
    for (auto&[x,y] : p) {
      int ok = 1;
      for (auto&[j,i] : p) {
        if (abs(x-j)+abs(y-i) > k) ok = 0;
      }
      if (ok) ans = 1;
    }
    cout << ans << endl;
  }
}