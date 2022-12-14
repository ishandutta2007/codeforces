#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

typedef long long i64;
typedef std::pair<i64, i64> Info;

const int N = 1000000 + 10;

int n, p[N];

Info bit[2 * N];

inline Info& operator+= (Info &lhs, const Info &rhs) {
  lhs.first += rhs.first;
  lhs.second += rhs.second;
  return lhs;
}

inline Info operator- (const Info &lhs, const Info &rhs) {
  return Info(lhs.first - rhs.first, lhs.second - rhs.second);
}

void add(int p, const Info &v) {
  for (; p < 2 * N; p += p & -p) bit[p] += v;
}

Info query(int p) {
  Info res(0, 0);
  for (; p; p ^= p & -p) res += bit[p];
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &p[i]), p[i] = p[i] - 1;
  static i64 cur[N];
  memset(bit, 0, sizeof bit);
  // abs(p[i] - i - -x)
  for (int i = 0; i < n; ++i) add(p[i] - i + N, {1, p[i] - i});
  for (int i = 0; i < n; ++i) {
    Info u = query(N - i), v = query(2 * N - 1) - u;
    cur[i] += -i * u.first - u.second;
    cur[i] += v.second + i * v.first;
    add(p[i] - i + N, {-1, -(p[i] - i)});
  }
  // abs(p[i] - i - n + x)
  memset(bit, 0, sizeof bit);
  for (int i = 0; i < n; ++i) {
    Info u = query(n - i + N), v = query(2 * N - 1) - u;
    cur[i] += (n - i) * u.first - u.second;
    cur[i] += v.second - (n - i) * v.first;
    add(p[i] - i + N, {1, p[i] - i});
  }
  Info ans((i64)N * N, N);
  for (int i = 0; i < n; ++i) ans = std::min(ans, {cur[i], (n - i) % n});
  printf("%lld %lld\n", ans.first, ans.second);
  return 0;
}