#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

const int N = 300000 + 10, INF = 0x3f3f3f3f;

struct Node {
  Node *p, *ch[2];
  int key, tag;
  inline bool dir() const { return this == p->ch[1]; }
  inline void apply(int x) {
    key += x;
    tag += x;
  }
  void release() {
    if (tag) {
      if (ch[0]) ch[0]->apply(tag);
      if (ch[1]) ch[1]->apply(tag);
      tag = 0;
    }
  }
  void rotate();
  void splay(Node*);
} pool[N];

void Node::rotate() {
  Node *v = p;
  bool d = dir();
  v->release();
  release();
  if (v->p) v->p->ch[v->dir()] = this;
  p = v->p;
  if (ch[!d]) ch[!d]->p = v;
  v->ch[d] = ch[!d];
  ch[!d] = v;
  v->p = this;
}

void Node::splay(Node *t = nullptr) {
  release();
  while (p != t) {
    if (p->p != t) (dir() == p->dir() ? p : this)->rotate();
    rotate();
  }
}

Node *lower_bound(Node *p, int x) {
  Node *res = nullptr;
  p->splay();
  while (p) {
    p->release();
    if (p->key >= x) {
      res = p;
      p = p->ch[0];
    } else {
      p = p->ch[1];
    }
  }
  if (res) res->splay();
  return res;
}

Node *meld(Node *u, Node *v) {
  if (!u) return v;
  if (!v) return u;
  u->splay();
  while (u->ch[1]) u = u->ch[1];
  u->splay();
  u->release();
  u->ch[1] = v;
  v->p = u;
  v->splay();
  return v;
}

void solve(int l, int r) {
  Node *u = lower_bound(&pool[0], r);
  u->splay();
  u->release();
  Node *x = u->ch[0], *y = u->ch[1];
  x->p = u->ch[0] = nullptr;
  y->p = u->ch[1] = nullptr;
  u->key = l;
  Node *z = lower_bound(x, l);

  if (z) {
    z->splay();
    x = z->ch[0];
    while (x->ch[1]) x = x->ch[1];
    x->splay();
  } else {
    x->splay();
    while (x->ch[1]) x = x->ch[1];
    x->splay();
  }
  x->release();
  if (x->ch[1]) {
    x->ch[1]->apply(1);
    x->ch[1]->p = u;
    u->ch[1] = x->ch[1];
  }
  u->p = x;
  x->ch[1] = u;
  u->splay();
  meld(x, y);
}

int n;

int main() {
  scanf("%d", &n);
  for (int i = 0; i <= n; ++i) pool[i].ch[1] = &pool[i + 1], pool[i + 1].p = &pool[i];
  for (int i = 1; i <= n + 1; ++i) pool[i].key = INF;
  pool[n + 1].splay();
  for (int i = n; i--;) {
    int l, r;
    scanf("%d%d", &l, &r);
    solve(l, r);
  }
  std::vector<int> res;
  std::function<void(Node*)> dfs = [&] (Node *p) {
    if (!p) return;
    p->release();
    dfs(p->ch[0]);
    res.push_back(p->key);
    dfs(p->ch[1]);
  };
  Node *p = &pool[0];
  p->splay();
  dfs(p);
  for (int i = res.size() - 1; i >= 0; --i) {
    if (res[i] < INF) {
      printf("%d\n", i);
      break;
    }
  }
  return 0;
}