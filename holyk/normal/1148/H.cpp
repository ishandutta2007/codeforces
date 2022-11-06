#include <bits/stdc++.h>
#ifdef LOCAL
#define dbg(args...) std::cerr << "\033[32;1m" << #args << " -> ", err(args)
#else
#define dbg(...)
#endif
inline void err() { std::cerr << "\033[0m\n"; }
template<class T, class... U>
inline void err(const T &x, const U &... a) { std::cerr << x << ' '; err(a...); }
template <class T>
inline void readInt(T &w) {
  char c, p = 0;
  while (!isdigit(c = getchar())) p = c == '-';
  for (w = c & 15; isdigit(c = getchar());) w = w * 10 + (c & 15);
  if (p) w = -w;
}
template <class T, class... U>
inline void readInt(T &w, U &... a) { readInt(w), readInt(a...); }
template <class T, class U>
inline bool smin(T &x, const U &y) { return y < x ? x = y, 1 : 0; }
template <class T, class U>
inline bool smax(T &x, const U &y) { return x < y ? x = y, 1 : 0; }

typedef long long LL;
typedef std::pair<int, int> PII;

constexpr int N(2e5 + 5);
int n, pos[N];
namespace SegTree {
#define ls o << 1
#define rs o << 1 | 1
int min[N << 2];
void update(int o, int l, int r, int x, int y) {
  if (l == r) {
    min[o] = y; return;
  }
  int m = l + r >> 1;
  x <= m ? update(ls, l, m, x, y) : update(rs, m + 1, r, x, y);
  min[o] = std::min(min[ls], min[rs]);
}
int ask(int o, int l, int r, int x) {
  if (x < l) return n;
  if (r <= x) return min[o];
  int m = l + r >> 1;
  return std::min(ask(ls, l, m, x), ask(rs, m + 1, r, x));
}
#undef ls
#undef rs
}

struct Node {
  Node *ls, *rs;
  int v; LL vi;
  LL sumv, sumvi;
} t[N * 100], *null = t, *ptr = t + 1;

class PerSegTree {
 public:
  PerSegTree(): root() { root[0] = null; }
  void ins(int i, int l, int r, int v) {
    auto it = root.rbegin();
    assert(it->first <= i);
    ins(root[i] = it->second, 1, n, l, r, v, i);
  }
  LL ask(int l, int r) {
    coef = r + 1;
    return ask((--root.upper_bound(r))->second, 1, n, l, r);
  }
 private:
  std::map<int, Node*> root;
  void ins(Node *&o, int l, int r, int x, int y, int v, int i) {
    *ptr = *o, o = ptr++;
    o->sumv += 1LL * v * (y - x + 1);
    o->sumvi += 1LL * v * i * (y - x + 1);
    if (x == l && r == y) {
      o->v += v, o->vi += 1LL * v * i;
      return;
    }
    int m = l + r >> 1;
    if (y <= m)
      ins(o->ls, l, m, x, y, v, i);
    else if (x > m)
      ins(o->rs, m + 1, r, x, y, v, i);
    else
      ins(o->ls, l, m, x, m, v, i), ins(o->rs, m + 1, r, m + 1, y, v, i);
  }
  int coef;
  LL ask(Node *o, int l, int r, int x, int y) {
    if (x == l && r == y) return coef * o->sumv - o->sumvi;
    int m = l + r >> 1;
    LL ans = (1LL * coef * o->v - o->vi) * (y - x + 1);
    if (y <= m)
      ans += ask(o->ls, l, m, x, y);
    else if (x > m)
      ans += ask(o->rs, m + 1, r, x, y);
    else
      ans += ask(o->ls, l, m, x, m) + ask(o->rs, m + 1, r, m + 1, y);
    return ans;
  }
};

bool vis[N];
std::map<int, PII> s;
int main() {
  null->ls = null->rs = null;
  readInt(n);
  std::vector<PerSegTree> t(n + 1);
  LL ans = 0;
  for (int i = 1, mex = 0, x, l, r, k; i <= n; i++) {
    readInt(x, l, r, k);
    x = (x + ans) % (n + 1);
    l = (l + ans) % i + 1;
    r = (r + ans) % i + 1;
    k = (k + ans) % (n + 1);
    if (l > r) std::swap(l, r);
    dbg(x, l, r, k);
    for (vis[x] = 1; vis[mex]; mex++) ;
    SegTree::update(1, 1, n, i, x);
    if (pos[x]) SegTree::update(1, 1, n, pos[x], n);
    pos[x] = i;
    auto it = s.find(x);
    if (it != s.end()) {
      auto [p, q] = it->second;
      s.erase(it);
      t[x].ins(i, p, q, -1);
      while (p <= q) {
        int v = SegTree::ask(1, 1, n, q - 1), idx = smin(v, mex) ? 0 : pos[v];
        t[v].ins(i, std::max(p, idx + 1), q, 1);
        s[v] = PII(idx + 1, q);
        q = idx;
      }
    }
    auto &[p, q] = s[!x];
    p ? q = i : p = q = i;
    t[!x].ins(i, i, i, 1);
    ans = t[k].ask(l, r);
    printf("%lld\n", ans);
  }  
  return 0;
}