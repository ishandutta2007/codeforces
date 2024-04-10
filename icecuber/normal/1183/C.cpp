#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll k, n, a, b;
    cin >> k >> n >> a >> b;
    if (k <= n*b) cout << -1 << endl;
    else cout << min(n,(k-n*b-1)/(a-b)) << endl;
  }
}