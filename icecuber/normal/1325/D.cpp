#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll u, v;
  cin >> u >> v;
  ll d = v-u;
  if (u == 0 && v == 0) {
    cout << 0 << endl;
  } else if (d < 0 || d%2) {
    cout << -1 << endl;
  } else if (d == 0) {
    cout << 1 << endl << u << endl;
  } else if ((d/2&u) == 0) {
    cout << 2 << endl;
    ll a = (d/2) & ~u, b = d/2 ^ u;
    cout << a << ' ' << b << endl;
  } else {
    cout << 3 << endl;
    cout << u << ' ' << d/2 << ' ' << d/2  << endl;
  }
}