#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;

/*
  vector<int> a(n);
  iota(a.begin(), a.end(), 1);

  int ans = 0;
  do {
    vector<int> b(n);
    for(int i = 0; i < n; ++i) b[a[i] - 1] = i + 1;
    int val = 1;
    for(int i = 0; i < n; ++i) if(abs(a[i] - b[i]) > 1) { val = 0; break; }
    if(val == 1) {
      ++ans;
      //for(int i = 0; i < n; ++i) cout << a[i] << ' ';
      vector<int> c(n);
      int special = 0;
      for(int i = 0, j = 0; i < n; ++i) if(!c[i]) {
        ++j;
        int cnt = 0;
        for(int k = i; ; ) {
          c[k] = j;
          k = a[k] - 1;
          ++cnt;
          if(k == i) break;
        }
        if(cnt >= 4) {
          special = max(special, cnt);
        }
      }
      if(special) {
        for(int i = 0; i < n; ++i) cout << a[i] << ' ';
        cout << " / ";
        for(int i = 0; i < n; ++i) cout << c[i] << ' ';
        cout << ">>> " << special << '\n';
      }
    }
  } while(next_permutation(a.begin(), a.end()));
  cout << ans << '\n';

*/
  using ll = long long;
  const ll M = 998244353;
  vector<ll> d(n + 1), e(n + 1), fac(n + 1), ifac(n + 1);
  d[0] = d[1] = 1;
  if(n >= 2) d[2] = 2;
  for(int i = 3; i <= n; ++i) d[i] = (d[i - 1] + (i - 1) * d[i - 2]) % M;
  e[0] = 1;
  for(int i = 1; i <= n; ++i) e[i] = e[i - 1] * (2 * i - 1) % M;
  fac[0] = ifac[0] = 1;
  for(int i = 1; i <= n; ++i) {
    fac[i] = fac[i - 1] * i % M;
    ifac[i] = 1;
    for(ll x = fac[i], k = M - 2; k; k /= 2, x = x * x % M)
      if(k & 1) ifac[i] = ifac[i] * x % M; 
  }
  const auto choose = [&](int n, int k) {
    return fac[n] * ifac[k] % M * ifac[n - k] % M;
  };

  ll ans = 0;
  for(int i = 0, two = 1; n - 4 * i >= 0; ++i) {
    ans += two * d[n - 4 * i] % M * choose(n - 2 * i, 2 * i) % M * e[i] % M;
    two = 2 * two % M;
  }
  ans %= M;
  cout << ans << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;

  while(t--) {
    solve();
  }

  return 0;
}