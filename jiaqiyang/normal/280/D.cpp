#include <cctype>
#include <cstdio>

const int N = 100000 + 10, INF = 0x3f3f3f3f;

inline int nextInt() {
  char ch;
  while (ch = getchar(), !isdigit(ch) && ch != '-') {}
  bool sig = false;
  if (ch == '-') sig = true, ch = getchar();
  int res = ch - '0';
  while (isdigit(ch = getchar())) res = 10 * res + ch - '0';
  if (sig) res = -res;
  return res;
}

inline bool checkMax(int &lhs, int rhs) { return rhs > lhs ? (lhs = rhs, true) : false; }

struct Info {
  int ls, rs, mx, sum;
  int l, r, p, q;
  Info() {
    ls = rs = mx = -INF;
    sum = 0;
    l = r = p = q = 0;
  }
  Info(int pos, int x) {
    ls = rs = mx = sum = x;
    l = r = p = q = pos;
  }
};

inline Info operator+ (const Info &lhs, const Info &rhs) {
  Info res;
  res.ls = lhs.ls, res.rs = rhs.rs;
  res.p = lhs.p, res.q = rhs.q;
  if (checkMax(res.ls, lhs.sum + rhs.ls)) res.p = rhs.p;
  if (checkMax(res.rs, rhs.sum + lhs.rs)) res.q = lhs.q;
  res.mx = lhs.mx, res.l = lhs.l, res.r = lhs.r;
  if (checkMax(res.mx, rhs.mx)) res.l = rhs.l, res.r = rhs.r;
  if (checkMax(res.mx, lhs.rs + rhs.ls)) res.l = lhs.q, res.r = rhs.p;
  res.sum = lhs.sum + rhs.sum;
  return res;
}

#define pos(l, r) (((l) + (r)) | ((l) != (r)))

int n, a[N];

struct Tree {
  Info info[2 * N];
  void build(int l, int r) {
    int id = pos(l, r);
    if (l == r) {
      info[id] = Info(l, a[l]);
      return;
    }
    int mid = (l + r) / 2;
    build(l, mid);
    build(mid + 1, r);
    info[id] = info[pos(l, mid)] + info[pos(mid + 1, r)];
  }
  void modify(int l, int r, int p, int v) {
    int id = pos(l, r);
    if (l == r) {
      info[id] = Info(p, v);
      return;
    }
    int mid = (l + r) / 2;
    if (p <= mid) modify(l, mid, p, v); else modify(mid + 1, r, p, v);
    info[id] = info[pos(l, mid)] + info[pos(mid + 1, r)];
  }
  Info query(int l, int r, int p, int q) {
    int id = pos(l, r);
    if (p <= l && r <= q) return info[id];
    Info res;
    int mid = (l + r) / 2;
    if (p <= mid) res = res + query(l, mid, p, q);
    if (q > mid) res = res + query(mid + 1, r, p, q);
    return res;
  }
} tree[2];

struct Range {
  int l, r;
  Info info;
  Range() {}
  Range(int _l, int _r, const Info &_info): l(_l), r(_r), info(_info) {}
  inline bool operator> (const Range &rhs) const { return info.mx > rhs.info.mx; }
};

inline Range operator+ (const Range &lhs, const Range &rhs) {
  Range res;
  res.l = lhs.l, res.r = rhs.r;
  res.info = lhs.info + rhs.info;
  return res;
}

struct Vector {
  Range range[N];
  int tot;
  void clear() { tot = 0; }
  void push(const Range &cur) {
    int k = tot + 1;
    for (int i = 1; i <= tot; ++i) {
      if (range[i].l > cur.r) {
        k = i;
        break;
      }
    }
    for (int i = ++tot; i > k; --i) range[i] = range[i - 1];
    range[k] = cur;
    maintain();
  }
  void maintain() {
    if (!tot) return;
    int t = tot;
    tot = 1;
    for (int i = 2; i <= t; ++i)
      if (range[i].l > range[tot].r + 1) range[++tot] = range[i]; else range[tot] = range[tot] + range[i];
  }
  int getMax() {
    if (!tot) return 0;
    int res = 1;
    for (int i = 2; i <= tot; ++i) if (range[i] > range[res]) res = i;
    return res;
  }
  void erase(int p) {
    for (int i = p; i < tot; ++i) range[i] = range[i + 1];
    --tot;
    maintain();
  }
} mem[2];

int main() {
  n = nextInt();
  for (int i = 1; i <= n; ++i) a[i] = nextInt();
  tree[0].build(1, n);
  for (int i = 1; i <= n; ++i) a[i] = -a[i];
  tree[1].build(1, n);
  for (int m = nextInt(); m--;) {
    if (nextInt() == 0) {
      int p = nextInt(), v = nextInt();
      tree[0].modify(1, n, p, v);
      tree[1].modify(1, n, p, -v);
    } else {
      int l = nextInt(), r = nextInt(), k = nextInt();
      mem[0].clear(), mem[1].clear();
      mem[0].push(Range(l, r, tree[0].query(1, n, l, r)));
      int ans = 0;
      while (k--) {
        int u = mem[0].getMax(), v = mem[1].getMax();
        if (!u && !v) break;
        if (!u || (v && mem[1].range[v] > mem[0].range[u])) {
          Range cur = mem[1].range[v];
          if (cur.info.mx <= 0) break;
          ans += cur.info.mx;
          mem[1].erase(v);
          int p = cur.info.l, q = cur.info.r;
          if (cur.l < p) mem[1].push(Range(cur.l, p - 1, tree[1].query(1, n, cur.l, p - 1)));
          if (q < cur.r) mem[1].push(Range(q + 1, cur.r, tree[1].query(1, n, q + 1, cur.r)));
          mem[0].push(Range(p, q, tree[0].query(1, n, p, q)));
        } else {
          Range cur = mem[0].range[u];
          if (cur.info.mx <= 0) break;
          ans += cur.info.mx;
          mem[0].erase(u);
          int p = cur.info.l, q = cur.info.r;
          if (cur.l < p) mem[0].push(Range(cur.l, p - 1, tree[0].query(1, n, cur.l, p - 1)));
          if (q < cur.r) mem[0].push(Range(q + 1, cur.r, tree[0].query(1, n, q + 1, cur.r)));
          mem[1].push(Range(p, q, tree[1].query(1, n, p, q)));
        }
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}