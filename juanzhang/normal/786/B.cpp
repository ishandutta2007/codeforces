#include <bits/stdc++.h>
using namespace std;

#define mid ((l + r) >> 1)
#define lson ls[k], l, mid
#define rson rs[k], mid + 1, r
typedef long long ll;
typedef pair <ll, int> pii;
const int maxn = 1e5 + 10, maxm = maxn << 3;
ll dis[maxm];
int n, m, s, tot, rt_i, rt_o, h[maxm], ls[maxm], rs[maxm];

struct edges {
  int nxt, to, w;

  edges() {}
  edges(int x, int y, int z) :
    nxt(x), to(y), w(z) {}
} e[maxn * 30];

void addline(int u, int v, int w) {
  static int cnt;
  e[++cnt] = edges(h[u], v, w), h[u] = cnt;
}

void build_i(int &k, int l, int r) {
  k = ++tot;
  if (l == r) {
    addline(k, l, 0); return;
  }
  build_i(lson), build_i(rson);
  addline(k, ls[k], 0), addline(k, rs[k], 0);
}

void build_o(int &k, int l, int r) {
  k = ++tot;
  if (l == r) {
    addline(l, k, 0); return;
  }
  build_o(lson), build_o(rson);
  addline(ls[k], k, 0), addline(rs[k], k, 0);
}

void ins_i(int k, int l, int r, int ql, int qr, int u, int x) {
  if (ql <= l && r <= qr) {
    addline(u, k, x); return;
  }
  if (ql <= mid) ins_i(lson, ql, qr, u, x);
  if (qr > mid) ins_i(rson, ql, qr, u, x);
}

void ins_o(int k, int l, int r, int ql, int qr, int u, int x) {
  if (ql <= l && r <= qr) {
    addline(k, u, x); return;
  }
  if (ql <= mid) ins_o(lson, ql, qr, u, x);
  if (qr > mid) ins_o(rson, ql, qr, u, x);
}

int main() {
  scanf("%d %d %d", &n, &m, &s);
  tot = n;
  build_i(rt_i, 1, n);
  build_o(rt_o, 1, n);
  for (int i = 1; i <= m; i++) {
    int op, u, l, r, w;
    scanf("%d %d %d %d", &op, &u, &l, &r);
    if (op == 1) {
      addline(u, l, r);
    } else if (op == 2) {
      scanf("%d", &w);
      ins_i(rt_i, 1, n, l, r, u, w);
    } else {
      scanf("%d", &w);
      ins_o(rt_o, 1, n, l, r, u, w);
    }
  }
  static priority_queue <pii, vector <pii>, greater <pii> > Q;
  memset(dis, 0x3f, sizeof dis);
  dis[s] = 0, Q.push(pii(0, s));
  while (!Q.empty()) {
    pii p = Q.top();
    int u = p.second;
    Q.pop();
    if (dis[u] < p.first) continue;
    for (int i = h[u]; i; i = e[i].nxt) {
      int v = e[i].to;
      if (dis[v] > dis[u] + e[i].w) {
        dis[v] = dis[u] + e[i].w;
        Q.push(pii(dis[v], v));
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    printf("%I64d ", dis[i] < 1ll << 60 ? dis[i] : -1);
  }
  return 0;
}