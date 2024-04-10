#include <bits/stdc++.h>
#define dbg(args...) std::cerr << "\033[31;1m" << #args << " -> ", err(args)
inline void err() { std::cerr << "\033[0m\n"; }
template<class T, class... U>
inline void err(const T &x, const U &... a) { std::cerr << x << ' '; err(a...); }

constexpr int N(3e5 + 5), INF(1e9 + 1);

struct Node {
  Node *ls, *rs;
  int siz, rnd, val, tag;
  inline void pushup() { siz = ls->siz + rs->siz + 1; }
  inline void add(int);
  inline void pushdown() { if (tag) ls->add(tag), rs->add(tag), tag = 0; }
} t[N], *null = new Node();
void Node::add(int x) { if (this != null) tag += x, val += x; }
void split_v(Node *o, int v, Node *&x, Node *&y) {
  if (o == null) {
    x = y = null; return;
  }
  o->pushdown();
  if (v < o->val)
    y = o, split_v(o->ls, v, x, o->ls);
  else
    x = o, split_v(o->rs, v, o->rs, y);
  o->pushup();
}
void split_k(Node *o, int k, Node *&x, Node *&y) {
  if (o == null) {
    x = y = null; return;
  }
  o->pushdown();
  if (k <= o->ls->siz)
    y = o, split_k(o->ls, k, x, o->ls);
  else
    x = o, split_k(o->rs, k - o->ls->siz - 1, o->rs, y);
  o->pushup();
}
Node* merge(Node *x, Node *y) {
  if (x == null) return y;
  if (y == null) return x;
  x->pushdown(), y->pushdown();
  return x->rnd < y->rnd
    ? (x->rs = merge(x->rs, y), x->pushup(), x)
    : (y->ls = merge(x, y->ls), y->pushup(), y);
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; std::cin >> n;
  null->ls = null->rs = null, null->siz = 0, null->val = INF;
  Node *root = null;
  for (int i = 0; i <= n; i++) {
    static std::mt19937 gen(std::chrono::high_resolution_clock().now().time_since_epoch().count());
    t[i].ls = t[i].rs = null;
    t[i].siz = 1, t[i].rnd = gen();
    t[i].val = i ? INF : 0;
    root = merge(root, t + i);
  }
  while (n--) {
    int l, r; std::cin >> l >> r;
    if (l > r) continue;
    Node *a, *b, *c, *d, *o;
    split_v(root, l - 1, a, b);
    split_v(b, r - 1, b, d);
    if (b == null) {
      for (o = d; o->ls != null; o = o->ls) o->pushdown();
      o->val = l;
      root = merge(a, d);
    } else {
      split_k(b, b->siz - 1, b, c);
      for (o = d; o->ls != null; o = o->ls) o->pushdown();
      o->val = std::min(o->val, c->val + 1);
      for (o = b; o->ls != null; o = o->ls) o->pushdown();
      c->val = std::min(l, o->val);
      b->add(1);
      root = merge(merge(a, c), merge(b, d));
    }
  }
  Node *a, *b;
  split_v(root, INF - 1, a, b);
  std::cout << a->siz - 1 << "\n";
  return 0;
}