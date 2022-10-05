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

  int n, m;
  cin >> n >> m;

  vector<vpii> e(2 * n + 1);
  for(int i = 1; i <= n; i++) {
    e[i].emplace_back(i + n, 2);
    e[i + n].emplace_back(i, 2);
  }
  for(int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    e[x].emplace_back(y, 1);
    e[y + n].emplace_back(x + n, 1);
  }

  vint td(2 * n + 1, int(1e9));
  {
    priority_queue<pii, vpii, greater<pii>> pq;
    td[1] = 0;
    pq.emplace(0, 1);
    while(!pq.empty()) {
      pii t = pq.top();
      pq.pop();
      if(t.x != td[t.y]) continue;
      for(pii &p : e[t.y]) {
        if(td[p.x] > t.x + (p.y == 2)) {
          td[p.x] = t.x + (p.y == 2);
          pq.emplace(td[p.x], p.x);
        }
      }
    }
  }

  struct Dijk {
    int td, ed, x;
    bool operator<(const Dijk &o) const {
      if(td > 25 || o.td > 25) return td < o.td;
      return (1 << td) - 1 + ed < (1 << o.td) - 1 + o.ed;
    }
    bool operator>(const Dijk &o) const {
      if(td > 25 || o.td > 25) return td > o.td;
      return (1 << td) - 1 + ed > (1 << o.td) - 1 + o.ed;
    }
  };
  vector<vint> d(2 * n + 1, vint(20, int(1e9)));
  {
    priority_queue<Dijk, vector<Dijk>, greater<Dijk>> pq;
    d[1][0] = 0;
    pq.push({0, 0, 1});
    while(!pq.empty()) {
      Dijk t = pq.top();
      pq.pop();
      if(d[t.x][t.td - td[t.x]] != t.ed) continue;
      for(pii &p : e[t.x]) {
        int ntd = t.td + (p.y == 2);
        int ned = t.ed + (p.y == 1);
        if(ntd >= td[p.x] + 20) continue;
        if(d[p.x][ntd - td[p.x]] > ned) {
          d[p.x][ntd - td[p.x]] = ned;
          pq.push({ntd, ned, p.x});
        }
      }
    }
  }

  Dijk ad = {int(1e9), 0, 0};
  for(int i = 0; i < 20; i++) {
    Dijk cd = {td[n] + i, d[n][i], 0};
    if(cd.ed <= n && cd < ad) ad = cd;
    cd = {td[2 * n] + i, d[2 * n][i], 0};
    if(cd.ed <= n && cd < ad) ad = cd;
  }
  const static int M = 998244353;
  int ans = 1;
  for(int i = 0; i < ad.td; i++) ans = ans * 2 % M;
  ans = (ans - 1 + ad.ed + M) % M;
  cout << ans << '\n';
  return 0;
}