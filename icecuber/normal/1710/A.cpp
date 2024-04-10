#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int w, h, n;
    cin >> w >> h >> n;
    vector<ll> a(n);
    for (ll&v : a) cin >> v;
    int ok = 0;
    for (int _ : {0,1}) {
      swap(w,h);
      ll sum = 0, all2 = 1;
      for (ll v : a) {
        ll x = v/h;
        if (x >= 2) {
          sum += x;
          all2 &= x==2;
        }
      }
      ok |= (sum >= w && !(all2 && sum%2 != w%2));
    }
    cout << (ok ? "Yes" : "No") << endl;
  }
}