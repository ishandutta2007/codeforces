// Author:  HolyK
// Created: Fri Jun  4 23:26:15 2021
#include <bits/stdc++.h>
#define dbg(a...) fprintf(stderr, a)
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

#define ls ch[0]
#define rs ch[1]
struct Node {
  Node *ch[2], *fa;
  // bool rev;
  bool tag;
  LL siz, sum;
  int a, c;
  Node() : tag(false), siz(0), sum(0), a(0), c(0) {
    ch[0] = ch[1] = fa = nullptr;
  }
  bool nrt() const { return fa && (fa->ch[0] == this || fa->ch[1] == this); }
  bool dir() { return this == fa->ch[1]; }
  void sch(int d, Node *c) {
    ch[d] = c;
    if (c) c->fa = this;
  }
  void rotate() {
    Node *p = fa;
    bool d = dir();
    fa = p->fa;
    if (p->nrt()) fa->ch[p->dir()] = this;
    p->sch(d, ch[!d]), sch(!d, p), p->pushup();
  }
  void update() {
    if (nrt()) fa->update();
    pushdown();
  }
  void splay() {
    for (update(); nrt(); rotate()) {
      if (fa->nrt()) {
	(fa->dir() == dir() ? fa : this)->rotate();
      }
    }
    pushup();
  }
  void access() {
    for (splay(), ch[1] = nullptr; fa; rotate()) {
      fa->splay();
      fa->ch[1] = this;
      fa->pushup();
    }
    pushup();
  }
  // void reverse() {
  //   std::swap(ch[0], ch[1]);
  //   rev ^= 1;
  // }
  // void evert() {
  //   access(), reverse(), pushdown();
  // }
  void pushup() {
    siz = a + (ch[0] ? ch[0]->siz : 0) + (ch[1] ? ch[1]->siz : 0);
    sum = 1LL * a * c + (ch[0] ? ch[0]->sum : 0) + (ch[1] ? ch[1]->sum : 0);
  }
  void clear() {
    siz = sum = 0;
    a = 0;
    tag = true;
  }
  void pushdown() {
    // if (rev) {
    //   if (ch[0]) ch[0]->reverse();
    //   if (ch[1]) ch[1]->reverse();
    //   rev = false;
    // }
    if (tag) {
      if (ch[0]) ch[0]->clear();
      if (ch[1]) ch[1]->clear();
      tag = false;
    }
  }
} t[100005];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int q, a, c;
  std::cin >> q >> a >> c;
  std::vector<Node*> root(q + 1, nullptr);
  root[0] = new Node;
  root[0]->a = a, root[0]->c = c;
  root[0]->pushup();
  for (int i = 1; i <= q; i++) {
    int opt;
    std::cin >> opt;
    if (opt == 1) {
      int p;
      std::cin >> p >> a >> c;
      root[i] = new Node;
      root[i]->a = a, root[i]->c = c;
      root[i]->fa = root[p];
      root[i]->pushup();
    } else {
      int x, y;
      std::cin >> x >> y;
      Node *o = root[x], *p;
      if (!o) {
	std::cout << "0 0" << std::endl;
	continue;
      }
      LL a = 0, c = 0;
      o->access();
      while (o && y > 0) {
	p = o;
	if (o->ls && o->ls->siz + a > y) {
	  o = o->ls;
	} else {
	  if (o->ls) {
	    a += o->ls->siz;
	    c += o->ls->sum;
	    o->ls->clear();
	  }
	  int t = std::min<LL>(y - a, o->a);
	  o->a -= t;
	  a += t;
	  c += 1LL * t * o->c;
	  o = o->rs;
	}
      }
      o = p;
      while (o) o->pushup(), o = o->fa;
      p->splay();
      std::cout << a << " " << c << std::endl;
    }
  }
  return 0;
}
/*
5 5 2
2 0 2
1 0 3 4
2 2 4
1 0 1 3
2 4 2

 */