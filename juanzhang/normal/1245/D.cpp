#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

typedef long long ll;
typedef pair <int, int> pii;
const int maxn = 2010;
int n, h[maxn], val[maxn];

bool vis[maxn];
int pre[maxn];
ll e[maxn][maxn], dis[maxn];

int abso(int x) {
  return x < 0 ? -x : x;
}

struct node {
  int x, y;
} a[maxn];

int main() {
  scanf("%d", &n);
  rep(i, 1, n) scanf("%d %d", &a[i].x, &a[i].y);
  rep(i, 1, n) {
    int x;
    scanf("%d", &x);
    e[0][i] = x, dis[i] = x;
  }
  rep(i, 1, n) scanf("%d", val + i);
  rep(i, 1, n) {
    rep(j, i + 1, n) {
      ll w = 1ll * (val[i] + val[j]) * (abso(a[i].x - a[j].x) + abso(a[i].y - a[j].y));
      e[i][j] = e[j][i] = w;
    }
  }
  vector <int> ansu;
  vector <pii> ansp;
  vis[0] = 1;
  ll ans = 0;
  while (1) {
    int pos = -1;
    rep(i, 1, n) {
      if (!vis[i] && (pos == -1 || dis[pos] > dis[i])) {
        pos = i;
      }
    }
    if (pos == -1) break;
    int u = pos, v = pre[pos];
    if (!v) {
      ansu.push_back(u);
    } else {
      ansp.emplace_back(u, v);
    }
    vis[pos] = 1;
    ans += dis[pos];
    rep(i, 1, n) {
      if (!vis[i] && dis[i] > e[pos][i]) {
        dis[i] = e[pos][i], pre[i] = pos;
      }
    }
  }
  printf("%I64d\n", ans);
  printf("%d\n", (int) ansu.size());
  for (int x : ansu) printf("%d ", x);
  printf("\n%d\n", (int) ansp.size());
  for (pii p : ansp) printf("%d %d\n", p.first, p.second);
  return 0;
}