#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  ll last, g = 0, first;
  cin >> first;
  last = first;
  for (int i = 1; i < n; i++) {
    ll x;
    cin >> x;
    g = __gcd(g,x-last);
    last = x;
  }
  for (int i = 0; i < m; i++) {
    ll p;
    cin >> p;
    if (g%p == 0) {
      cout << "YES" << endl;
      cout << first << ' ' << i+1 << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}