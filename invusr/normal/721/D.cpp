#include <bits/stdc++.h>
using namespace std;

typedef long long s64;

const int md = 998244353;

struct segtree {
  vector<s64> a, tree;
  int n;
  int negative;

  segtree(int n): n(n) {
    a.resize(n);
    tree.resize(n * 2 - 1);
  }

  void pull(int x, int z) {
    tree[x] = min(tree[x + 1], tree[z]);
  }

  void build(int x, int l, int r) {
    if (l == r) {
      tree[x] = a[l] < 0 ? -a[l] : a[l];
      negative += a[l] < 0;
    } else {
      int y = l + r >> 1, z = x + (y - l + 1 << 1);
      build(x + 1, l, y);
      build(z, y + 1, r);
      pull(x, z);
    }
  }

  void modify(int x, int l, int r, int v) {
    if (l == r) {
      int backup = negative;
      negative -= a[l] < 0;
      if ((backup & 1) == (a[l] < 0)) {
        a[l] -= v;
      } else {
        a[l] += v;
      }
      tree[x] = a[l] < 0 ? -a[l] : a[l];
      negative += a[l] < 0;
    } else {
      int y = l + r >> 1, z = x + (y - l + 1 << 1);
      if (tree[x + 1] < tree[z]) {
        modify(x + 1, l, y, v);
      } else {
        modify(z, y + 1, r, v);
      }
      pull(x, z);
    }
  }

  int query(int x, int l, int r) const {
    if (l == r) {
      return (a[l] % md + md) % md;
    } else {
      int y = l + r >> 1, z = x + (y - l + 1 << 1);
      int ans = 1;
      ans = (s64)ans * query(x + 1, l, y) % md;
      ans = (s64)ans * query(z, y + 1, r) % md;
      return ans;
    }
  }

  void print(int x, int l, int r) const {
    if (l == r) {
      cout << a[l] << ' ';
    } else {
      int y = l + r >> 1, z = x + (y - l + 1 << 1);
      print(x + 1, l, y);
      print(z, y + 1, r);
    }
  }

  void build() {
    build(0, 0, n - 1);
  }

  void modify(int v) {
    modify(0, 0, n - 1, v);
  }

  int query() const {
    return query(0, 0, n - 1);
  }

  void print() const {
    print(0, 0, n - 1);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k, v;
  cin >> n >> k >> v;
  segtree seg(n);
  for (int i = 0; i < n; ++i) {
    cin >> seg.a[i];
  }
  seg.build();
  while (k--) {
    seg.modify(v);
  }
//  cout << seg.query() << '\n';
  seg.print();

  return 0;
}