#include <bits/stdc++.h>
#define dbg(...)                                           \
  std::cerr << "\033[32;1m", fprintf(stderr, __VA_ARGS__), \
      std::cerr << "\033[0m"
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

constexpr int N(5e5 + 5);

struct Info {
  int c, len, d[2][2], r[2];
  Info() : c(0), len(0) {
    d[0][0] = 0, d[0][1] = -1e9;
    d[1][0] = 0, d[1][1] = -1e9;
    r[0] = r[1] = -1e9;
  }
  void reverse() {
    std::swap(d[0][0], d[1][0]);
    std::swap(d[0][1], d[1][1]);
  }
  Info &compress(Info a, Info b) {
    c = a.c ^ b.c;
    len = a.len + b.len;
    d[0][0] = std::max(a.d[0][0], a.len + b.d[0][a.c]);
    d[0][1] = std::max(a.d[0][1], a.len + b.d[0][!a.c]);
    d[1][0] = std::max(b.d[1][0], b.len + a.d[1][b.c]);
    d[1][1] = std::max(b.d[1][1], b.len + a.d[1][!b.c]);
    r[0] = std::max(
        {a.r[0], b.r[0], a.d[1][0] + b.d[0][0], a.d[1][1] + b.d[0][1]});
    r[1] = std::max(
        {a.r[1], b.r[1], a.d[1][0] + b.d[0][1], a.d[1][1] + b.d[0][0]});
    return *this;
  }
  Info &rake(Info a, Info b) {
    c = b.c;
    len = b.len;
    d[0][0] = std::max(a.d[0][0], b.d[0][0]);
    d[0][1] = std::max(a.d[0][1], b.d[0][1]);
    d[1][0] = std::max(b.d[1][0], b.len + a.d[0][b.c]);
    d[1][1] = std::max(b.d[1][1], b.len + a.d[0][!b.c]);
    r[0] = std::max(
        {a.r[0], b.r[0], a.d[0][0] + b.d[0][0], a.d[0][1] + b.d[0][1]});
    r[1] = std::max(
        {a.r[1], b.r[1], a.d[0][0] + b.d[0][1], a.d[0][1] + b.d[0][0]});
    return *this;
  }
};


struct SplayTree {
  static SplayTree *null;
  SplayTree *ch[3], *fa;
  bool rev;
  Info info;
  SplayTree() : rev(false), info() {
    static bool init = true;
    if (init) {
      init = false;
      null = new SplayTree;
      null->ch[0] = null->ch[1] = null->ch[2] = null->fa = null;
    }
    ch[0] = ch[1] = ch[2] = fa = null;
  }
  bool notRoot() const { return fa->ch[0] == this || fa->ch[1] == this; }
  void reverse() {
    rev ^= 1;
    std::swap(ch[0], ch[1]);
    info.reverse();
  }
  bool dir() const { return fa->ch[1] == this; }
  void sch(int d, SplayTree *c) { ch[d] = c, c->fa = this; }
  void rotate() {
    SplayTree *p = fa;
    bool d = dir();
    fa = p->fa;
    if (fa != null) {
      fa->ch[fa->ch[2] == p ? 2 : p->dir()] = this;
    }
    p->sch(d, ch[!d]), sch(!d, p);
    p->pushup();
  }
  void splay() {
    static SplayTree *s[N], **t;
    t = s;
    for (auto x = this; x->notRoot(); x = x->fa) *++t = x->fa;
    while (t != s) (*t--)->pushdown();
    for (pushdown(); notRoot(); rotate()) {
      if (fa->notRoot()) {
        (fa->dir() == dir() ? fa : this)->rotate();
      }
    }
    pushup();
  }
  virtual void pushup() {}
  virtual void pushdown() {}
  virtual ~SplayTree() {}
};
SplayTree *SplayTree::null;

struct RakeTree : SplayTree {
  void pushup() {
    info.rake(ch[0]->info, Info().rake(ch[2]->info, ch[1]->info));
  }
};

struct CompressTree : SplayTree {
  void pushup() {
    info.compress(ch[0]->info, Info().rake(ch[2]->info, ch[1]->info));
    // dbg("vt pushup!\n");
  }
  void pushdown() {
    if (rev) {
      rev = false;
      ch[0]->reverse(), ch[1]->reverse();
    }
  }
  void access() {
    splay();
    if (ch[1] != null) {
      auto r = new RakeTree;
      r->sch(0, ch[2]), r->sch(2, ch[1]), r->pushup();
      ch[1] = null, sch(2, r), pushup();
    }
    for (; fa != null; rotate()) {
      fa->splay();
      SplayTree *m = fa, *p = m->fa;
      assert(p != null);
      p->splay();
      if (p->ch[1] != null) {
        m->sch(2, p->ch[1]);
        m->pushup();
      } else {
        if (m->ch[0] == null) {
          p->sch(2, m->ch[1]);
        } else if (m->ch[1] == null) {
          p->sch(2, m->ch[0]);
        } else {
          auto x = m->ch[0];
          x->fa = null;
          while (x->pushdown(), x->ch[1] != null) x = x->ch[1];
          x->splay();
          p->sch(2, x);
          x->sch(1, m->ch[1]);
          x->pushup();
        }
        delete m;
      }
      p->sch(1, this);
      p->pushup();
    }
    pushup();
  }
  void evert() { access(), reverse(), pushdown(); }
};
void link(CompressTree *x, CompressTree *y, int c) {
  x->access(), y->evert();
  auto e = new SplayTree;
  e->info.len = 1, e->info.c = c;
  x->sch(1, y), y->sch(0, e);
  y->pushup(), x->pushup();
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  std::cin >> n;
  CompressTree *t = new CompressTree[n + 1];
  assert(SplayTree::null);
  std::vector<int> u(n - 1), v(n - 1);
  for (int i = 0, c; i < n - 1; i++) {
    std::cin >> u[i] >> v[i] >> c;
    link(t + u[i], t + v[i], c);
  }
  std::cin >> m;
  while (m--) {
    int i;
    std::cin >> i;
    i--;
    t[u[i]].evert(), t[v[i]].access();
    t[u[i]].ch[1]->info.c ^= 1;
    t[u[i]].pushup();
    t[v[i]].pushup();
    std::cout << t[v[i]].info.r[0] << "\n";
  }
  return 0;
}