#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 998244353;
ll inv(ll a) {
  ll r = 1;
  for (ll p = mod-2; p; p >>= 1) {
    if (p&1) r = r*a%mod;
    a = a*a%mod;
  }
  return r;
}

ll a[1000][1000];
int id[1000][1000];
const int nax = 1e6;
ll dp[nax];
ll x2y2[nax], sum_x[nax], sum_y[nax];
int x[nax], y[nax];

void self_add(ll&a, ll b) {
  (a += b) %= mod;
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int h, w;
  cin >> h >> w;
  map<int,int> ma;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
      id[i][j] = ma[a[i][j]]++;
    }
  }
  int acc = 0;
  for (auto&p : ma) {
    int cp = p.second;
    p.second = acc;
    acc += cp;
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      id[i][j] += ma[a[i][j]];
      int k = id[i][j];
      x[k] = j;
      y[k] = i;
      x2y2[k] = i*i+j*j;
      sum_x[k] = j;
      sum_y[k] = i;
    }
  }
  for (int i = 1; i < w*h; i++) {
    self_add(x2y2[i], x2y2[i-1]);
    self_add(sum_x[i], sum_x[i-1]);
    self_add(sum_y[i], sum_y[i-1]);
  }
  for (int i = 1; i < w*h; i++) {
    int n = ma[a[y[i]][x[i]]];
    if (!n) continue;
    ll in = inv(n);
    dp[i] = ( x2y2[i]-x2y2[i-1] + (x2y2[n-1]+dp[n-1]-2*x[i]*sum_x[n-1]-2*y[i]*sum_y[n-1])%mod*in + dp[i-1] )%mod;
  }
  int y0, x0;
  cin >> y0 >> x0;
  y0--, x0--;
  int k = id[y0][x0];
  cout << (dp[k]-(k?dp[id[y0][x0]-1]:0)+mod*2)%mod << endl;
}