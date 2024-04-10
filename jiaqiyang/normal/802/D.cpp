#include <cstdio>
#include <random>
#include <numeric>
#include <algorithm>

typedef long long i64;

const int K = 1000, N = 250;

inline i64 sqr(int x) { return (i64)x * x; }

i64 solve(int a[], int b[]) {
  i64 res = 0;
  for (int i = 0; i < N; ++i) res += sqr(a[i] - b[i]);
  return res;
}

int a[K + 1][N], b[K + 1][N], c[N];

void init() {
  std::random_device rd;
  std::mt19937 gen(rd());
  for (int i = 1; i <= K; ++i) {
    std::poisson_distribution<> d(i);
    for (int j = 0; j < N; ++j) a[i][j] = d(gen);
    std::uniform_int_distribution<> u(0, 2 * i);
    for (int j = 0; j < N; ++j) b[i][j] = u(gen);
    std::sort(a[i], a[i] + N);
    std::sort(b[i], b[i] + N);
  }
}

int main() {
  init();
  int tcase;
  for (scanf("%d", &tcase); tcase--;) {
    for (int i = 0; i < N; ++i) scanf("%d", &c[i]);
    std::sort(c, c + N);
    int avg = std::accumulate(c, c + N, 0) / N;
    int l = std::max(avg - 100, 10), r = std::min(avg + 100, 1000);
    std::pair<i64, int> p, q;
    p.first = q.first = 1LL << 62;
    for (int i = l; i <= r; ++i) p = std::min(p, {solve(a[i], c), i});
    for (int i = l; i <= r; ++i) q = std::min(q, {solve(b[i], c), i});
    puts(p < q ? "poisson" : "uniform");
  }
  return 0;
}