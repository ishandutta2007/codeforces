#include <bits/stdc++.h>

using namespace std;

inline void md(vector<int>& f, int x, int y) {
  for (; x < f.size(); x = (x | (x + 1))) {
    f[x] = max(y, f[x]);
  }
}

inline int mx(const vector<int>& f, int x) {
  int mx = -228'228;
  for (; x >= 0; x = (x & (x + 1)) - 1) {
    mx = max(mx, f[x]);
  }
  return mx;
}


class MergeSortTree {
 public:
  MergeSortTree(const vector<pair<int64_t, int>>& a): n(a.size()), a(a), tr(n * 4 + 2), fn(n * 4 + 2) {
    init(0, 0, n - 1);
  }

  void upd(int64_t x, int y, int val) {
    upd(0, 0, n - 1, x, y, val);
  }

  int mx(int64_t x, int y) {
    int ans = -n;
    mx(0, 0, n - 1, x, y, ans);
    return ans;
  }

 private:
  void init(int v, int l, int r) {
    fn[v].resize(r - l + 1, -n);
    if (l == r) {
      tr[v].emplace_back(a[l].second);
      return;
    }
    int mid = (l + r) / 2;
    init(v * 2 + 1, l, mid);
    init(v * 2 + 2, mid + 1, r);
    tr[v].reserve(r - l + 1);
    merge(tr[v * 2 + 1].begin(), tr[v * 2 + 1].end(), tr[v * 2 + 2].begin(), tr[v * 2 + 2].end(), std::back_inserter(tr[v]));
  }

  void upd(int v, int l, int r, int64_t x, int y, int val) {
    int it = lower_bound(tr[v].begin(), tr[v].end(), y) - tr[v].begin();
    md(fn[v], it, val);
    if (l == r) {
      return;
    }
    int mid = (l + r) / 2;
    if (a[mid] >= make_pair(x, y)) {
      upd(v * 2 + 1, l, mid, x, y, val);
    } else {
      upd(v * 2 + 2, mid + 1, r, x, y, val);
    }
  }

  void mx(int v, int l, int r, int64_t x, int y, int& ans) {
    if (a[r].first <= x) {
      int it = upper_bound(tr[v].begin(), tr[v].end(), y) - tr[v].begin() - 1;
      if (it >= 0) {
        ans = max(ans, ::mx(fn[v], it));
      }
      return;
    }
    int mid = (l + r) / 2;
    mx(v * 2 + 1, l, mid, x, y, ans);
    if (a[mid + 1] <= make_pair(x, y)) {
      mx(v * 2 + 2, mid + 1, r, x, y, ans);
    }
  }

  int n;
  const vector<pair<int64_t, int>>& a;
  vector<vector<int>> tr;
  vector<vector<int>> fn;
};

void solve() {
  int n = 200'000, v = 1;
  cin >> n >> v;
  vector<int> t(n + 1);
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  //  a[i] = rand() % n;
  }
  n++;
  a[0] = 0;
  t[0] = 0;

  std::vector<pair<int64_t, int>> b(n);
  std::vector<pair<int64_t, int>> c(n);
  for (int i = 0; i < n; i++) {
    b[i] = make_pair(1ll * t[i] * v - a[i], a[i]);
    c[i] = make_pair(1ll * t[i] * v + a[i], -a[i]);
  }
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());
  MergeSortTree mb(b);
  MergeSortTree mc(c);
  vector<int> f(n);
  f[0] = 0;
  mb.upd(0, 0, 0);
  mc.upd(0, 0, 0);
  for (int i = 1; i < n; i++) {
    f[i] = max(mb.mx(1ll * t[i] * v - a[i], a[i]), mc.mx(1ll * t[i] * v + a[i], -a[i])) + 1;
    mb.upd(1ll * t[i] * v - a[i], a[i], f[i]);
    mc.upd(1ll * t[i] * v + a[i], -a[i], f[i]);
  }
  cout << *std::max_element(f.begin(), f.end()) << "\n";
}


signed main() {
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
#endif
  ios_base::sync_with_stdio(false);
  int t;
  solve();
  return 0;
}