#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 10;
int n, k, a[maxn];

#define mid ((l + r) >> 1)
#define lson k << 1, l, mid
#define rson k << 1 | 1, mid + 1, r

ll val[maxn << 2];

void maintain(int k) {
  val[k] = min(val[k << 1], val[k << 1 | 1]);
}

void build(int k, int l, int r) {
  if (l == r) {
    val[k] = a[l]; return;
  }
  build(lson), build(rson), maintain(k);
}

void upd(int k, int l, int r, int x, ll v) {
  if (l == r) {
    val[k] = v; return;
  }
  x <= mid ? upd(lson, x, v) : upd(rson, x, v);
  maintain(k);
}

int query(int k, int l, int r, ll v) {
  if (l == r) return l;
  return val[k << 1] <= v ? query(lson, v) : query(rson, v);
}

ll query(int k, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) return val[k];
  ll res = 1ll << 60;
  if (ql <= mid) res = query(lson, ql, qr);
  if (qr > mid) res = min(res, query(rson, ql, qr));
  return res;
}

#undef mid
#undef lson
#undef rson

ll ans[maxn];

set <int> S;
queue <int> Q;

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  build(1, 1, n);
  ll cur = 0;
  int cnt = 0;
  while (cnt < n) {
    if (S.empty()) {
      ll nxt = val[1];
      cur = max(cur, nxt);
      int pos = query(1, 1, n, cur);
      Q.push(pos), S.insert(pos), upd(1, 1, n, pos, 1ll << 60);
    } else {
      ll nxt = cur + k;
      int pos = *S.begin();
      if (pos == 1) {
        cnt++;
        ans[Q.front()] = nxt, cur = nxt;
        S.erase(Q.front()), Q.pop();
      } else {
        ll x = query(1, 1, n, 1, pos - 1);
        if (x <= nxt) {
          int tmp = query(1, 1, n, x);
          Q.push(tmp), S.insert(tmp), upd(1, 1, n, tmp, 1ll << 60);
        } else {
          cnt++;
          ans[Q.front()] = nxt, cur = nxt;
          S.erase(Q.front()), Q.pop();
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    printf("%lld ", ans[i]);
  }
  return 0;
}