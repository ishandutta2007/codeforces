#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using s64 = long long;
using u64 = unsigned long long;

using r32 = double;
using r64 = long double;

inline int getint() {
  static char c;
  while (((c = getchar()) < '0' || c > '9') && c != '-');

  if (c == '-') {
    int res = 0;
    while ((c = getchar()) >= '0' && c <= '9') {
      res = res * 10 + c - '0';
    }
    return -res;
  } else {
    int res = c - '0';
    while ((c = getchar()) >= '0' && c <= '9') {
      res = res * 10 + c - '0';
    }
    return res;
  }
}

const int MaxN = 3000;
const int M = 1000000007;

inline int modpow(int a, const int &n) {
  int res = 1;
  for (int i = n; i; i >>= 1) {
    if (i & 1) {
      res = (s64)res * a % M;
    }
    a = (s64)a * a % M;
  }
  return res;
}

int n, d;
vector<int> adj[MaxN + 1];

int f[MaxN + 1][MaxN + 2];
int g[MaxN + 1][MaxN + 2];

void dfs(const int &u) {
  for (int i = 1; i <= n + 1; ++i) {
    f[u][i] = 1;
  }
  for (int v : adj[u]) {
    dfs(v);
    for (int i = 1; i <= n + 1; ++i) {
      f[u][i] = (s64)f[u][i] * g[v][i] % M;
    }
  }
  for (int i = 1; i <= n + 1; ++i) {
    g[u][i] = (g[u][i - 1] + f[u][i]) % M;
  }
}

int inv[MaxN + 2];

inline int lagrange() {
  int res = 0;
  for (int i = 1; i <= n + 1; ++i) {
    int p = 1;
    for (int j = 1; j <= n + 1; ++j) {
      if (i != j) {
        p = (s64)p * (d + M - j) % M;
        int x = i - j;
        if (x > 0) {
          p = (s64)p * inv[x] % M;
        } else {
          p = (s64)p * inv[-x] % M * (M - 1) % M;
        }
      }
    }
    res = (res + (s64)p * g[1][i]) % M;
  }
  return res;
}

int main() {
  cin >> n >> d;
  for (int v = 2; v <= n; ++v) {
    int u = getint();
    adj[u].push_back(v);
  }

  inv[1] = 1;
  for (int i = 2; i <= n + 1; ++i) {
    inv[i] = (s64)(M - M / i) * inv[M % i] % M;
  }

  dfs(1);

  cout << lagrange() << endl;

  return 0;
}