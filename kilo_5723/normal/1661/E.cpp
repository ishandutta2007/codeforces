#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
const int maxn = 5e5 + 5, maxm = 2e6 + 5, k = 4;
inline int ls(int u) { return u << 1; }
inline int rs(int u) { return u << 1 | 1; }
struct dat {
  int a[2][3];
  int cnt;
  dat() {}
  dat(int c) { cnt = c; }
  dat(int x, int y, int z) {
    a[0][0] = a[1][0] = x;
    a[0][1] = a[1][1] = y;
    a[0][2] = a[1][2] = (x && !y && z) + z;
    cnt = max(max(a[0][0], a[0][1]), a[0][2]);
  }
};
// map<int,int> f,id;
int f[k * 2], id[k * 2];
int ff(int u) { return f[u] == u ? u : f[u] = ff(f[u]); }
dat operator+(dat a, dat b) {
  if (a.cnt < 0) return b;
  if (b.cnt < 0) return a;
  dat c(0, 0, 0);
  memset(f, 0, sizeof(f));
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 3; j++) {
      if (a.a[i][j]) f[a.a[i][j]] = a.a[i][j];
      if (b.a[i][j]) f[b.a[i][j] + k] = b.a[i][j] + k;
    }
  for (int i = 0; i < 3; i++)
    if (a.a[1][i] && b.a[0][i]) {
      int u = ff(a.a[1][i]), v = ff(b.a[0][i] + k);
      if (u == v) continue;
      f[u] = v;
      c.cnt--;
    }
  memset(id, 0, sizeof(id));
  int cnt = 0;
  for (int i = 0; i < 3; i++) {
    if (a.a[0][i]) {
      int t = ff(a.a[0][i]);
      if (!id[t]) id[t] = ++cnt;
      c.a[0][i] = id[t];
    }
    if (b.a[1][i]) {
      int t = ff(b.a[1][i] + k);
      if (!id[t]) id[t] = ++cnt;
      c.a[1][i] = id[t];
    }
  }
  c.cnt += a.cnt + b.cnt;
  return c;
}
dat a[maxm];
int l[maxm], r[maxm];
char s[maxn];
int b[3][maxn];
void build(int u, int _l, int _r) {
  // printf("%d\n",u);
  l[u] = _l;
  r[u] = _r;
  if (_l == _r) {
    a[u] = dat(b[0][_l], b[1][_l], b[2][_l]);
    return;
  }
  int _m = _l + ((_r - _l) >> 1);
  build(ls(u), _l, _m);
  build(rs(u), _m + 1, _r);
  a[u] = a[ls(u)] + a[rs(u)];
}
dat query(int u, int _l, int _r) {
  if (l[u] > _r || r[u] < _l) return dat(-1);
  if (l[u] >= _l && r[u] <= _r) return a[u];
  return query(ls(u), _l, _r) + query(rs(u), _l, _r);
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < 3; i++) {
    scanf("%s", s);
    for (int j = 0; j < n; j++) b[i][j] = s[j] - '0';
  }
  build(1, 0, n - 1);
  int m;
  scanf("%d", &m);
  while (m--) {
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d\n", query(1, l - 1, r - 1).cnt);
  }
  return 0;
}