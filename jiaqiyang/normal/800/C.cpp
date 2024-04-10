#include <cstdio>
#include <vector>
#include <algorithm>

typedef long long i64;

const int N = 200000 + 10;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int m;

bool flag[N];

void init() {
  int n;
  scanf("%d%d", &n, &m);
  while (n--) {
    int a;
    scanf("%d", &a);
    if (a == 0) a = m;
    flag[a] = true;
  }
}

void exgcd(int a, int b, int &x, int &y) {
  if (!b) {
    x = 1, y = 0;
    return;
  }
  exgcd(b, a % b, y, x);
  y -= a / b * x;
}

int f[N], mem[N];
std::pair<int, int> g[N];

std::vector<int> ans;

int solve(int a, int b) {
  //  b * x \equiv a (mod m)
  int x, y;
  exgcd(b, m, x, y);
  return (i64)a / mem[b] * x % m;
}

int main() {
  init();
  static int d[N], pos[N];
  int tot = 0;
  for (int i = 1; i <= m; ++i) if (m % i == 0) d[++tot] = i, pos[i] = tot;
  for (int i = 1; i <= m; ++i) mem[i] = gcd(i, m);
  for (int i = 1; i <= m; ++i) if (!flag[i]) ++f[pos[mem[i]]];
  for (int i = 1; i <= tot; ++i)
    for (int j = i + 1; j <= tot; ++j)
      if (d[j] % d[i] == 0) g[j] = std::max(g[j], std::make_pair(g[i].first + f[i], i));
  for (int i = tot; i; i = g[i].second)
    for (int j = 1; j <= m; ++j)
      if (!flag[j] && pos[mem[j]] == i) ans.push_back(j);
  std::reverse(ans.begin(), ans.end());
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); ++i) printf("%d ", (solve(ans[i], i ? ans[i - 1] : 1) % m + m) % m);
  return 0;
}