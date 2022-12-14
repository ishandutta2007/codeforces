#include <cstdio>
#include <cstring>

typedef long long i64;

const int N = 100000 + 10, K = 6, MOD = 1000000007;

int n, tcase;
int a[N], sum[K][N];

int C[K][K];

inline int Pow(int base, int exp) {
  int res = 1;
  for (; exp; exp >>= 1) {
    if (exp & 1) res = (i64)res * base % MOD;
    base = (i64)base * base % MOD;
  }
  return res;
}

class IntervalTree {
  const int k;
  int mem[2 * N], tag[2 * N];

  inline int pos(int l, int r) { return (l + r) | (l != r); }

  void release(int l, int r) {
    int id = pos(l, r);
    if (l == r || !~tag[id]) return;
    int mid = (l + r) / 2, lch = pos(l, mid), rch = pos(mid + 1, r);
    tag[lch] = tag[id], tag[rch] = tag[id];
    mem[lch] = (i64)tag[id] * (sum[k][mid] - sum[k][l - 1] + MOD) % MOD;
    mem[rch] = (i64)tag[id] * (sum[k][r] - sum[k][mid] + MOD) % MOD;
    tag[id] = -1;
  }

  inline void update(int l, int r) {
    int id = pos(l, r);
    int mid = (l + r) / 2, lch = pos(l, mid), rch = pos(mid + 1, r);
    mem[id] = (mem[lch] + mem[rch]) % MOD;
  }

 public:
  IntervalTree(int _k): k(_k) {}

  void init(int l, int r) {
    tag[pos(l, r)] = -1;
    if (l == r) {
      mem[pos(l, r)] = (i64)a[l] * (sum[k][l] - sum[k][l - 1] + MOD) % MOD;
      return;
    }
    int mid = (l + r) / 2;
    init(l, mid);
    init(mid + 1, r);
    update(l, r);
  }

  int Query(int l, int r, int p, int q) {
    if (p <= l && r <= q) return mem[pos(l, r)];
    release(l, r);
    int mid = (l + r) / 2, res = 0;
    if (p <= mid) res += Query(l, mid, p, q);
    if (q > mid) res += Query(mid + 1, r, p, q);
    return res % MOD;
  }

  void Modify(int l, int r, int p, int q, int x) {
    release(l, r);
    if (p <= l && r <= q) {
      mem[pos(l, r)] = (i64)(tag[pos(l, r)] = x) * (sum[k][r] - sum[k][l - 1] + MOD) % MOD;
      return;
    }
    int mid = (l + r) / 2;
    if (p <= mid) Modify(l, mid, p, q, x);
    if (q > mid) Modify(mid + 1, r, p, q, x);
    update(l, r);
  }
} *pool[K];

int Query(int l, int r, int k) {
  int res = 0;
  for (int i = 0; i <= k; ++i) {
    int temp = (i64)C[k][i] * pool[i]->Query(1, n, l, r) % MOD * Pow(l - 1, k - i) % MOD;
    if ((k - i) & 1) temp = MOD - temp;
    (res += temp) %= MOD;
  }
  return res;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif
  scanf("%d%d", &n, &tcase);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  for (int i = 0; i < K; ++i) C[i][0] = 1;
  for (int i = 1; i < K; ++i)
    for (int j = 1; j <= i; ++j)
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
  for (int k = 0; k < K; ++k) {
    for (int i = 1; i <= n; ++i)
      sum[k][i] = (sum[k][i - 1] + Pow(i, k)) % MOD;
    (pool[k] = new IntervalTree(k))->init(1, n);
  }
  while (tcase--) {
    char op;
    int l, r, x;
    scanf(" %c%d%d%d", &op, &l, &r, &x);
    switch (op) {
      case '?':
        printf("%d\n", Query(l, r, x));
        break;
      case '=':
        for (int i = 0; i < K; ++i) pool[i]->Modify(1, n, l, r, x);
        break;
    }
  }
  return 0;
}