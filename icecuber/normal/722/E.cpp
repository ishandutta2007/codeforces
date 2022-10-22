#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define x first
#define y second

const int m = 21;
const ll mod = 1e9+7;

ll dp[2001][m];
ll fac[200000], ifac[200000], inv[200000];

ll bin(int x, int y) {
  if (x < 0 || y < 0) return 0;
  return fac[x+y]*ifac[x] %mod *ifac[y] %mod;
}

ll mypow(ll a, ll p = mod-2) {
  ll r = 1;
  while (p) {
    if (p&1) r = r*a%mod;
    a = a*a%mod;
    p >>= 1;
  }
  return r;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int w, h, n, s;
  cin >> w >> h >> n >> s;
  fac[0] = ifac[0] = 1;
  for (int i = 1; i < w+h; i++) {
    fac[i] = fac[i-1]*i%mod;
    inv[i] = i > 1 ? mod-mod/i*inv[mod%i]%mod : 1;
    ifac[i] = ifac[i-1]*inv[i]%mod;
    assert(fac[i]*ifac[i]%mod == 1);
  }

  vector<pair<int,int>> p(n);
  for (auto&v : p) cin >> v.x >> v.y;
  p.emplace_back(w,h);
  for (auto&v : p) v.x--, v.y--;
  sort(p.begin(), p.end());

  for (int i = 0; i <= n; i++) {
    for (int k = 0; k < m; k++) {
      dp[i][k] = bin(p[i].x, p[i].y);
      for (int j = 0; j < i; j++)
	(dp[i][k] -= dp[j][k]*bin(p[i].x-p[j].x,p[i].y-p[j].y)) %= mod;
    }
    for (int k = m-1; k; k--)
      (dp[i][k] -= dp[i][k-1]) %= mod;
  }
  ll ans = 0;
  ll sum = 0;
  for (int k = 0; k < m; k++) {
    (ans += dp[n][k]*s) %= mod;
    (sum += dp[n][k]) %= mod;
    s -= s/2;
  }
  assert(s == 1);
  (ans += bin(p[n].x,p[n].y)-sum) %= mod;
  (ans *= mypow(bin(p[n].x,p[n].y))) %= mod;
  cout << (ans+mod)%mod << endl;
}