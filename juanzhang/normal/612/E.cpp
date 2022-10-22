#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int maxn = 1e6 + 10;
int n, a[maxn], ans[maxn];

vector <int> cir[maxn];

int par[maxn], sz[maxn];

int find(int x) {
  return par[x] == x ? x : par[x] = find(par[x]);
}

void unite(int x, int y) {
  if ((x = find(x)) != (y = find(y))) {
    par[x] = y, sz[y] += sz[x];
  }
}

bool vis[maxn];
vector <int> vec, v1, v2;

void dfs(int u) {
  vis[u] = 1;
  vec.push_back(u);
  if (!vis[a[u]]) dfs(a[u]);
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    ans[i] = a[i];
    par[i] = i, sz[i] = 1;
  }
  for (int i = 1; i <= n; i++) {
    unite(i, a[i]);
  }
  for (int i = 1; i <= n; i++) {
    if (find(i) == i) {
      cir[sz[i]].push_back(i);
    }
  }
  for (int i = 2; i <= n; i++) {
    if (!cir[i].size()) continue;
    if (i % 2 == 0 && cir[i].size() % 2 != 0) {
      return puts("-1"), 0;
    }
    if (i % 2 != 0) {
      for (int u : cir[i]) {
        vec.clear();
        dfs(u);
        for (int j = 0; j < i; j++) {
          ans[vec[j]] = vec[(j + (i + 1) / 2) % i];
        }
      }
    } else {
      int sz = cir[i].size();
      for (int j = 0; j < sz; j += 2) {
        vec.clear();
        dfs(cir[i][j]), v1 = vec;
        vec.clear();
        dfs(cir[i][j + 1]), v2 = vec;
        vec.clear();
        for (int k = 0; k < i; k++) {
          vec.push_back(v1[k]);
          vec.push_back(v2[k]);
        }
        for (int k = 1; k < i << 1; k++) {
          ans[vec[k - 1]] = vec[k];
        }
        ans[vec.back()] = vec[0];
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    printf("%d ", ans[i]);
  }
  return 0;
}