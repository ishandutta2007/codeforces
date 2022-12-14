#include <cmath>
#include <cstdio>
#include <algorithm>

const int N = 300000 + 10;
const double eps = 1e-7;

inline int sgn(double x) {
  if (fabsl(x) < eps) return 0;
  return x > 0.0 ? 1 : -1;
}

inline int fcmp(double a, double b) { return sgn(a - b); }

inline double sqr(double x) { return x * x; }

int n, q, a, b, x[N];

struct tag_t {
  double a, b, c;
  tag_t() {}
  tag_t(double _a, double _b, double _c): a(_a), b(_b), c(_c) {}
  inline void clear() { a = b = c = 0.0; }
  inline bool empty() { return sgn(a) == 0 && sgn(b) == 0 && sgn(c) == 0; }
};

class node_t {
 public:
  node_t *p, *ch[2];
  double l, r, a, b, c, det;
  tag_t tag;

  inline double f(double x) { return a * sqr(x) + b * x + c; }
  inline double deriv(double x) { return 2.0 * a * x + b; }
  inline double getmin() { return std::min<double>(std::min(r, std::max(l, -b / 2.0 / a)), q); }
  inline int dir();
  inline void setc(node_t*, int);
  inline void apply(const tag_t&);
  inline void shr(double);
  inline void release();
  inline void rotate();
  inline void splay();
  inline double findmin();
} pool[2 * N], *root, *tot = pool;

inline int node_t::dir() {
  if (!p) return -1;
  return this == p->ch[1];
}

inline void node_t::setc(node_t *c, int d) {
  if (this) ch[d] = c;
  if (c) c->p = this;
}

inline void node_t::apply(const tag_t &t) {
  tag.a += t.a;
  tag.b += t.b;
  tag.c += t.c;
  a += t.a;
  b += t.b;
  c += t.c;
}

inline void node_t::shr(double d) {
  det += d, l += d, r += d;
  c += a * d * d - b * d;
  b -= 2.0 * a * d;
  tag.c += tag.a * d * d - tag.b * d;
  tag.b -= 2.0 * tag.a * d;
}

inline void node_t::release() {
  if (det) {
    if (ch[0]) ch[0]->shr(det);
    if (ch[1]) ch[1]->shr(det);
    det = 0.0;
  }
  if (!tag.empty()) {
    if (ch[0]) ch[0]->apply(tag);
    if (ch[1]) ch[1]->apply(tag);
    tag.clear();
  }
}

inline void node_t::rotate() {
  if (p == root) root = this;
  node_t *v = p;
  v->release(), release();
  int d = dir();
  v->p->setc(this, v->dir());
  v->setc(ch[!d], d);
  setc(v, !d);
}

inline void node_t::splay() {
  release();
  while (this != root) {
    if (p != root)
      (dir() == p->dir()) ? (p->rotate(), rotate()) : (rotate(), rotate());
    else
      rotate();
  }
}

double node_t::findmin() {
  node_t *cur = this;
  while (cur->release(), fcmp(cur->l, q) > 0) cur = cur->ch[0];
  while (1) {
    cur->release();
    int a = sgn(cur->deriv(cur->l)), b = sgn(cur->deriv(cur->r));
    int d = b < 0;
    if ((a <= 0 && b >= 0) || !cur->ch[d] || fcmp(cur->ch[d]->l, q) >= 0) {
      cur->splay();
      return cur->getmin();
    }
    cur = cur->ch[d];
  }
}

int main() {
  scanf("%d%d%d%d", &n, &q, &a, &b);
  for (int i = 1; i <= n; ++i) scanf("%d", x + i);
  root = ++tot;
  root->l = 1, root->r = q;
  root->a = 1.0, root->b = -2.0 * x[1], root->c = sqr(x[1]);
  static double inf[N];
  for (int i = 2; i <= n; ++i) {
    inf[i - 1] = root->findmin(); 
    root->release();
    if (fcmp(root->l, inf[i - 1]) < 0) {
      node_t *u = ++tot;
      *u = *root;
      u->r = inf[i - 1];
      u->setc(root->ch[0], 0);
      u->setc(NULL, 1);
      root->setc(u, 0);
    }
    if (fcmp(inf[i - 1], root->r) < 0) {
      node_t *u = ++tot;
      *u = *root;
      u->l = inf[i - 1];
      u->setc(NULL, 0);
      u->setc(root->ch[1], 1);
      root->setc(u, 1);
    }
    root->c = root->f(inf[i - 1]);
    root->a = root->b = 0.0;
    root->l = inf[i - 1] + a, root->r = inf[i - 1] + b;
    if (root->ch[0]) root->ch[0]->shr(a);
    if (root->ch[1]) root->ch[1]->shr(b);
    root->apply(tag_t(1.0, -2.0 * x[i], sqr(x[i])));
  }
  static double y[N];
  y[n] = root->findmin();
  for (int i = n - 1; i > 0; --i) {
    if (fcmp(y[i + 1], inf[i] + b) > 0)
      y[i] = y[i + 1] - b;
    else if (fcmp(y[i + 1], inf[i] + a) < 0)
      y[i] = y[i + 1] - a;
    else
      y[i] = inf[i];
  }
  double ans = 0.0;
  for (int i = 1; i < n; ++i) printf("%.10f ", y[i]), ans += sqr(y[i] - x[i]);
  printf("%.10f\n%.10f\n", y[n], ans += sqr(y[n] - x[n]));
  return 0;
}