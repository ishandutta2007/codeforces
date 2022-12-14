#include <cstdio>
#include <vector>
#include <algorithm>

#define fst first
#define snd second

typedef long long i64;

const int N = 100000 + 10, MOD = 1000000007;

int n, k, a[N], ans;
int anc[N], size[N];

inline int Find(int x) { return anc[x] == x ? x : (anc[x] = Find(anc[x])); }

inline bool Union(int a, int b) {
  if ((a = Find(a)) == (b = Find(b))) return false;
  anc[a] = b;
  size[b] += size[a];
  return true;
}

inline int Pow(int base, int exp) {
  int res = 1;
  for (; exp; exp >>= 1) {
    if (exp & 1) res = (i64)res * base % MOD;
    base = (i64)base * base % MOD;
  }
  return res;
}

int cnt[N];
std::vector<int> pos;
std::vector<int> f[N], inv[N];

void DFS(int dep, int tot, int mx) {
  static std::vector<int> cur, g;
  if (dep == k) {
    if (mx < 3) {
      (++ans) %= MOD;
    } else {
      for (int i = 0; i < cur.size(); ++i) {
        tot = (i64)tot * inv[cnt[cur[i]]][cur[i]] % MOD;
        tot = (i64)tot * f[++cnt[cur[i]]][cur[i]] % MOD;
      }
      (ans += tot) %= MOD;
      for (int i = 0; i < cur.size(); ++i) --cnt[cur[i]];
    }
  } else {
    cur.push_back(size[pos[dep]]);
    g.push_back(1);
    DFS(dep + 1, tot, std::max(size[pos[dep]], mx));
    cur.pop_back();
    g.pop_back();
    for (int i = 0; i < cur.size(); ++i) {
      cur[i] += size[pos[dep]];
      ++g[i];
      DFS(dep + 1, (i64)tot * (g[i] - 1) % MOD, std::max(cur[i], mx));
      --g[i];
      cur[i] -= size[pos[dep]];
    }
  }
}

int main() {
  scanf("%d%d", &n, &k);
  static bool flag[N];
  static std::vector<int> val;
  static int order[N];
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    anc[i] = i;
    size[i] = 1;
    flag[a[i]] = true;
    if (!a[i]) pos.push_back(i);
  }
  for (int i = 0; i < k; ++i) order[pos[i]] = i;
  for (int i = 1; i <= n; ++i) if (!flag[i]) val.push_back(i);
  std::sort(val.begin(), val.end());
  for (int i = 1; i <= n; ++i) if (a[i] && !Union(i, a[i])) ++cnt[size[Find(i)]];
  int orig = 1, mx = 0;
  f[0].resize(n + 1, 1);
  inv[0].resize(n + 1, 1);
  for (int i = 1; i <= n; ++i) {
    f[i].resize(n / i + 1);
    inv[i].resize(n / i + 1);
    for (int j = 1; i * j <= n; ++j) {
      f[i][j] = (i64)j * f[i - 1][j] % MOD;
      if (i > 1) (f[i][j] += (i64)(i - 1) * j * f[i - 2][j] % MOD) %= MOD;
      inv[i][j] = Pow(f[i][j], MOD - 2);
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (cnt[i]) {
      mx = i;
      orig = (i64)orig * f[cnt[i]][i] % MOD;
    }
  }
  ans = 0;
  DFS(0, orig, mx);
  printf("%d\n", ans);
  return 0;
}