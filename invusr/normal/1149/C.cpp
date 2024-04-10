#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000000;

struct node {
  int a, b, c, d, e, f, ans;
  // a: suffix e+f; b: suffix e-f;
  // c: prefix e+f; d: prefix f-e;

  node(int v = 1) {
    a = c = ans = 1;
    if (v == 1) {
      e = 0;
      f = 1;
      b = -1;
      d = 1;
    } else {
      e = 1;
      f = 0;
      b = 1;
      d = -1;
    }
  }
};

node unite(const node &l, const node &r) {
  node res;
  res.ans = max(l.b + r.c, l.a + r.d);
  res.ans = max(res.ans, max(l.ans, r.ans));
  res.a = max(l.a - r.e + r.f, l.b + r.e + r.f);
  res.a = max(res.a, r.a);
  res.b = max(l.b + r.e - r.f, r.b);
  res.c = max(r.c - l.f + l.e, r.d + l.f + l.e);
  res.c = max(res.c, l.c);
  res.d = max(r.d + l.f - l.e, l.d);
  if (l.f > r.e) {
    res.e = l.e;
    res.f = r.f + l.f - r.e;
  } else {
    res.e = l.e + r.e - l.f;
    res.f = r.f;
  }
  return res;
}

// a+b = a1+b2+|a2-b1| = max{(a1-b1)+(a2+b2), (a1+b1)+(b2-a2)}
// a-b = a1-b1+a2-b2
// b-a = b2-a2+b1-a1

struct segtree {
  vector<node> tree;
  int n;

  segtree(int n): n(n) {
    tree.resize(n * 2 - 1);
  }

  void pull(int x, int z) {
    tree[x] = unite(tree[x + 1], tree[z]);
  }

  void build(int x, int l, int r, char *s) {
    if (l == r) {
      tree[x] = node(s[l] == '(' ? 1 : -1);
    } else {
      int y = l + r >> 1, z = x + (y - l + 1 << 1);
      build(x + 1, l, y, s);
      build(z, y + 1, r, s);
      pull(x, z);
    }
  }

  void modify(int x, int l, int r, int q, int v) {
    if (l == r) {
      tree[x] = node(v);
    } else {
      int y = l + r >> 1, z = x + (y - l + 1 << 1);
      if (q <= y) {
        modify(x + 1, l, y, q, v);
      } else {
        modify(z, y + 1, r, q, v);
      }
      pull(x, z);
    }
  }

  node query(int x, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) {
      return tree[x];
    } else {
      int y = l + r >> 1, z = x + (y - l + 1 << 1);
      if (rr <= y) {
        return query(x + 1, l, y, ll, rr);
      } else if (ll > y) {
        return query(z, y + 1, r, ll, rr);
      } else {
        return unite(query(x + 1, l, y, ll, rr), query(z, y + 1, r, ll, rr));
      }
    }
  }

  int query() {
    return tree[0].ans;
  }

  void build(char *s) {
    build(0, 0, n - 1, s);
  }

  void modify(int q, char v) {
    modify(0, 0, n - 1, q, v == '(' ? 1 : -1);
  }
};


  char s[233333];

int main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);

  int n, m;
  scanf("%d %d", &n, &m);
  scanf("%s", s);
  segtree seg((n - 1) * 2);
  seg.build(s);
  printf("%d\n", seg.query());
  while (m--) {
    int x, y;
    scanf("%d %d", &x, &y);
    --x;
    --y;
    seg.modify(x, s[y]);
    seg.modify(y, s[x]);
    swap(s[x], s[y]);
    printf("%d\n", seg.query());
  }

  return 0;
}