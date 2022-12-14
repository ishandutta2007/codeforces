#include <map>
#include <iostream>
#include <algorithm>

#define fst first
#define snd second

typedef long long i64;
typedef unsigned long long u64;
typedef std::pair<i64, i64> Info;

const int N = 19;

i64 mem[N];

std::map<Info, Info> pool;

Info dfs(i64 hi, i64 n) {
  if (n < 10) {
    hi = std::max(hi, n);
    return hi ? Info(1, n - hi) : Info(0, 0);
  }
  Info &res = pool[Info(hi, n)];
  if (res.fst) return res;
  i64 t = 1;
  while (10ULL * t <= (u64)n) t *= 10;
  i64 a = n / t, b = n % t;
  Info temp = dfs(std::max(hi, a), b);
  res.fst += temp.fst;
  temp = dfs(hi, n - b + temp.snd);
  res.fst += temp.fst;
  res.snd += temp.snd;
  return res;
}

int main() {
  mem[0] = 1;
  for (int i = 1; i < N; ++i) mem[i] = 10 * mem[i - 1];
  i64 n;
  std::cin >> n;
  std::cout << dfs(0, n).fst << '\n';
  return 0;
}