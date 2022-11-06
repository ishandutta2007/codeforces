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

constexpr int N(1e5 + 5), T(100);
struct SplayTree {
  using Node = SplayTree;
  Node *ch[2], *fa;
  int siz;
  SplayTree() : siz(1) {
    ch[0] = ch[1] = fa = nullptr;
  }
  bool nrt() { return fa && (fa->ch[0] == this || fa->ch[1] == this); }
  bool dir() { return this == fa->ch[1]; }
  void sch(int d, Node *c) {
    ch[d] = c;
    if (c) c->fa = this;
  }
  void rotate() {
    Node *p = fa;
    bool d = dir();
    fa = p->fa;
    if (p->nrt()) fa->ch[p->dir()] = this; //
    p->sch(d, ch[!d]), sch(!d, p), p->pushup();
  }
  void splay() {
    for (; nrt(); rotate()) {
      if (fa->nrt()) {
        (fa->dir() == dir() ? fa : this)->rotate();
      }
    }
    pushup();
  }
  void access() {
    for (splay(), ch[1] = nullptr; fa; rotate()) {
      fa->splay(), fa->ch[1] = this, fa->pushup();
    }
    pushup();
  }
  void pushup() {
    siz = 1 + (ch[0] ? ch[0]->siz : 0) + (ch[1] ? ch[1]->siz : 0);
  }
} t[N];
int lg[N];
struct STMin {
  int st[18][N];
  STMin(std::vector<int> a) {
    for (int i = 0; i < a.size(); i++) st[0][i] = a[i];
    for (int i = 1; i < 18; i++) {
      for (int j = (1 << i) - 1; j < a.size(); j++)
        st[i][j] = std::min(st[i - 1][j], st[i - 1][j - (1 << i - 1)]);
    }
      
  }
  int operator()(int l, int r) {
    int k = lg[r - l + 1];
    return std::min(st[k][r], st[k][l + (1 << k) - 1]);
  }
};
struct STMax {
  int st[18][N];
  STMax(std::vector<int> a) {
    for (int i = 0; i < a.size(); i++) st[0][i] = a[i];
    for (int i = 1; i < 18; i++) {
      for (int j = (1 << i) - 1; j < a.size(); j++)
        st[i][j] = std::max(st[i - 1][j], st[i - 1][j - (1 << i - 1)]);
    }
      
  }
  int operator()(int l, int r) {
    int k = lg[r - l + 1];
    return std::max(st[k][r], st[k][l + (1 << k) - 1]);
  }
};
void link(int x, int y) {
  SplayTree *a = t + x, *b = t + y;
  assert(!a->fa);
  a->fa = b;
}
void cut(int x, int y) {
  SplayTree *a = t + x, *b = t + y;
  a->access(), b->splay();
  assert(b->ch[1] == a && !a->ch[0] && !a->ch[1]);
  a->fa = b->ch[1] = nullptr;
  b->pushup();
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, w, m;
  std::cin >> n >> w >> m;
  for (int i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;
  std::vector<int> a(n);
  for (int &x : a) std::cin >> x;
  STMin min(a);
  STMax max(a);
  std::vector<int> to(n);
  std::priority_queue<PII> pq;
  for (int i = 0; i < n; i++) {
    link(i, to[i] = i + 1);
    if (i < n - 1) {
      pq.emplace(-std::abs(a[i + 1] - a[i]), i);
    }
  }
  std::vector<PII> q(m);
  for (int i = 0; i < m; i++) {
    std::cin >> q[i].first;
    q[i].first = w - q[i].first;
    q[i].second = i;
  }
  std::sort(q.begin(), q.end());
  std::vector<int> ans(m);
  for (auto [k, id] : q) {
    while (pq.size() && -pq.top().first <= k) {
      int s = -pq.top().first;
      int p = pq.top().second;
      pq.pop();
      int l = to[p], r = n;
      while (l < r) {
        int m = l + r >> 1;
        if (max(p, m) - min(p, m) > k) r = m;
        else l = m + 1;
      }
      cut(p, to[p]);
      to[p] = l;
      if (to[p] == n || to[p] - p > T) continue;
      pq.emplace(min(p, to[p]) - max(p, to[p]), p);
      link(p, to[p]);
    }
    int cnt = 0;
    for (int i = 0; i < n; ) {
      if (to[i] == n || to[i] - i > T) {
        int l = to[i], r = n;
        while (l < r) {
          int m = l + r >> 1;
          if (max(i, m) - min(i, m) > k) r = m;
          else l = m + 1;
        }
        i = to[i] = l;
        cnt++;
      } else {
        SplayTree *o = t + i, *p;
        o->access();
        assert(o->siz > 1);
        cnt += o->siz - 1;
        for (p = o; p->ch[0]; p = p->ch[0]) ;
        i = p - t;
        assert(i == n || to[i] == n || to[i] - i > T);
      }
    }
    ans[id] = cnt - 1;
  }
  for (int x : ans) std::cout << x << "\n";
  return 0;
}