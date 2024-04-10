#include <cstdio>
#include <random>
#include <numeric>
#include <algorithm>

typedef long long i64;

const int K = 1000, N = 250;

inline i64 sqr(int x) { return (i64)x * x; }

i64 solve(int a[], int b[]) {
  i64 res = 0;
  for (int i = 0; i < 8 * N; ++i) res += sqr(a[i] - b[i]);
  return res;
}

int a[K + 1][8 * N], b[K + 1][8 * N], c[8 * N];

void init() {
  std::random_device rd;
  std::mt19937 gen(rd());
  for (int i = 1; i <= K; ++i) {
    std::poisson_distribution<> d(i);
    for (int j = 0; j < 8 * N; ++j) a[i][j] = d(gen);
    std::uniform_int_distribution<> u(0, 2 * i);
    for (int j = 0; j < 8 * N; ++j) b[i][j] = u(gen);
    std::sort(a[i], a[i] + 8 * N);
    std::sort(b[i], b[i] + 8 * N);
  }
}

int main() {
  init();
  int tcase;
  for (scanf("%d", &tcase); tcase--;) {
    static int temp[N];
    for (int i = 0; i < N; ++i) scanf("%d", &temp[i]);
    for (int i = 0; i < 8 * N; ++i) c[i] = temp[i / 8];
    std::sort(c, c + 8 * N);
    int avg = std::accumulate(c, c + 8 * N, 0) / 8. / N + .5;
    int l = std::max(avg - 50, 10), r = std::min(avg + 50, 1000);
    std::pair<i64, int> p, q;
    p.first = q.first = 1LL << 62;
    for (int i = l; i <= r; ++i) p = std::min(p, {solve(a[i], c), i});
    for (int i = l; i <= r; ++i) q = std::min(q, {solve(b[i], c), i});
    int ans;
    if (p < q) {
      ans = p.second;
    } else {
      ans = (q.second + avg + (c[8 * N - 1] + c[0]) / 2.) / 3. + .5;
      ans = std::max(ans, (c[8 * N - 1] + 1) / 2);
    }
    printf("%d\n", ans);
  }
  return 0;
}