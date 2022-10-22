#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int maxn = 1e5 + 10, P = 1e9 + 7;
int n, a[maxn], dp[maxn][2], pre[maxn], suf[maxn];

vector <int> e[maxn];

void dfs(int u) {
  if (e[u].empty()) {
    dp[u][a[u]] = 1; return;
  }
  for (int v : e[u]) {
    dfs(v);
  }
  pre[0] = 1;
  int sz = e[u].size();
  for (int i = 0; i < sz; i++) {
    int v = e[u][i];
    pre[i + 1] = 1ll * pre[i] * (dp[v][0] + dp[v][1]) % P;
  }
  suf[sz] = 1;
  for (int i = sz - 1; ~i; i--) {
    int v = e[u][i];
    suf[i] = 1ll * suf[i + 1] * (dp[v][0] + dp[v][1]) % P;
  }
  dp[u][0] = 1;
  for (int i = 0; i < sz; i++) {
    int v = e[u][i];
    dp[u][1] = (dp[u][1] + 1ll * dp[v][1] * pre[i] % P * suf[i + 1] % P) % P;
    dp[u][0] = 1ll * dp[u][0] * (dp[v][0] + dp[v][1]) % P;
  }
  if (a[u]) {
    dp[u][1] = dp[u][0], dp[u][0] = 0;
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    int x;
    scanf("%d", &x);
    e[x + 1].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  dfs(1);
  printf("%d", dp[1][1]);
  return 0;
}