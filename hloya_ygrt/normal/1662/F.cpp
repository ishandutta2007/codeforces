#include <bits/stdc++.h>

using namespace std;


template <typename T>
struct seg_tree {
  seg_tree(int n): n(n), tr(n * 4 + 2) {

  }

  void upd(int v) {
    if (cmp(tr[v * 2 + 1], tr[v * 2 + 2])) {
      tr[v] = tr[v * 2 + 1];
    } else {
      tr[v] = tr[v * 2 + 2];
    }
  }

  void init(int v, int l, int r, const vector<int>& a) {
    if (l == r) {
      tr[v] = a[l];
      return;
    }
    int mid = (l + r) / 2;
    init(v * 2 + 1, l, mid, a);
    init(v * 2 + 2, mid + 1, r, a);
    upd(v);
  }

  void init(const vector<int>& a) {
    init(0, 0, n - 1, a);
  }

  void upd(int v, int l, int r, int i, int x) {
    if (l == r) {
      tr[v] = x;
      return;
    }
    int mid = (l + r) / 2;
    if (i <= mid) {
      upd(v * 2 + 1, l, mid, i, x);
    } else {
      upd(v * 2 + 2, mid + 1, r, i, x);
    }
    upd(v);
  }

  void upd(int i, int x) {
    upd(0, 0, n - 1, i, x);
  }

  template<typename Foo>
  void dosmth(int v, int l, int r, int ll, int rr, int x, Foo& foo) {
    int mid = (l + r) / 2;
    if (ll <= l && r <= rr) {
      if (!cmp( tr[v], x)) {
        return;
      }
      if (l == r) {
        foo(l);
        return;
      }
      dosmth(v * 2 + 1, l, mid, ll, rr, x, foo);
      dosmth(v * 2 + 2, mid + 1, r, ll, r, x, foo);
    }
    if (ll <= mid) {
      dosmth(v * 2 + 1, l, mid, ll, rr, x, foo);
    }
    if (rr > mid) {
      dosmth(v * 2 + 2, mid + 1, r, ll, rr, x, foo);
    }
  }

  T cmp;
  int n;
  vector<int> tr;
};

void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  a--;
  b--;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  vector<int> prv(n), nxt(n);
  for (int i = 0; i < n; i++) {
    prv[i] = i - p[i];
    nxt[i] = i + p[i];
  }
  seg_tree<std::greater_equal<int>> seg_nxt(n);
  seg_tree<std::less_equal<int>> seg_prv(n);
  seg_nxt.init(nxt);
  seg_prv.init(prv);
  queue<int> q;

  int depth = -1;
  vector<int> dst(n, -1);
  auto add = [&] (int i) {
    q.push(i);
    dst[i] = depth + 1;
    seg_nxt.upd(i, -1);
    seg_prv.upd(i, n);
  };
  add(a);
  while (!q.empty()) {
    auto v = q.front();
    q.pop();
    depth = dst[v];
    seg_nxt.dosmth(0, 0, n - 1, max(0, v - p[v]), v, v, add);
    seg_prv.dosmth(0, 0, n - 1, v, min(n - 1, v + p[v]), v, add);
  }
  cout << dst[b] << "\n";
}

int main() {
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
#endif
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  for (; t >= 1; t--) {
    solve();
  }
  return 0;
}