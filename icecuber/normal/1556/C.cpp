#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<ll> c(n);
  for (ll&v : c) cin >> v;
  unsigned long long ans = 0;
  for (int l = 0; l < n; l++) {
    if (l%2) continue;
    ll acc = c[l], mi = acc-1, cnt = 0;
    for (int r = l+1; r < n; r++) { 
      if (r%2 && mi >= 0) {
        ll a = max(0ll, acc-c[r]), b = min(acc, mi+1);
//cout << l << ' '<< r << ' ' << b-a+cnt << endl;
        ans += max(b-a, 0ll);
      }
      acc += c[r]*(r%2?-1:1);
      if (acc < mi) {
        mi = acc;
        cnt = 2;
      } else if (acc == mi) {
        cnt++;
      }
    }
  }
  cout << ans << endl;
}