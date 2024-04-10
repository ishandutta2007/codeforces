#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    ll n, x;
    cin >> n >> x;
    x *= 2;
    set<ll> cur;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      ll a;
      cin >> a;
      if (cur.size() && (a > *cur.begin()+x || a < *cur.rbegin()-x)) {
        ans++;
        cur.clear();
      }
      cur.insert(a);
    }
    cout << ans << endl;
  }
}