#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int q, m;
  cin >> q >> m;
  vector<int> a(m);
  int ans = 0;
  while (q--) {
    int y;
    cin >> y;
    y %= m;
    a[y]++;
    while (a[ans%m] >= ans/m+1) ans++;
    cout << ans << '\n';
  }
}