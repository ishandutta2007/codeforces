#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int maxn = 3e5, maxm = 1 << 20;
inline int ls(int u) { return u << 1; }
inline int rs(int u) { return u << 1 | 1; }
int l[maxm], r[maxm];
ll val[maxm][3][2];
void update(int u) {
  memset(val[u], 0, sizeof(val[u]));
  auto vu = val[u], vl = val[ls(u)], vr = val[rs(u)];
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 2; j++)
      for (int k = 0; k < 2; k++) {
        vu[i][k] += vl[i][j] * vr[j][k] % mod;
      }
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 2; j++) vu[i][j] %= mod;
  // for (int i = 0; i < 2; i++)
  //   for (int j = 0; j < 2; j++) {
  //     val[u][i & j] += val[ls(u)][i] * val[rs(u)][j] % mod;
  //     val[u][i | j] += val[ls(u)][i] * val[rs(u)][j] % mod;
  //     val[u][i ^ j] += val[ls(u)][i] * val[rs(u)][j] % mod;
  //   }
  // val[u][0] %= mod;
  // val[u][1] %= mod;
}
void modify(int u, int v) {
  memset(val[u], 0, sizeof(val[u]));
  for (int i = 0; i < 2; i++) {
    val[u][i][i & v]++;
    val[u][i][i | v]++;
    val[u][i][i ^ v]++;
  }
  val[u][2][v] = 1;
  val[u][2][!v] = 0;
}
void build(int u, int _l, int _r) {
  l[u] = _l;
  r[u] = _r;
  modify(u, 0);
  if (_l == _r) return;
  int _m = (_l + _r) / 2;
  build(ls(u), _l, _m);
  build(rs(u), _m + 1, _r);
  update(u);
}
void modify(int u, int p, int v) {
  if (p < l[u] || p > r[u]) return;
  if (l[u] == r[u]) {
    modify(u, v);
    return;
  }
  modify(ls(u), p, v);
  modify(rs(u), p, v);
  update(u);
}
struct opr {
  int x, u, v;
};
bool operator<(opr a, opr b) { return a.x < b.x; }
vector<opr> arr;
vector<int> itr;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    arr.push_back({l, i, 1});
    arr.push_back({r + 1, i, 0});
    itr.push_back(l);
    itr.push_back(r + 1);
  }
  sort(arr.begin(), arr.end());
  reverse(arr.begin(), arr.end());
  sort(itr.begin(), itr.end());
  itr.resize(unique(itr.begin(), itr.end()) - itr.begin());
  build(1, 0, n - 1);
  ll ans = 0;
  for (int i = 1; i < itr.size(); i++) {
    int v = itr[i - 1], m = itr[i] - itr[i - 1];
    while (arr.size() && arr.back().x == v) {
      auto op = arr.back();
      arr.pop_back();
      modify(1, op.u, op.v);
    }
    ans += m * val[1][2][1] % mod;
    ans %= mod;
    // printf("%lld\n", ans);
  }
  printf("%lld\n", ans);
  return 0;
}