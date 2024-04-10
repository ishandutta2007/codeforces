#include <cctype>
#include <cstdio>
#include <cstring>

const int N = 200000 + 10, L = 20, S = 32;

int nextInt() {
  char ch;
  while (!isdigit(ch = getchar())) {}
  int res = ch - '0';
  while (isdigit(ch = getchar())) res = 10 * res + ch - '0';
  return res;
}

int n, q;

unsigned a[N];

struct Info {
  unsigned data[S];
  inline int size() {
    int res = 0;
    for (int i = 0; i < S; ++i) if (data[i]) ++res;
    return res;
  }
  inline void clear() { memset(data, 0, sizeof data); }
  unsigned &operator[] (int s) { return data[s]; }
  unsigned operator[] (int s) const { return data[s]; }
  inline void insert(unsigned x) {
    for (int i = S - 1; i >= 0; --i) if ((x ^ data[i]) < x) x ^= data[i];
    if (x) data[31 - __builtin_clz(x)] = x;
  }
} info[2 * N];

inline Info operator+ (Info lhs, const Info &rhs) {
  for (int i = 0; i < S; ++i) if (rhs[i]) lhs.insert(rhs[i]);
  return lhs;
}

inline int pos(int l, int r) { return (l + r) | (l != r); }

void build(int l, int r) {
  int id = pos(l, r);
  if (l == r) {
    info[id].insert(a[l] ^ a[l + 1]);
    return;
  }
  int mid = (l + r) / 2;
  build(l, mid);
  build(mid + 1, r);
  info[id] = info[pos(l, mid)] + info[pos(mid + 1, r)];
}

unsigned bit[N];

inline void add(int p, unsigned v) {
  for (; p <= n; p += p & -p) bit[p] ^= v;
}

inline unsigned query(int p) {
  unsigned res = a[p];
  for (; p; p ^= p & -p) res ^= bit[p];
  return res;
}

void modify(int l, int r, int p) {
  int id = pos(l, r);
  if (l == r) {
    info[id].clear();
    info[id].insert(query(p) ^ query(p + 1));
    return;
  }
  int mid = (l + r) / 2;
  if (p <= mid) modify(l, mid, p); else modify(mid + 1, r, p);
  info[id] = info[pos(l, mid)] + info[pos(mid + 1, r)];
}

Info ans;

void query(int l, int r, int p, int q) {
  int id = pos(l, r);
  if (p <= l && r <= q) {
    ans = ans + info[id];
    return;
  }
  int mid = (l + r) / 2;
  if (p <= mid) query(l, mid, p, q);
  if (q > mid) query(mid + 1, r, p, q);
}

int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++i) a[i] = nextInt();
  build(1, n);
  while (q--) {
    int t = nextInt(), l = nextInt(), r = nextInt();
    if (t == 1) {
      unsigned x = nextInt();
      add(l, x);
      add(r + 1, x);
      if (l > 1) modify(1, n, l - 1);
      modify(1, n, r);
    } else {
      ans.clear();
      ans.insert(query(r));
      if (l < r) query(1, n, l, r - 1);
      printf("%d\n", 1 << ans.size());
    }
  }
  return 0;
}