#include <cctype>
#include <stdio.h>
#include <cstring>
#include <algorithm>

typedef int Matrix[5][5];

const int N = 200000 + 10, INF = 0x3f3f3f3f;

int nextInt() {
  char ch;
  while (!isdigit(ch = getchar())) {}
  int res = ch - '0';
  while (isdigit(ch = getchar())) res = 10 * res + ch - '0';
  return res;
}

int n, m;
char s[N];

inline int pos(int l, int r) { return (l + r) | (l != r); }

Matrix info[2 * N];

void merge(Matrix res, const Matrix lhs, const Matrix rhs) {
  memset(res, 0x3f, sizeof(Matrix));
  for (register int i = 0; i <= 4; ++i)
    for (register int k = i; k <= 4; ++k)
      for (register int j = i > k ? i : k; j <= 4; ++j)
        res[i][j] = std::min(res[i][j], lhs[i][k] + rhs[k][j]);
}

const char t[] = "2017";

void build(int l, int r) {
  if (l == r) {
    int id = pos(l, r);
    memset(info[id], 0x3f, sizeof(Matrix));
    for (int i = 0; i <= 4; ++i) {
      if (i >= 3 && s[l] == '6') {
        info[id][i][i] = 1;
        continue;
      }
      if (i < 4 && s[l] == t[i]) info[id][i][i + 1] = 0;
      info[id][i][i] = (s[l] == t[i]);
    }
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid);
  build(mid + 1, r);
  merge(info[pos(l, r)], info[pos(l, mid)], info[pos(mid + 1, r)]);
}

int ans[5];

void query(int l, int r, int p, int q) {
  if (p <= l && r <= q) {
    int id = pos(l, r);
    static int temp[5];
    memset(temp, 0x3f, sizeof temp);
    for (register int i = 0; i <= 4; ++i)
      for (register int j = i; j <= 4; ++j)
        temp[j] = std::min(temp[j], ans[i] + info[id][i][j]);
    memcpy(ans, temp, sizeof temp);
    return;
  }
  int mid = (l + r) >> 1;
  if (p <= mid) query(l, mid, p, q);
  if (q > mid) query(mid + 1, r, p, q);
}

int main() {
  scanf("%d%d %s", &n, &m, s + 1);
  build(1, n);
  for (int i = 1; i <= m; ++i) {
    int l = nextInt(), r = nextInt();
    memset(ans, 0x3f, sizeof ans);
    ans[0] = 0;
    query(1, n, l, r);
    printf("%d\n", ans[4] == INF ? -1 : ans[4]);
  }
  return 0;
}