#include <cstdio>
#include <cstring>
#include <vector>

typedef long long i64;

const int N = 20, M = 6, K = 5;

int n, a[N];

int f[N][K], g[N][K];

struct Tuple {
  int a, b;
  Tuple() {}
  Tuple(int _a, int _b): a(_a), b(_b) {}
  inline int sum() { return 7 * a + 4 * b; }
};

std::vector<Tuple> tuple;

void init() {
  for (int a = 0; a <= M; ++a)
    for (int b = 0; a + b <= M; ++b)
      tuple.push_back(Tuple(a, b));
}

char s[M][N];

void print(int n, int k) {
  if (!n) return;
  const Tuple &t = tuple[g[n][k]];
  for (int i = 0; i < t.a; ++i) s[i][n - 1] = '7';
  for (int i = 0; i < t.b; ++i) s[t.a + i][n - 1] = '4';
  for (int i = t.a + t.b; i < M; ++i) s[i][n - 1] = '0';
  print(n - 1, f[n][k]);
}

void write(char *num) {
  int t = strlen(num);
  while (t && num[t - 1] == '0') --t;
  for (int i = t - 1; i >= 0; --i) putchar(num[i]);
  if (!t) putchar('0');
  putchar(' ');
}

void solve() {
  memset(f, -1, sizeof f);
  f[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < K; ++j) {
      int cur = f[i][j];
      if (cur == -1) continue;
      for (int k = 0; k < tuple.size(); ++k) {
        int t = tuple[k].sum() + j;
        if (t % 10 != a[i]) continue;
        f[i + 1][t / 10] = j;
        g[i + 1][t / 10] = k;
      }
    }
  }
  if (f[n][0] != -1) {
    memset(s, 0, sizeof s);
    print(n, 0);
    for (int j = 0; j < M; ++j) write(s[j]);
    putchar('\n');
  } else {
    puts("-1");
  }
}

int main() {
  init();
  int tcase;
  for (scanf("%d", &tcase); tcase--;) {
    i64 x;
    scanf("%lld", &x);
    n = 0;
    for (; x; x /= 10) a[n++] = x % 10;
    solve();
  }
  return 0;
}