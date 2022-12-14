#include <cctype>
#include <ctime>
#include <stdio.h>
#include <cstdlib>
#include <algorithm>

const int N = 50000 + 10, M = 100000 + 10, T = 1000000 + 10, S = 20;

int nextInt() {
  char ch;
  while (!isdigit(ch = getchar())) {}
  int res = ch - '0';
  while (isdigit(ch = getchar())) res = 10 * res + ch - '0';
  return res;
}

int n, m, tot, a[M], b[M], l[N], t[N][S];

int colA[T];

void genA() {
  for (int i = 1; i <= tot; ++i) colA[i] = rand() & 1;
}

bool checkA() {
  for (int i = 1; i <= n; ++i) {
    int mask = 0;
    for (int j = 0; j < l[i]; ++j) mask |= 1 << colA[t[i][j]];
    if (mask != 3) return false;
  }
  return true;
}

int colB[N];

void genB() {
  for (int i = 1; i <= n; ++i) colB[i] = rand() & 1;
}

bool checkB() {
  int cnt = 0;
  for (int i = 1; i <= m; ++i) if (colB[a[i]] != colB[b[i]]) ++cnt;
  if (2 * cnt >= m) {
    return true;
  } else {
    return false;
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) a[i] = nextInt(), b[i] = nextInt();
  tot = 0;
  for (int i = 1; i <= n; ++i) {
    l[i] = nextInt();
    for (int j = 0; j < l[i]; ++j) tot = std::max(tot, t[i][j] = nextInt());
  }
  srand(time(0));
  for (genA(); !checkA();) genA();
  for (genB(); !checkB();) genB();
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < l[i]; ++j) {
      if (colA[t[i][j]] == colB[i]) {
        printf("%d", t[i][j]);
        putchar(i == n ? '\n' : ' ');
        break;
      }
    }
  }
  for (int i = 1; i <= tot; ++i) {
    putchar(colA[i] + '1');
    putchar(i == tot ? '\n' : ' ');
  }
  return 0;
}