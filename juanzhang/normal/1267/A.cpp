#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template <typename T>
inline void chkmax(T &x, T y) {
  if (x < y) x = y;
}

template <typename T>
inline void chkmin(T &x, T y) {
  if (x > y) x = y;
}

typedef long long ll;
const int maxn = 2e5 + 10;
int n, tot;

struct line {
  ll l, r, x;
} a[maxn];

struct node {
  ll pos, x;
  int op, id;

  bool operator < (const node &o) const {
    return x > o.x || (x == o.x && a[id].l > a[o.id].l);
  }
} data[maxn * 3];

bool flg[maxn];

priority_queue <node> Q;

int main() {
  scanf("%d", &n);
  rep(i, 1, n) {
    ll l, r, x;
    scanf("%I64d %I64d %I64d", &l, &r, &x);
    a[i] = {l, r, x};
    data[++tot] = {l, 0, 0, 0};
    data[++tot] = {l + x, x, 1, i};
    data[++tot] = {r, x, -1, i};
  }
  sort(data + 1, data + tot + 1, [] (node x, node y) {
    return x.pos < y.pos || (x.pos == y.pos && x.op > y.op);
  });
  ll ans = 0, cur = 0;
  for (int i = 1; i <= tot; i++) {
//    printf("(%lld %lld %d %d) %lld\n", data[i].pos, data[i].x, data[i].op, data[i].id, cur);
    while (!Q.empty() && flg[Q.top().id]) {
      Q.pop();
    }
    if (!Q.empty()) {
      node tmp = Q.top();
      ll delta = max(cur, a[tmp.id].l);
      ll val = max(0ll, data[i].pos - delta) / tmp.x;
//      printf("#(%lld) %lld\n", cur, val);
      if (val) ans += val, cur = delta + val * tmp.x;
    }
    if (data[i].op > 0) {
      Q.push(data[i]);
    } else {
      flg[data[i].id] = 1;
    }
  }
  printf("%I64d", ans);
  return 0;
}