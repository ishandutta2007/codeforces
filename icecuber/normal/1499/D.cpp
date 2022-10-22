#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 2e7+10;
int primes[nax];

int main() {
  for (int i = 2; i < nax; i++) {
    if (primes[i] == 0) {
      for (int j = i; j < nax; j += i)
        primes[j]++;
    }
  }
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  map<int,ll> mem;
  while (t--) {
    int c, d, x;
    cin >> c >> d >> x;
    vector<int> div;
    for (int g = 1; g*g <= x; g++) {
      if (x%g == 0) {
        div.push_back(g);
        if (g*g < x) div.push_back(x/g);
      }
    }
    ll ans = 0;
    for (int g : div) {
      int v = x/g+d;
      if (v%c) continue;
      v /= c;
      ans += 1ll<<primes[v];
    }
    cout << ans << endl;
  }
}