#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

const int N = 200 + 10;

typedef long long i64;
typedef i64 Matrix[N][N];

int m, a[N];
i64 n;
char s[N];

Matrix adj;

struct {
  int next[26], fail, val;
} pool[N];

int tot = 1, root = 1;

void add(char s[], int v) {
  int u = root;
  for (char *it = s; *it != '\0'; ++it) {
    int ch = *it - 'a';
    if (!pool[u].next[ch]) pool[u].next[ch] = ++tot;
    u = pool[u].next[ch];
  }
  pool[u].val += v;
}

void build() {
  static std::queue<int> q;
  q.push(root);
  while (!q.empty()) {
    int a = q.front();
    q.pop();
    pool[a].val += pool[pool[a].fail].val;
    for (int i = 0; i < 26; ++i) {
      int &b = pool[a].next[i];
      (b ? (q.push(b), pool[b].fail) : b) = (a == root) ? root : pool[pool[a].fail].next[i];
    }
  }
  memset(adj, -0x3f, sizeof adj);
  for (int a = 1; a <= tot; ++a) adj[a][a] = 0;
  for (int a = 1; a <= tot; ++a) {
    for (int i = 0; i < 26; ++i) {
      int b = pool[a].next[i];
      adj[a][b] = pool[b].val;
    }
  }
}

void mul(Matrix a, const Matrix b) {
  static Matrix c;
  memset(c, -0x3f, sizeof c);
  for (register int i = 1; i <= tot; ++i)
    for (register int k = 1; k <= tot; ++k)
      for (register int j = 1; j <= tot; ++j)
        c[i][j] = std::max(c[i][j], a[i][k] + b[k][j]);
  memcpy(a, c, sizeof c);
}

void power(Matrix base, i64 exp) {
  static Matrix res;
  memset(res, -0x3f, sizeof res);
  res[1][1] = 0;
  for (; exp; exp >>= 1) {
    if (exp & 1) mul(res, base);
    mul(base, base);
  }
  memcpy(base, res, sizeof res);
}

int main() {
  scanf("%d%lld", &m, &n);
  pool[root].fail = root;
  for (int i = 1; i <= m; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= m; ++i) {
    scanf(" %s", s);
    add(s, a[i]);
  }
  build();
  power(adj, n);
  printf("%lld\n", *std::max_element(adj[1] + 1, adj[1] + tot + 1));
  return 0;
}