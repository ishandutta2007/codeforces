#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n;
  cin >> n;
  ll m = 9*8*7*5;
  int full = 0;
  for (int i = 0; i < m; i++) {
    int ok = 1;
    for (int j = 2; j <= 10; j++)
      if (i%j == 0) ok = 0;
    full += ok;
  }
  ll ans = full*(n/m);
  n %= m;
  for (int i = 0; i <= n; i++) {
    int ok = 1;
    for (int j = 2; j <= 10; j++)
      if (i%j == 0) ok = 0;
    ans += ok;
  }
  cout << ans << endl;
}