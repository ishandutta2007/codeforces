#include <cstdio>
#include <cstring>
#include <vector>

const int N = 200 + 10;
const int R = 1, G = 2, B = 4;

int mask[N][N][N];

int dfs(int r, int g, int b) {
  if (!r && !g && !b) return 0;
  if (!g && !b) return R;
  if (!g && !r) return B;
  if (!r && !b) return G;
  int &res = mask[r][g][b];
  if (res >= 0) return res;
  res = 0;
  if (r > 1) res |= dfs(r - 1, g, b);
  if (g > 1) res |= dfs(r, g - 1, b);
  if (b > 1) res |= dfs(r, g, b - 1);
  if (r && g) res |= dfs(r - 1, g - 1, b + 1);
  if (r && b) res |= dfs(r - 1, g + 1, b - 1);
  if (g && b) res |= dfs(r + 1, g - 1, b - 1);
  return res;
}

int main() {
  memset(mask, -1, sizeof mask);
  int n, r = 0, g = 0, b = 0;
  static char s[N];
  scanf("%d %s", &n, s);
  for (char *i = s; *i; ++i) if (*i == 'R') ++r; else if (*i == 'G') ++g; else ++b;
  int t = dfs(r, g, b);
  if (t & B) putchar('B');
  if (t & G) putchar('G');
  if (t & R) putchar('R');
  putchar('\n');
  return 0;
}