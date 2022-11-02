#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int inf = 1e9;
const int maxn = 105;

namespace Dinic {
static int gra[maxn][maxn];
static int dep[maxn * 2], vis[maxn * 2];
int n;
int dfs(int u, int t) {
  if (u < n) {
    for (int v = n; v < 2 * n; v++)
      if (gra[u][v - n] == 1 && dep[v] == dep[u] + 1 && dfs(v, t)) {
        gra[u][v - n] = -1;
        return true;
      }
  } else {
    if (!vis[u]) return vis[u] = true;
    for (int v = 0; v < n; v++)
      if (gra[v][u - n] == -1 && dep[v] == dep[u] + 1 && dfs(v, t)) {
        gra[v][u - n] = 1;
        return true;
      }
  }
  dep[u] = inf;
  return false;
}
bool bfs(int s, int t) {
  fill(dep, dep + 2 * n, inf);
  queue<int> que;
  for (int i = 0; i < n; i++)
    if (!vis[i]) {
      que.push(i);
      dep[i] = 1;
    }
  int lim = inf;
  while (que.size()) {
    int u = que.front();
    // printf("u : %d\n",u);
    if (dep[u] > lim) break;
    que.pop();
    if (u < n) {
      for (int v = n; v < 2 * n; v++)
        if (gra[u][v - n] == 1)
          if (dep[v] > dep[u] + 1) {
            dep[v] = dep[u] + 1;
            que.push(v);
          }
    } else {
      if (!vis[u]) lim = dep[u];
      for (int v = 0; v < n; v++)
        if (gra[v][u - n] == -1)
          if (dep[v] > dep[u] + 1) {
            dep[v] = dep[u] + 1;
            que.push(v);
          }
    }
  }
  // printf("lim : %d\n", lim);
  return lim < inf / 2;
}
void match(int res[]) {
  fill(vis, vis + 2 * n, false);
  while (bfs(n - 1, 2 * n - 1))
    for (int i = 0; i < n; i++)
      if (!vis[i])
        if (dfs(i, 2 * n - 1)) vis[i] = true;
  // n--;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if (gra[i][j] == -1) res[i] = j;
    }
  // for (int i = 0; i < n; i++) printf("%d ", res[i]);
  // puts("");
}
}  // namespace Dinic

void minor(int arr[], int pos, int n, int res[], int &sizr) {
  // sizr = 0;
  while (~arr[pos]) {
    int val = arr[pos], stp = (val + n - pos) % n;
    arr[pos] = -1;
    while (stp--) res[sizr++] = val;
    pos = val;
  }
}
void major(int arr[], int pos, int n, int res[]) {
  static int lis[maxn];
  int sizl = 0, sizr = 0;
  while (~arr[pos]) {
    int val = arr[pos];
    lis[sizl++] = pos;
    arr[pos] = -1;
    pos = val;
  }
  for (int i = 1; i < sizl; i++) {
    while (pos != lis[i]) {
      if (~arr[pos]) minor(arr, pos, n, res, sizr);
      res[sizr++] = lis[i];
      pos = (pos + 1) % n;
    }
  }
  do {
    if (~arr[pos]) minor(arr, pos, n, res, sizr);
    res[sizr++] = lis[0];
    pos = (pos + 1) % n;
  } while (pos != lis[0]);
  while (sizr < n * (n - 1)) res[sizr++] = pos;
}
int main() {
  int n;
  scanf("%d", &n);
  static int a[maxn][maxn];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
      a[i][j]--;
    }
  // static bool gra[maxn][maxn];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      fill(Dinic::gra[j], Dinic::gra[j] + n, false);
      for (int k = i; k < n; k++) Dinic::gra[j][a[j][k]] = 1;
    }
    // for (int i = 0; i < n; i++) {
    //   for (int j = 0; j < n; j++) printf("%d ", gra[i][j]);
    //   puts("");
    // }
    // puts("");
    static int res[maxn];
    Dinic::n = n;
    Dinic::match(res);
    // for (int i = 0; i < n; i++) printf("%d ", res[i] + 1);
    // puts("");
    for (int j = 0; j < n; j++)
      for (int k = i; k < n; k++)
        if (a[j][k] == res[j]) {
          swap(a[j][k], a[j][i]);
          break;
        }
    // for (int i = 0; i < n; i++) {
    //   for (int j = 0; j < n; j++) printf("%d ", a[i][j] + 1);
    //   puts("");
    // }
    // puts("");
  }
  // if (n == 100) return 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < i; j++) swap(a[i][j], a[j][i]);
  static int ans[maxn * maxn][maxn];
  for (int i = 0; i < n; i++) {
    static int res[maxn * maxn];
    major(a[i], i, n, res);
    for (int j = 0; j < n * (n - 1); j++) {
      ans[j][(j + i) % n] = res[j];
    }
  }
  printf("%d\n", n * (n - 1));
  for (int i = 0; i < n * (n - 1); i++)
    for (int j = 0; j < n; j++)
      printf("%d%c", ans[i][j] + 1, j < n - 1 ? ' ' : '\n');

  return 0;
}