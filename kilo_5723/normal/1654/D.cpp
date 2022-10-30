#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int maxn = 2e5 + 5;
int mdiv[maxn], prim[maxn], sizp;
int inv[maxn];
ll ans = 0;
struct edge {
  int v, x, y;
};
vector<edge> e[maxn];
int cnt[maxn], mxm[maxn];
void add(int n) {
  while (n != 1) {
    int m = mdiv[n];
    n /= m;
    cnt[m]--;
  }
}
void sub(int n) {
  while (n != 1) {
    int m = mdiv[n];
    n /= m;
    cnt[m]++;
    mxm[m] = max(mxm[m], cnt[m]);
  }
}
void dfs1(int u, int f) {
  // printf("%d : ",u);
  // for (int i=2;i<=3;i++) printf(" %d",cnt[i]);
  // puts("");
  for (auto ed : e[u])
    if (ed.v != f) {
      add(ed.y);
      sub(ed.x);
      dfs1(ed.v, u);
      add(ed.x);
      sub(ed.y);
    }
}
void dfs2(int u, int f, ll w) {
  ans += w;
  for (auto ed : e[u])
    if (ed.v != f) dfs2(ed.v, u, w * inv[ed.x] % mod * ed.y % mod);
}
int main() {
  inv[1] = 1;
  for (int i = 2; i < maxn; i++) inv[i] = mod - mod / i * inv[mod % i] % mod;
  for (int i = 2; i < maxn; i++) mdiv[i] = i;
  for (int i = 2; i < maxn; i++) {
    if (mdiv[i] == i) prim[sizp++] = i;
    for (int j = 0; j < sizp && prim[j] <= mdiv[i] && i * prim[j] < maxn; j++)
      mdiv[i * prim[j]] = prim[j];
  }
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
      int p, q, x, y;
      scanf("%d%d%d%d", &p, &q, &x, &y);
      e[p].push_back({q, x, y});
      e[q].push_back({p, y, x});
    }
    fill(cnt, cnt + n + 1, 0);
    fill(mxm, mxm + n + 1, 0);
    dfs1(1, 1);
    ll w = 1;
    for (int i = 1; i <= n; i++)
      while (mxm[i]--) w = w * i % mod;
    ans = 0;
    // printf("%lld\n", w);
    dfs2(1, 1, w);
    printf("%lld\n", ans % mod);
    for (int i = 1; i <= n; i++) e[i].clear();
  }
  return 0;
}