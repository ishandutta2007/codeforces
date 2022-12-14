#include <bits/stdc++.h>

typedef long long int64;

const int P = 100 + 1, N = 3000000;

inline void cmin(int &a, int b) { if (b < a) a = b; }

int l, r, p;

std::vector<int> prime, pool;

inline void preprocessing(int n) {
  static bool flag[P];
  for (int i = 2; i <= n; ++i) {
    if (!flag[i]) prime.push_back(i);
    for (int j = 0; j < prime.size() && i * prime[j] <= n; ++j) {
      flag[i * prime[j]] = true;
      if (i % prime[j] == 0) break;
    }
  }
}

int lim;

void DFS(int dep, int cur) {
  pool.push_back(cur);
  for (int i = dep; i < prime.size(); ++i) {
    if ((int64)cur * prime[i] > r) break;
    DFS(i, cur * prime[i]);
  }
}

int Solve() {
  lim = r;
  pool.clear();
  DFS(0, 1);
  std::sort(pool.begin(), pool.end());
  static int mem[N];
  static bool flag[N];
  memset(mem, 0x3f, sizeof mem);
  mem[0] = 0;
  for (int i = 1; i <= p; ++i) {
    for (int j = 0, pos = 0; j < pool.size(); ++j) {
      while (pos < pool.size() && pool[pos] < pool[j] * i) ++pos;
      flag[j] |= (++mem[j] <= p);
      if (pos < pool.size() && pool[j] * i == pool[pos]) cmin(mem[pos], mem[j]);
    }
  }
  int res = 0;
  for (int i = 0; i < pool.size(); ++i) res += (l <= pool[i] && flag[i]);
  return res;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif
  scanf("%d%d%d", &l, &r, &p);
  preprocessing(p);
  printf("%d\n", Solve());
  return 0;
}