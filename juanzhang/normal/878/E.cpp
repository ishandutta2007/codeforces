#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

typedef long long ll;
const int maxn = 1e5 + 10, P = 1e9 + 7;
int n, q, a[maxn], ans[maxn];

struct Querys {
  int l, r, tid;
} Q[maxn];

int pw2[maxn], sum[maxn];

int par[maxn], pre[maxn], val[maxn], sz[maxn];

int query(int l, int r) {
  return (sum[l] - 1ll * sum[r + 1] * pw2[r - l + 1] % P + P) % P;
}

int find(int x) {
  return par[x] == x ? x : par[x] = find(par[x]);
}

void unite(int x, int y) {
  x = find(x), y = find(y), par[y] = x;
  if ((val[x] > 0 && sz[x] > 30) || (sz[x] > 30 && val[y] > 0) || (val[x] + ((ll) val[y] << sz[x])) > 1 << 30) {
    val[x] = 1 << 30;
  } else {
    val[x] += val[y] << sz[x];
  }
  sz[x] += sz[y];
}

int main() {
  pw2[0] = 1;
  rep(i, 1, 1e5) pw2[i] = 2ll * pw2[i - 1] % P;
  scanf("%d %d", &n, &q);
  rep(i, 1, n) scanf("%d", a + i), par[i] = i, sz[i] = 1;
  rep(i, 1, q) scanf("%d %d", &Q[i].l, &Q[i].r), Q[i].tid = i;
  sort(Q + 1, Q + q + 1, [] (Querys x, Querys y) {
    return x.r < y.r;
  });
  per(i, n, 1) sum[i] = (2ll * sum[i + 1] + a[i] + P) % P;
  for (int i = 1, j = 1; i <= n; i++) {
    val[i] = a[i];
    while (find(i) > 1 && val[find(i)] > 0) {
      unite(find(i) - 1, i);
    }
//    putchar('#');
//    rep(k, 1, i) if (find(k) == k) {
//      printf("%d ", k);
//    }
//    puts("");
    int rt = find(i);
    pre[rt] = (query(rt, i) + pre[find(rt - 1)]) % P;
    for (; j <= q && Q[j].r == i; j++) {
      int x = Q[j].l, cur = find(x);
      ans[Q[j].tid] = (2ll * (pre[rt] - pre[cur] + P) + query(x, cur + sz[cur] - 1)) % P;
    }
  }
  rep(i, 1, q) printf("%d\n", ans[i]);
  return 0;
}