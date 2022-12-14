#include <bits/stdc++.h>

const int N = 100000 + 10;

inline void cmax(int &a, int b) { if (a < b) a = b; }

int n, y, k, x;
int64_t kpow[N], kinv[N], v[N];
std::vector<int> e[N];

int64_t in[N], out[N];

int size[N], ms[N];
bool flag[N];

std::vector<int> q;

inline int64_t pow(int64_t base, int64_t exp) {
  int64_t res = 1;
  for (; exp; exp >>= 1) {
    if (exp & 1) (res *= base) %= y;
    (base *= base) %= y;
  }
  return res;
}

void calsize(int a, int fa = 0) {
  size[a] = 1, ms[a] = 0, q.push_back(a);
  for (auto b : e[a]) {
    if (!flag[b] && b != fa) {
      calsize(b, a);
      size[a] += size[b];
      ms[a] = std::max(ms[a], size[b]);
    }
  }
}

int centroid(int root) {
  q.clear();
  calsize(root);
  int res = root, best = ms[root];
  for (auto it : q) {
    int cur = std::max(size[root] - size[it], ms[it]);
    if (cur < best) best = cur, res = it;
  }
  return res;
}

int dep[N];
int64_t df[N], dt[N], target[N];

void caldist(int a, int fa = 0) {
  for (auto b : e[a]) {
    if (!flag[b] && b != fa) {
      dep[b] = dep[a] + 1;
      dt[b] = (dt[a] + v[b] * kpow[dep[b]]) % y;
      df[b] = (df[a] * k + v[b]) % y;
      caldist(b, a);
    }
  }
}

std::vector<int> pool[N];

void dfs(int a, const int root, int fa = 0) {
  pool[root].push_back(a);
  for (auto b : e[a])
    if (!flag[b] && b != fa)
      dfs(b, root, a);
}

inline void solve() {
  static std::unordered_map<int64_t, int> from, to;
  from.clear(), to.clear();
  for (auto a : q) for (auto it : pool[a]) from[target[it]]++, to[dt[it]]++;
  for (auto a : q) {
    for (auto it : pool[a]) from[target[it]]--, to[dt[it]]--;
    for (auto it : pool[a]) in[it] += from[dt[it]], out[it] += to[target[it]];
    for (auto it : pool[a]) from[target[it]]++, to[dt[it]]++;
  }
}

void divide(int root) {
  root = centroid(root);
  flag[root] = true, dt[root] = df[root] = v[root], dep[root] = 0;
  caldist(root);
  if (dt[root] == x) in[root]++, out[root]++;
  for (auto it : q) {
    if (it != root) {
      if (df[it] == x) in[root]++, out[it]++;
      if (dt[it] == x) out[root]++, in[it]++;
    }
  }
  q.clear();
  for (auto next : e[root]) {
    if (!flag[next]) {
      q.push_back(next);
      pool[next].clear();
      dfs(next, next);
      for (auto it : pool[next])
        target[it] = (((x - df[it]) * kinv[dep[it]] + v[root]) % y + y) % y;
    }
  }
  solve();
  for (auto next : e[root]) if (!flag[next]) divide(next);
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin >> n >> y >> k >> x;
  for (int i = 1; i <= n; ++i) std::cin >> v[i];
  for (int tmp = n - 1; tmp--;) {
    int u, v;
    std::cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  kpow[0] = kinv[0] = 1;
  for (int i = 1; i <= n; ++i) kinv[i] = pow(kpow[i] = kpow[i - 1] * k % y, y - 2);
  divide(1);
  int64_t ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += (int64_t)in[i] * (n - in[i]) * 2;
    ans += (int64_t)out[i] * (n - out[i]) * 2;
    ans += (int64_t)out[i] * (n - in[i]) + (int64_t)in[i] * (n - out[i]);
  }
  ans = (int64_t)n * n * n - ans / 2;
  std::cout << ans << std::endl;
  return 0;
}