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
    vector<pair<ll,ll>> a(n);
    for (auto&[x,y] : a) cin >> x >> y;
    ll need = 0, mi = 1e15;
    for (int i = 0; i < n; i++) {
      int j = (i+n-1)%n;
      need += max(a[i].first-a[j].second, 0ll);
      mi = min(mi, min(a[j].second,a[i].first));
    }
    cout << need+mi << endl;
  }
}