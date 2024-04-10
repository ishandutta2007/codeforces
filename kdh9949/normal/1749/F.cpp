#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 200005, K = 21;
struct Fen {
  ll d[N];
  void u(int x, ll v) { for(; x < N; x += x & -x) d[x] += v; }
  void u(int s, int e, ll v) { u(s, v); u(e + 1, -v); }
  ll g(int x) { ll r = 0; for(; x; x &= x - 1) r += d[x]; return r; }
} F[K];
ll V[K][N];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n;
  cin >> n;

  static vector<int> e[N];
  for(int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    e[x].push_back(y);
    e[y].push_back(x);
  }

  static int s[N];
  const function<int(int, int)> f = [&](int x, int y) {
    for(int i : e[x]) if(i != y) s[x] += f(i, x);
    return ++s[x];
  };
  f(1, 0);
  static int sp[K][N], dep[N], ord[N], up[N];
  const function<void(int, int, int)> g = [&](int x, int y, int z) {
    static int cnt = 0;
    dep[x] = dep[y] + 1;
    ord[x] = ++cnt;
    up[x] = z;
    sp[0][x] = y;
    for(int i = 1; i < K; ++i) sp[i][x] = sp[i - 1][sp[i - 1][x]];
    vector<int> v;
    for(int i : e[x]) if(i != y) v.push_back(i);
    sort(v.begin(), v.end(), [&](int x, int y){ return s[x] > s[y]; });
    for(int i : v) g(i, x, i == v[0] ? z : i);
  };
  g(1, 0, 1);

  auto lca = [&](int x, int y) -> int {
    if(dep[x] < dep[y]) swap(x, y);
    for(int i = K - 1; i >= 0; --i) if(dep[x] - (1 << i) >= dep[y]) x = sp[i][x];
    if(x == y) return x;
    for(int i = K - 1; i >= 0; --i) if(sp[i][x] != sp[i][y]) { x = sp[i][x]; y = sp[i][y]; }
    return sp[0][x];
  };

  auto upd = [&](int k, int x, int y, ll v) {
    while(dep[x] >= dep[y]) {
      int nx = (dep[up[x]] >= dep[y] ? up[x] : y);
      F[k].u(ord[nx], ord[x], v);
      x = sp[0][nx];
    }
  };

  int q;
  cin >> q;
  while(q--) {
    int t;
    cin >> t;
    if(t == 1) {
      int x;
      cin >> x;
      ll ans = 0;
      for(int i = 0; i < K; ++i) {
        for(int j = 0, y = x; j <= i && y; ++j, y = sp[0][y])
          ans += V[i][y] + F[i].g(ord[y]);
      }
      cout << ans << '\n';
    }
    else {
      int x, y; ll v; int d;
      cin >> x >> y >> v >> d;
      int z = lca(x, y);
      upd(d, x, z, v); upd(d, y, z, v); V[d][z] -= 2 * v;
      if(d) { upd(d - 1, x, z, -v); upd(d - 1, y, z, -v); V[d - 1][z] += 2 * v; }
      for(int i = d; i >= 0 && z; --i, z = sp[0][z]) {
        V[i][z] += v;
        if(i - 2 >= 0 && sp[0][z]) V[i - 2][z] -= v;
      }
    }
  }
  
  return 0;
}