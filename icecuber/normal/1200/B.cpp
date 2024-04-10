#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll n, m, k;
    cin >> n >> m >> k;
    ll h;
    cin >> h;
    m += h;
    int ok = 1;
    for (int i = 1; i < n; i++) {
      cin >> h;
      ll new_m = m-max(0ll,h-k);
      if (new_m < 0) ok = 0;
      m = new_m+h;
    }
    cout << (ok ? "YES" : "NO") << endl;
  }
}