#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define x first
#define y second

ll mod = 1e9+7;
ll fac[200000], ifac[200000];

ll bin(int x, int y) {
  if (x < 0 || y < 0) return 0;
  return fac[x+y]*ifac[x]%mod*ifac[y]%mod;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int w, h, n;
  cin >> w >> h >> n;
  fac[0] = fac[1] = ifac[0] = ifac[1] = 1;
  for (int i = 2; i < w+h; i++) {
    fac[i] = fac[i-1]*i%mod;
    int a = mod/i, b = mod%i, ib = ifac[b]*fac[b-1]%mod;
    ifac[i] = mod-ifac[i-1]*a %mod * ib %mod;
    assert(fac[i]*ifac[i]%mod == 1);
  }
  vector<pair<int,int>> p(n);
  for (auto&v : p) cin >> v.x >> v.y;
  p.emplace_back(w,h);
  sort(p.begin(), p.end());
  for (auto&v : p) v.x--, v.y--;

  vector<ll> dp;
  for (int i = 0; i <= n; i++) {
    ll ways = bin(p[i].x,p[i].y);
    for (int j = 0; j < i; j++)
      (ways -= dp[j]*bin(p[i].x-p[j].x,p[i].y-p[j].y)) %= mod;
    dp.push_back(ways);
  }
  cout << (dp[n]+mod)%mod << endl;
}