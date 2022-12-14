#include <cstdio>
#include <map>
#include <vector>
#include <numeric>
#include <algorithm>

typedef long long i64;

const int N = 200000 + 10;

i64 gcd(i64 a, i64 b) { return b ? gcd(b, a % b) : a; }

int mod;
i64 sum;
std::vector<i64> a;

std::map<i64, i64> ans;

void init() {
  int cnt;
  std::vector<int> b;
  for (scanf("%d%d", &mod, &cnt); cnt--;) {
    int x;
    scanf("%d", &x);
    b.push_back(x);
  }
  sum = std::accumulate(b.begin(), b.end(), 0LL);
  a.resize(b.size());
  for (int i = 1; i < b.size(); ++i) a[i] = a[i - 1] + b[i];
}

void exgcd(i64 a, i64 b, i64 &x, i64 &y) {
  if (!b) {
    x = 1, y = 0;
    return;
  }
  exgcd(b, a % b, y, x);
  y -= a / b * x;
}

int inv(i64 a, int mod) {
  i64 x, y;
  exgcd(a, mod, x, y);
  return (x % mod + mod) % mod;
}

void solve(int a, const std::vector<i64> &val) {
  int t = inv(sum % mod, mod);
  std::vector<std::pair<int, i64>> cur;
  for (auto x : val) {
    //x - k = y * s (mod m)
    cur.emplace_back(((x - a) % mod * t % mod + mod) % mod, -x);
  }
  std::sort(cur.begin(), cur.end());
  for (int i = 1; i < cur.size(); ++i) ans[-cur[i - 1].second] = cur[i].first - cur[i - 1].first;
  ans[-cur.back().second] = mod - cur.back().first + cur[0].first;
}

int main() {
  init();
  int t = gcd(sum, mod);
  std::vector<std::pair<int, i64>> pool;
  for (auto x : a) pool.emplace_back(x % t, x);
  std::sort(pool.begin(), pool.end());
  for (int i = 0; i < pool.size();) {
    std::vector<i64> b;
    int k = pool[i].first;
    for (; i < pool.size() && pool[i].first == k; ++i) b.emplace_back(pool[i].second);
    solve(k, b);
  }
  for (auto x : a) printf("%lld ", ans[x] / t);
  return 0;
}