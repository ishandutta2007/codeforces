#include <cstdio>
#include <cstring>

const int N = 100000 + 10, S = 60;

int n, a[N];

struct State {
  int a[S], b[S];
  inline State& operator+= (const State &rhs) {
    for (int i = 0; i < S; ++i) {
      b[i] += rhs.b[a[i]];
      a[i] = rhs.a[a[i]];
    }
    return *this;
  }
};

State state[2 * N], mem[S];

inline int pos(int l, int r) { return (l + r) | (l != r); }

void update(int l, int r) {
  int mid = (l + r) >> 1;
  (state[pos(l, r)] = state[pos(l, mid)]) += state[pos(mid + 1, r)];
}

void build(int l, int r) {
  if (l == r) {
    scanf("%d", &a[l]);
    state[pos(l, r)] = mem[a[l]];
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid);
  build(mid + 1, r);
  update(l, r);
}

void modify(int l, int r, int p, int v) {
  if (l == r) {
    state[pos(l, r)] = mem[v];
    return;
  }
  int mid = (l + r) >> 1;
  if (p <= mid) modify(l, mid, p, v); else modify(mid + 1, r, p, v);
  update(l, r);
}

State res;

void query(int l, int r, int p, int q) {
  if (p <= l && r <= q) {
    res += state[pos(l, r)];
    return;
  }
  int mid = (l + r) >> 1;
  if (p <= mid) query(l, mid, p, q);
  if (q > mid) query(mid + 1, r, p, q);
  update(l, r);
}

int main() {
  scanf("%d", &n);
  for (int i = 2; i <= 6; ++i) {
    for (int j = 0; j < S; ++j) {
      int &p = mem[i].a[j] = j, &q = mem[i].b[j] = 0;
      if (p % i == 0) p = (p + 1) % S, ++q;
      p = (p + 1) % S, ++q;
    }
  }
  build(1, n);
  int q;
  for (scanf("%d", &q); q--;) {
    char c;
    int x, y;
    scanf(" %c%d%d", &c, &x, &y);
    if (c == 'A') {
      --y;
      memset(&res, 0, sizeof(State));
      query(1, n, x, y);
      printf("%d\n", res.b[0]);
    } else {
      modify(1, n, x, a[x] = y);
    }
  }
  return 0;
}