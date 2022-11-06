// Author:  HolyK
// Created: Thu Apr 14 11:03:24 2022
#include <bits/stdc++.h>
bool DEBUG = false;

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

constexpr int P(1e9 + 7);
inline void inc(int &x, int y) {
  x += y;
  if (x >= P) x -= P;
}
inline void dec(int &x, int y) {
  x -= y;
  if (x < 0) x += P;
}
inline int sum(int x, int y) {
  return x + y >= P ? x + y - P : x + y;
}
inline int mod(LL x) { return x % P; }
int fpow(int x, int k = P - 2) {
  int r = 1;
  for (; k; k >>= 1, x = 1LL * x * x % P) {
    if (k & 1) r = 1LL * r * x % P;
  }
  return r;
}


struct SplayTree {
#define ls ch[0]
#define rs ch[1]
#define ms ch[2]
  using Node = SplayTree;
  Node *ch[3], *fa;
  
  SplayTree() : ch{0, 0, 0}, fa(0) {}

  bool nrt() const { return fa && (fa->ls == this || fa->rs == this); }
  int dir() const { return fa->rs == this; }
  void sch(int d, Node *x) {
    ch[d] = x;
    if (x) x->fa = this;
  }
  void rotate() {
    Node *p = fa;
    int k = dir();
    fa = p->fa;
    if (fa) fa->ch[fa->ms == p ? 2 : p->dir()] = this;
    p->sch(k, ch[!k]), sch(!k, p);
    p->pushup();
    pushup();
  }

  void splay() {
    for (; nrt(); rotate()) {
      if (fa->nrt()) {
        (dir() == fa->dir() ? fa : this)->rotate();
      }
    }
    pushup();
  }

  virtual void pushup() {
    
  }
  virtual ~SplayTree() {}
};

#define RT(x) static_cast<RakeTree *>(x)
#define CT(x) static_cast<CompressTree *>(x)

using RInfo = std::array<int, 2>;
struct Info {
  int a, b;
  Info(int c = 0) : a(1), b(c) {}
  Info(int a, int b) : a(a), b(b) {}
  Info(RInfo r) : a(sum(r[0], r[1])), b(r[1]) {}
  Info operator*(const Info &r) const {
    return Info(1LL * a * r.a % P, (1LL * a * r.b + 1LL * b * r.a) % P);
  }
};

RInfo cal(Info i, RInfo r) {
  return {
    mod(1LL * i.a * r[0]),
    mod(1LL * i.b * r[0] + 1LL * i.a * r[1])
  };
}
struct RakeTree : SplayTree {
  Info v;
  void pushup();
};

using CInfo = std::array<RInfo, 2>;
RInfo operator+(RInfo a, RInfo b) {
  return {sum(a[0], b[0]), sum(a[1], b[1])};
}
CInfo operator+(CInfo a, CInfo b) {
  return {a[0] + b[0], a[1] + b[1]};
}

RInfo rakeR(RInfo a, RInfo b) {
  return {mod(1LL * a[0] * b[0]), mod(1LL * a[0] * b[1] + 1LL * a[1] * b[0])};
}

CInfo rakeC(RInfo a, RInfo b) {
  return {RInfo{mod(1LL * b[0] * a[0]), mod(1LL * b[0] * a[1])},
          RInfo{mod(1LL * b[1] * a[0]), mod(1LL * b[1] * a[1])}};
}
CInfo rake(RInfo a, CInfo b) {
  return {RInfo{mod(1LL * (b[0][0] + b[0][1]) * a[0]),
                mod(1LL * b[0][0] * a[1] + 1LL * b[0][1] * (a[0] + a[1]))},
          RInfo{mod(1LL * (b[1][0] + b[1][1]) * a[0]),
                mod(1LL * b[1][0] * a[1] + 1LL * b[1][1] * (a[0] + a[1]))}};
}
CInfo compress(CInfo a, CInfo b) {
  return {
      RInfo{
        mod(1LL * b[0][0] * a[1][0] + 1LL * b[0][1] * (a[0][0] + a[1][0])),
        mod(1LL * b[0][0] * a[1][1] + 1LL * b[0][1] * (a[0][1] + a[1][1]))},
      RInfo{
        mod(1LL * b[1][0] * a[1][0] + 1LL * b[1][1] * (a[0][0] + a[1][0])),
        mod(1LL * b[1][0] * a[1][1] + 1LL * b[1][1] * (a[0][1] + a[1][1]))}};
}

constexpr CInfo CNull = {};
// constexpr CInfo CNull = {RInfo{0, 1}, RInfo{1, 0}};


