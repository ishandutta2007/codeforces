#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template <typename T>
inline void chkmax(T &x, T y) { if (x < y) x = y; }

template <typename T>
inline void chkmin(T &x, T y) { if (x > y) x = y; }

const int maxn = 2e5 + 10, P = 1e9 + 7;
int n, m, S, T;

int h[maxn];

struct edges {
  int nxt, to, w;
} e[maxn << 1];

void addline(int u, int v, int w) {
  static int cnt = 1;
  e[++cnt] = edges{h[u], v, w}, h[u] = cnt;
}

typedef unsigned u32;
typedef unsigned long long u64;
int pw2[maxn << 1];
u64 hash_val[maxn];

void init() {
  pw2[0] = 1;
  rep(i, 1, 2e5) pw2[i] = 2ll * pw2[i - 1] % P;
  rep(i, 0, 1e5) hash_val[i] = u64(u32(rnd())) << 32 | u32(rnd());
}

const int maxsz = maxn * 50, N = 2e5;
u64 val[maxsz];
int tot, rt[maxn], ls[maxsz], rs[maxsz], sum[maxsz];

#define mid ((l + r) >> 1)

void maintain(int k) {
  int l = ls[k], r = rs[k];
  val[k] = val[l] ^ val[r];
  sum[k] = sum[l] + sum[r];
}

void build(int &k, int l, int r) {
  k = ++tot;
  if (l == r) return;
  build(ls[k], l, mid), build(rs[k], mid + 1, r);
}

bool query_leq(int p, int q, int l, int r) {
  if (l == r) return sum[p] <= sum[q];
  if (val[rs[p]] == val[rs[q]]) {
    return query_leq(ls[p], ls[q], l, mid);
  } else {
    return query_leq(rs[p], rs[q], mid + 1, r);
  }
}

void upd(int &k, int rt, int l, int r, int x) {
  k = ++tot, sum[k] = sum[rt], val[k] = val[rt], ls[k] = ls[rt], rs[k] = rs[rt];
  if (l == r) {
    sum[k] = 1, val[k] = hash_val[l]; return;
  }
  x <= mid ? upd(ls[k], ls[rt], l, mid, x) : upd(rs[k], rs[rt], mid + 1, r, x);
  maintain(k);
}

bool query_01(int k, int l, int r, int x) {
  if (l == r) return sum[k];
  return x <= mid ? query_01(ls[k], l, mid, x) : query_01(rs[k], mid + 1, r, x);
}

int query(int k, int l, int r, int x) {
  if (l == r) return sum[k];
  return x <= mid ? query(ls[k], l, mid, x) : sum[ls[k]] + query(rs[k], mid + 1, r, x);
}

int replace(int k, int rt, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) return rt;
  int res = ++tot;
  ls[res] = ql <= mid ? replace(ls[k], ls[rt], l, mid, ql, qr) : ls[k];
  rs[res] = qr > mid ? replace(rs[k], rs[rt], mid + 1, r, ql, qr) : rs[k];
  return maintain(res), res;
}

int add(int k, int pos) {
  int tmp;
  if (!query_01(k, 0, N, pos)) {
    return upd(tmp, k, 0, N, pos), tmp;
  }
  int delta = query(k, 0, N, pos);
  int l = pos, r = N, ans = pos;
  while (l <= r) {
    query(k, 0, N, mid) == delta + mid - pos ? l = (ans = mid) + 1 : r = mid - 1;
  }
  tmp = replace(k, rt[S], 0, N, pos, ans);
  upd(tmp, tmp, 0, N, ans + 1);
  return tmp;
}

void print(int k, int l, int r, int ql, int qr) {
  if (l == r) {
    printf("%d", sum[k]);
    if (r == 9) putchar(10);
    return;
  }
  if (ql <= mid) print(ls[k], l, mid, ql, qr);
  if (qr > mid) print(rs[k], mid + 1, r, ql, qr);
}

void print(int x, int cur = 0) {
  printf("#(%d) : ", x);
  print(cur ? cur : rt[x], 0, N, 0, 9);
}

#undef mid

typedef pair <int, int> pii;
int pre[maxn];
bool vis[maxn], flg[maxn];

struct cmp {
  bool operator () (pii x, pii y) {
    return !query_leq(x.first, y.first, 0, N);
  }
};

priority_queue <pii, vector <pii>, cmp> Q;

int main() {
  init();
  scanf("%d %d", &n, &m);
  rep(i, 1, m) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    addline(u, v, w), addline(v, u, w);
  }
  scanf("%d %d", &S, &T);
  if (S == T) return printf("0\n1\n%d", S), 0;
  build(rt[S], 0, N);
  Q.push(pii(rt[S], S));
  while (!Q.empty()) {
    pii p = Q.top();
    int u = p.second;
    Q.pop();
    if (vis[u]) continue;
    vis[u] = 1;
//    print(u);
    for (int i = h[u]; i; i = e[i].nxt) {
      int v = e[i].to;
      if (vis[v]) continue;
//      printf("(%d -> %d) %d\n", u, v, e[i].w);
      int tmp = add(rt[u], e[i].w);
//      print(0, tmp);
//if (v == T) print(0, tmp);
      if (!flg[v] || query_leq(tmp, rt[v], 0, N)) {
        rt[v] = tmp, pre[v] = i, flg[v] = 1;
        Q.push(pii(rt[v], v));
      }
    }
  }
  if (!pre[T]) return puts("-1"), 0;
  int res = 0;
  vector <int> vec;
  for (int u = T; u != S; u = e[pre[u] ^ 1].to) {
    vec.push_back(u);
    res = (res + pw2[e[pre[u]].w]) % P;
  }
  vec.push_back(S);
  reverse(vec.begin(), vec.end());
  printf("%d\n%d\n", res, (int) vec.size());
  for (int u : vec) printf("%d ", u);
  return 0;
}