#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 256;

int n, a[N], l[N], r[N];

int size[N];

void dfs(int x) {
  if (a[x] != -1) {
    size[x] = 0;
    return;
  }
  dfs(l[x]);
  dfs(r[x]);
  size[x] = size[l[x]] + size[r[x]] + 1;
  if (size[r[x]] & 1) std::swap(l[x], r[x]);
}

inline int merge(int lhs, int rhs, int dir) { return ((lhs < rhs) ^ dir) ? rhs : lhs; }

int mem[N][2][3];

int solve(int x, int y, int z) {
  if (a[x] != -1) return a[x];
  if (size[x] == 1) return merge(a[l[x]], a[r[x]], y ^ (z == 2));
  int &res = mem[x][y][z];
  if (res != -1) return res;
  if (z) {
    res = solve(x, !y, 0);
    if (size[x] & 1) {
      if (size[l[x]] & 1) {
        res = merge(res, merge(solve(l[x], y, 0), solve(r[x], !y, size[l[x]] == 1 && z == 1 ? 2 : 1), !y), y);
        res = merge(res, merge(solve(r[x], y, 0), solve(l[x], !y, size[r[x]] == 1 && z == 1 ? 2 : 1), !y), y);
      } else {
        if (size[l[x]]) res = merge(res, merge(solve(r[x], !y, 0), solve(l[x], y, size[r[x]] == 0 && z == 1 ? 2 : 1), !y), y);
        if (size[r[x]]) res = merge(res, merge(solve(l[x], !y, 0), solve(r[x], y, size[l[x]] == 0 && z == 1 ? 2 : 1), !y), y);
      }
    } else {
      res = merge(res, merge(solve(r[x], y, 0), solve(l[x], y, size[r[x]] == 0 && z == 1 ? 2 : 1), y), y);
    }
  } else {
    if (size[x] & 1) {
      int s = size[l[x]] & 1;
      res = merge(solve(l[x], y, s), solve(r[x], y, s), y);
    } else {
      res = merge(merge(solve(l[x], y, 0), solve(r[x], !y, 0), !y), merge(solve(l[x], !y, 1), solve(r[x], y, 1), !y), y);
    }
  }
  return res;
}

int main() {
  int tcase;
  for (scanf("%d", &tcase); tcase--;) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
      if (a[i] == -1) scanf("%d%d", &l[i], &r[i]);
    }
    dfs(0);
    memset(mem, -1, sizeof mem);
    printf("%d\n", solve(0, 0, 0));
  }
  return 0;
}