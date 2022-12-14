#include <cctype>
#include <cstdio>
#include <iostream>
#include <algorithm>

typedef long long i64;

const int N = 1000 + 10, M = N * N, INF = 0x3f3f3f3f;

inline int nextInt() {
  char ch;
  while (!isdigit(ch = getchar())) {}
  int res = ch - '0';
  while (isdigit(ch = getchar())) res = 10 * res + ch - '0';
  return res;
}

struct Info {
  int x, y;
  Info() {}
  Info(int _x, int _y): x(_x), y(_y) {}
};

int n, a[N][N];
Info v;

inline int calc(int x, int y) {
  int numer = -(x + y), denom = v.x + v.y;
  return x * denom + numer * v.x;
}

#define pos(l, r) (((l) + (r)) | ((l) != (r)))

int tag[4 * M], min[4 * M];

inline void apply(int l, int r, int v) {
  int id = pos(l, r);
  if (v > tag[id]) tag[id] = v;
  if (v > min[id]) min[id] = v;
}

void release(int l, int r) {
  int id = pos(l, r), mid = (l + r) >> 1;
  if (tag[id]) {
    apply(l, mid, tag[id]);
    apply(mid + 1, r, tag[id]);
    tag[id] = 0;
  }
}

inline void update(int l, int r) {
  int mid = (l + r) >> 1, id = pos(l, r), rch = pos(mid + 1, r);
  min[id] = min[pos(l, mid)];
  if (min[rch] < min[id]) min[id] = min[rch];
}

int p, q, val, res;

void modify(int l, int r) {
  if (p <= l && r <= q) {
    apply(l, r, val);
    return;
  }
  int mid = (l + r) >> 1;
  release(l, r);
  if (p <= mid) modify(l, mid);
  if (q > mid) modify(mid + 1, r);
  update(l, r);
}

void query(int l, int r) {
  if (p <= l && r <= q) {
    res = std::min(res, min[pos(l, r)]);
    return;
  }
  int mid = (l + r) >> 1;
  release(l, r);
  if (p <= mid) query(l, mid);
  if (q > mid) query(mid + 1, r);
}

int sorted[2 * M], tot;

int binarySearch(int v) {
  int l = 1, r = tot;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (sorted[mid] >= v) r = mid; else l = mid + 1;
  }
  return l;
}

int main() {
  scanf("%d%d%d", &n, &v.x, &v.y);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      a[i][j] = nextInt();
  if (v.y < 0) {
    for (int i = 0; i < n; ++i) std::reverse(a[i], a[i] + n);
    v.y = -v.y;
  }
  if (v.x < 0) {
    for (int i = 0; i < n; ++i)
      for (int l = 0, r = n - 1; l < r; ++l, --r)
        std::swap(a[l][i], a[r][i]);
    v.x = -v.x;
  }
  static Info point[N][N];
  tot = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      sorted[++tot] = point[i][j].x = calc(i, j + 1);
      sorted[++tot] = point[i][j].y = calc(i + 1, j);
    }
  }
  std::sort(sorted + 1, sorted + tot + 1);
  tot = std::unique(sorted + 1, sorted + tot + 1) - sorted - 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      point[i][j].x = binarySearch(point[i][j].x);
      point[i][j].y = binarySearch(point[i][j].y);
    }
  }
  i64 ans = 0;
  for (int sum = 0; sum < 2 * n; ++sum) {
    for (int x = 0; x < n; ++x) {
      int y = sum - x;
      if (!(0 <= y && y < n)) continue;
      p = point[x][y].x, q = point[x][y].y - 1, res = INF;
      query(1, tot - 1);
      ans += std::max(a[x][y] - res, 0);
      val = a[x][y];
      modify(1, tot - 1);
    }
  }
  std::cout << ans << '\n';
  return 0;
}