#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = 998244353;

const int N = 100005;
ll fac[N], ifac[N], two[N];

ll inv(ll x) {
  ll r = 1;
  for(ll k = mod - 2; k; k /= 2, x = x * x % mod)
    if(k & 1) r = r * x % mod;
  return r;
}

void preproc() {
  fac[0] = 1;
  for(int i = 1; i < N; ++i) fac[i] = fac[i - 1] * i % mod;
  ifac[N - 1] = inv(fac[N - 1]);
  for(int i = N - 2; i >= 0; --i) ifac[i] = ifac[i + 1] * (i + 1) % mod;
  two[0] = 1;
  for(int i = 1; i < N; ++i) two[i] = two[i - 1] * 2 % mod;
}

ll bino(int n, int r) {
  return fac[n] * ifac[r] % mod * ifac[n - r] % mod;
}

void solve() {
  int n;
  cin >> n;

  vector<ll> a(n);
  for(int i = 0; i < n; ++i) cin >> a[i];

  if(*max_element(a.begin(), a.end()) == 0) {
    cout << two[n - 1] << '\n';
    return;
  }

  vector<ll> b = {0};
  for(int i = 0; i < n; ++i) {
    if(a[i]) {
      if(b.size() % 2) b.push_back(1);
      b.push_back(a[i]);
    }
    else {
      int j = i;
      while(j < n && !a[j]) ++j;
      b.push_back(j - i + 1);
      i = j - 1;
    }
  }
  if(b.size() % 2) b.push_back(1);
  b.push_back(0);
  --b[1];
  --b[int(b.size() - 2)];

/*
  for(auto x : b) cout << x << ' ';
  cout << '\n';
*/

  ll ans = 1, LS = 0, RS = 0;
  for(int i = 0, j = int(b.size()) - 1; i < j; ) {
    if(LS == RS) {
      if(i + 2 == j) ans = ans * two[b[i + 1]] % mod;
      else {
        ll cur = 0;
        for(int t = 0; t <= min(b[i + 1], b[j - 1]); ++t) {
          cur += bino(b[i + 1], t) * bino(b[j - 1], t) % mod;
          cur %= mod;
        }
        ans = ans * cur % mod;
      }
      i += 2; LS += b[i];
      j -= 2; RS += b[j];
    }
    else if(LS < RS) { i += 2; LS += b[i]; }
    else { j -= 2; RS += b[j]; }
    //cout << i << ' ' << j << ' ' << LS << ' ' << RS << " / " << ans << '\n';
  }
  cout << ans << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  preproc();

  int t;
  cin >> t;
  while(t--) { solve(); }

  return 0;
}