#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1e9+7;
const int nax = 1e5;
int par[nax], sz[nax];
int find(int p) {
  return p == par[p] ? p : par[p] = find(par[p]);
}
void join(int a, int b) {
  a = find(a), b = find(b);
  if (a == b) return;
  if (sz[a] < sz[b]) swap(a,b);
  par[b] = a;
  sz[a] += sz[b];
}
ll bin_pow(ll a, ll p) {
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
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) par[i] = i, sz[i] = 1;
  map<int,int> px, py;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    if (!px.count(x)) px[x] = i;
    join(px[x], i);
    if (!py.count(y)) py[y] = i;
    join(py[y], i);
  }
  map<int,int> lx, ly;
  for (auto [x,i] : px) ++lx[find(i)];
  for (auto [y,i] : py) ++ly[find(i)];
  ll ans = 1;
  for (int i = 0; i < n; i++) {
    if (find(i) == i) {
      (ans *= bin_pow(2, lx[i]+ly[i])+mod-(lx[i]+ly[i] > sz[i])) %= mod;
    }
  }
  cout << ans << endl;
}