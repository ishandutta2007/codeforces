#include <cstdio>
#include <tuple>
#include <vector>
#include <algorithm>

typedef long long i64;

const int N = 50 + 10, n = 50, m = 36;

i64 t, f[N][N];

std::vector<std::tuple<int, int, int, int>> ans;

int main() {
  f[0][1] = 1;
  for (int i = 1; i < N; ++i)
    for (int j = 1; j < N; ++j)
      f[i][j] = f[i - 1][j] + f[i][j - 1];
  scanf("%lld", &t);
  if (t < 3) {
    printf("%lld %lld\n0\n", t, t);
    return 0;
  }
  t -= 3;
  printf("%d %d\n", n, m);
  for (int i = 1; i <= n; ++i) if (!(i == 31 || i == 46 || i == 50)) ans.push_back(std::make_tuple(i, 35, i, 36));
  for (int i = 2; i < m; ++i) ans.push_back(std::make_tuple(31, i, 32, i)), ans.push_back(std::make_tuple(46, i, 47, i));
  std::vector<std::pair<i64, std::tuple<int, int, int, int>>> pool;
  for (int i = 1; i <= 30; ++i) pool.push_back(std::make_pair(f[i][34], std::make_tuple(i, 34, i, 35)));
  for (int i = 32; i <= 45; ++i) pool.push_back(std::make_pair(f[i - 31][34], std::make_tuple(i, 34, i, 35)));
  for (int i = 47; i <= 49; ++i) pool.push_back(std::make_pair(f[i - 46][34], std::make_tuple(i, 34, i, 35)));
  for (int i = 2; i <= 34; ++i) {
    pool.push_back(std::make_pair(f[30][i], std::make_tuple(30, i, 31, i)));
    pool.push_back(std::make_pair(f[14][i], std::make_tuple(45, i, 46, i)));
    pool.push_back(std::make_pair(f[3][i], std::make_tuple(49, i, 50, i)));
  }
  std::sort(pool.rbegin(), pool.rend());
  for (int i = 0; i < pool.size(); ++i) if (pool[i].first > t) ans.push_back(pool[i].second); else t -= pool[i].first;
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); ++i) printf("%d %d %d %d\n", std::get<0>(ans[i]), std::get<1>(ans[i]), std::get<2>(ans[i]), std::get<3>(ans[i]));
  return 0;
}