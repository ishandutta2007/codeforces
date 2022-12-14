#include <cctype>
#include <stdio.h>
#include <map>
#include <algorithm>

typedef long long i64;

const int N = 300000 + 10;

int nextInt() {
  char ch;
  while (ch = getchar(), !isdigit(ch) && ch != '-') {}
  bool sig = (ch == '-' ? (ch = getchar(), true) : false);
  int res = ch - '0';
  while (isdigit(ch = getchar())) res = 10 * res + ch - '0';
  return sig ? -res : res;
}

struct Info {
  int x, y;
  Info() {}
  Info(int _x, int _y): x(_x), y(_y) {}
  inline bool operator< (const Info &rhs) const {
    return x > rhs.x || (x == rhs.x && y < rhs.y);
  }
};

template <typename T> inline void check(T &lhs, const T &rhs) { lhs = (lhs < rhs ? lhs : rhs); }

int n, a[N], b[N], c[N];

int x[N], y[N], z[N];

void solve(const int cur[], int res[]) {
  std::map<i64, int> last;
  last[0] = n;
  res[n] = n + 1;
  i64 sum = 0;
  for (int i = n - 1; i >= 0; --i) {
    res[i] = res[i + 1];
    if (last.count(sum += cur[i])) check(res[i], last[sum]);
    last[sum] = i;
  }
}

int main() {
  n = nextInt();
  for (int i = 0; i < n; ++i) a[i] = nextInt();
  for (int i = 0; i < n; ++i) b[i] = nextInt();
  for (int i = 0; i < n; ++i) c[i] = a[i] + b[i];
  solve(a, x);
  solve(b, y);
  solve(c, z);
  static Info f[N], g[N];
  for (int i = 0; i <= n; ++i) {
    check(f[x[g[i].y]], Info(g[i].x + 1, i));
    check(g[y[f[i].y]], Info(f[i].x + 1, i));
    check(f[x[i]], Info(f[i].x + 1, f[i].y));
    check(g[y[i]], Info(g[i].x + 1, g[i].y));
    Info info(std::max(f[i].x, g[i].x) + 1, z[i]);
    check(f[z[i]], info);
    check(g[z[i]], info);
    check(f[i + 1], f[i]);
    check(g[i + 1], g[i]);
  }
  printf("%d\n", std::max(f[n].x, g[n].x));
  return 0;
}