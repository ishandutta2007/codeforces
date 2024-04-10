#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

using vint = vector<int>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpii = vector<pii>;
using vpil = vector<pil>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define x first
#define y second
#define all(v) v.begin(),v.end()

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<vint> e(n + 1);
  for(int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    e[x].push_back(y);
    e[y].push_back(x);
  }

  vint sz(n + 1, 0);
  function<int(int, int)> sf = [&](int x, int y) {
    for(int i : e[x]) if(i != y) sz[x] += sf(i, x);
    return ++sz[x];
  };
  function<int(int, int, int)> cf = [&](int x, int y, int t) {
    for(int i : e[x]) if(i != y && sz[i] > t / 2) return cf(i, x, t);
    return x;
  };
  int cen = cf(1, 0, sf(1, 0));

  int pc = 0;
  vint p(n + 1), h(n + 1), v;
  function<void(int, int, int)> f = [&](int x, int y, int z) {
    p[x] = ++pc;
    v.push_back(x);
    h[x] = z;
    for(int i : e[x]) if(i != y) f(i, x, z + 1); 
  };
  f(cen, 0, 0);

  ll ans = 0;
  vint av(n + 1);
  for(int i = n & 1; i < (n + 1) / 2; i++) {
    ans += 2 * (h[v[i]] + h[v[i + n / 2]]);
    av[v[i]] = v[i + n / 2];
    av[v[i + n / 2]] = v[i];
  }
  if(n & 1) {
    av[v[0]] = v[1];
    av[v[1 + n / 2]] = v[0];
  }

  cout << ans << '\n';
  for(int i = 1; i <= n; i++) cout << av[i] << " \n"[i == n];
  return 0;
}