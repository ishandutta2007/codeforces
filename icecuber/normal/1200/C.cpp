#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, m, q;
  cin >> n >> m >> q;
  ll g = __gcd(n,m);
  while (q--) {
    ll sx, sy, ex, ey;
    cin >> sy >> sx >> ey >> ex;
    sx--, sy--, ex--, ey--;
    ll si = sy ? sx/(m/g) : sx/(n/g);
    ll ei = ey ? ex/(m/g) : ex/(n/g);
    cout << (si == ei ? "YES" : "NO") << endl;
  }
}