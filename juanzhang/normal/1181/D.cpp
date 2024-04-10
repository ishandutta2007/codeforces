#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 5e5 + 10;
ll data[maxn];
int n, m, q, c[maxn], ans[maxn];

struct node {
  int x, y;

  inline bool operator < (const node &o) const {
    return x < o.x || (x == o.x && y < o.y);
  }
} a[maxn];

struct Query {
  int x, tid; ll k;

  inline bool operator < (const Query &o) const {
    return x < o.x || (x == o.x && k < o.k);
  }
} Q[maxn];

vector <int> vec[maxn];

int sum[maxn << 2];

#define mid ((l + r) >> 1)
#define lson k << 1, l, mid
#define rson k << 1 | 1, mid + 1, r

void ins(int k, int l, int r, int x) {
  sum[k]++;
  if (l == r) return;
  x <= mid ? ins(lson, x) : ins(rson, x);
}

int query(int k, int l, int r, int x) {
  if (l == r) return l;
  if (x <= sum[k << 1]) {
    return query(lson, x);
  } else {
    return query(rson, x - sum[k << 1]);
  }
}

#undef mid
#undef lson
#undef rson

void solve() {
  sort(Q + 1, Q + q + 1);
  int i = 1, j = 1;
  for (; i <= n; i++) {
    for (int x : vec[i]) {
      ins(1, 1, m, x);
    }
    for (; j <= q && Q[j].x == i; j++) {
      ans[Q[j].tid] = query(1, 1, m, Q[j].k);
    }
  }
  for (; j <= q; j++) {
    ans[Q[j].tid] = (Q[j].k - 1) % m + 1;
  }
}

int main() {
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 1, x; i <= n; i++) {
    scanf("%d", &x), c[x]++;
  }
  for (int i = 1; i <= m; i++) {
    a[i].x = c[i] + 1, a[i].y = i;
  }
  n++;
  sort(a + 1, a + m + 1);
  for (int i = 1, j = 1, now = 0; i <= n; i++) {
    for (; j <= m && a[j].x == i; j++, now++) {
      vec[i].push_back(a[j].y);
    }
    data[i] = data[i - 1] + now;
  }
  for (int i = 1; i <= q; i++) {
    ll k;
    scanf("%I64d", &k), k -= n - 1;
    int pos = lower_bound(data + 1, data + n + 1, k) - data - 1;
    Q[i].tid = i, Q[i].x = pos + 1, Q[i].k = k - data[pos];
  }
  solve();
  for (int i = 1; i <= q; i++) {
    printf("%d\n", ans[i]);
  }
  return 0;
}