struct CompressTree : SplayTree {
  void access() {
    splay();
    if (rs) {
      auto r = new RakeTree;
      r->sch(0, ms), r->sch(2, rs), r->pushup();
      rs = 0, sch(2, r), pushup();
    }
    for (; fa; rotate()) {
      fa->splay();
      auto m = fa, p = m->fa;
      p->splay();
      if (p->rs) {
        m->sch(2, p->rs);
        m->pushup();
      } else {
        if (!m->ls) {
          p->sch(2, m->rs);
        } else if (!m->rs) {
          p->sch(2, m->ls);
        } else {
          auto x = m->ls;
          x->fa = 0;
          while (x->rs) x = x->rs;
          x->splay();
          p->sch(2, x);
          x->sch(1, m->rs);
          x->pushup();
        }
        // delete m;
      }
      p->sch(1, this);
    }
    pushup();
  }

  int col;
  RInfo r;
  CInfo c;
  void pushup() {
    RInfo rl = ls ? CT(ls)->r : RInfo{1, 0};
    RInfo rm = cal(ms ? RT(ms)->v : Info(), RInfo{!col, col});
    RInfo rr = rs ? CT(rs)->r : RInfo{1, 0};
    r[0] = 1LL * rl[0] * rm[0] % P * rr[0] % P;
    r[1] = (1LL * rl[1] * rm[0] % P * rr[0] + 1LL * rl[0] * rm[1] % P * rr[0] + 1LL * rl[0] * rm[0] % P * rr[1]) % P;

    CInfo cr = rs ? rake(rm, CT(rs)->c) : CNull;
    // if (DEBUG) {
    //   std::cerr << "CR " << cr[0][0] << " " << cr[0][1] << "\n" << cr[1][0] << " " << cr[1][1] << "\n";
    // }
    if (rs) {
      cr = cr + rakeC(rm, rr), rm = rakeR(rm, rr);
    }
    if (ls) {
      auto &cl = CT(ls)->c;
      c = compress(cl, cr) + rake(rl, cr) + rakeC(rl, rm);
      c[0][0] = (c[0][0] + 1LL * rm[0] * (cl[0][0] + cl[1][0])) % P;
      c[0][1] = (c[0][1] + 1LL * rm[0] * (cl[0][1] + cl[1][1])) % P;
      c[1][0] = (c[1][0] + 1LL * rm[0] * cl[1][0] + 1LL * rm[1] * (cl[0][0] + cl[1][0])) % P;
      c[1][1] = (c[1][1] + 1LL * rm[0] * cl[1][1] + 1LL * rm[1] * (cl[0][1] + cl[1][1])) % P;
    } else {
      c = cr;
    }
  }
};

void RakeTree::pushup()  {
  v = (ls ? RT(ls)->v : Info()) * (rs ? RT(rs)->v : Info());
  if (ms) {
    v = v * (CT(ms)->r + CT(ms)->c[1]);
  }
}

CompressTree *link(CompressTree *x, CompressTree *y) {
  x->access();
  x->sch(1, y);
  y->pushup();
  x->pushup();
  return x;
}

constexpr int N(1e5 + 5);
CompressTree *node[N];

int fa[N];
void solve() {
  int n;
  std::cin >> n;
  for (int i = 2; i <= n; i++) std::cin >> fa[i], fa[i]++;

  for (int i = 1; i <= n; i++) {
    node[i] = new CompressTree;
    std::cin >> node[i]->col;
  }

  auto out = [&](int x) {
    std::cerr << "[OUT] " << x << "\n";
    // node[x]->pushup();
    if (node[x]->ls) std::cerr << "LS ";
    if (node[x]->rs) std::cerr << "RS ";
    std::cerr << "\n";
    for (int i : {0, 1}) {
      for (int j : {0, 1}) {
        std::cerr << node[x]->c[i][j] << " \n"[j];
      }
    }
    std::cerr << node[x]->r[0] << " " << node[x]->r[1] << "\n";
    return;
  };
  
  node[1]->pushup();
  for (int i = 2; i <= n; i++) {
    link(node[fa[i]], node[i]);
    // node[i]->access();
    // out(i);
  }
  // node[1]->splay();
  // out(1), out(2), out(3), out(5);
  // DEBUG = true;
  // node[3]->pushup();
  // DEBUG = false;
  // std::cerr << "RT\n";
  // std::cerr << RT(node[1]->ms)->v.a << " " << RT(node[1]->ms)->v.b << "\n";
  // DEBUG = true;
  // node[2]->pushup();
  // DEBUG = false;
  node[1]->access();
  std::cout << node[1]->r[1] << "\n";
  // int q;
  // std::cin >> q;
  // node[1] = new CompressTree;
  // std::cin >> node[1]->c;
  // int n = 1;
  // while (q--) {
  //   int opt, x, y;
  //   std::cin >> opt >> x >> y;
  //   if (opt == 1) {
  //     node[++n] = new CompressTree;
  //     node[n]->c = y;
  //     link(node[x], node[n]);
  //   } else {
  //     node[x]->access();
  //     node[x]->c = y;
  //     node[x]->pushup();
  //   }
  //   node[1]->splay();
  //   std::cout << node[1]->v.b << "\n";
  // }
}

int main() {
//   freopen("t.in", "r", stdin);
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int t = 1;
  
  // std::cin >> t;
  
  while (t--) {
    solve();
  }
  return 0;
}