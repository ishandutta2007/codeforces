#include <bits/stdc++.h>
#define perr(a...) fprintf(stderr, a)
#define dbg(a...) perr("\033[32;1m"), perr(a), perr("\033[0m")
template <class T, class U>
inline bool smin(T &x, const U &y) {
  return y < x ? x = y, 1 : 0;
}
template <class T, class U>
inline bool smax(T &x, const U &y) {
  return x < y ? x = y, 1 : 0;
}

using LL = long long;
using PII = std::pair<int, int>;

constexpr int N(1e5 + 5);
struct Node {
  Node *ls, *rs;
  LL sum[2];
} *null = new Node;
struct Data {
  int s, m, r;
} a[N];
void ins(Node *&o, int l, int r, int x, int y) {
  o = new Node(*o);
  o->sum[0] += a[y].m, o->sum[1] += a[y].r;
  if (l == r) return;
  int m = l + r >> 1;
  x <= m ? ins(o->ls, l, m, x, y) : ins(o->rs, m + 1, r, x, y);
}
LL ask(Node *p, Node *q, int l, int r, int x, int y, int z) {
  if (x > r || y < l) return 0;
  if (x <= l && r <= y) return q->sum[z] - p->sum[z];
  int m = l + r >> 1;
  return ask(p->ls, q->ls, l, m, x, y, z) + ask(p->rs, q->rs, m + 1, r, x, y, z);
}

Node *root[N];

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  *null = {null, null, {0, 0}};
  int n;
  std::cin >> n;
  root[0] = null;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].s >> a[i].m >> a[i].r;
    root[i] = root[i - 1];
    if (a[i].r) ins(root[i], 0, 1e5, a[i].m / a[i].r, i);
  }
  std::set<std::array<int, 3>> s;
  for (int i = 1; i <= n; i++) s.insert({i, i, 0});
  int q;
  std::cin >> q;
  while (q--) {
    int t, l, r;
    std::cin >> t >> l >> r;
    auto pl = s.lower_bound({l, 0, 0}), pr = --s.lower_bound({r + 1, 0, 0});
    if (pl == s.end() || pl->at(0) != l) pl--;
    auto u = *pl;
    if (u[0] < l) {
      u[1] = l - 1;
      s.insert(u);
    }
    u = *pr;
    if (u[1] > r) {
      u[0] = r + 1;
      s.insert(u);
    }
    LL ans = 0;
    for (auto u = pl; u != s.end() && u->at(0) <= r; s.erase(u++)) {
      auto [x, y, s] = *u;
      smax(x, l), smin(y, r);
      if (!s) {
        for (int i = x; i <= y; i++) ans += std::min<LL>(a[i].m, 1LL * t * a[i].r + a[i].s);
      } else {
        ans += ask(root[x - 1], root[y], 0, 1e5, 0, t - s - 1, 0) + ask(root[x - 1], root[y], 0, 1e5, t - s, 1e5, 1) * (t - s);
      }
    }
    s.insert({l, r, t});
    std::cout << ans << "\n";
    // for (auto [l, r, t] : s) dbg("%d %d %d\n", l, r, t);
    // dbg("!!! %lld\n", ans);
  }  
  return 0;
}