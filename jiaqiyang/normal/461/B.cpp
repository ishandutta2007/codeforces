#include <cstdio>
#include <cinttypes>
#include <vector>

const int N = 200000 + 10;
const int32_t MOD = 1e9 + 7;

inline void INC(int32_t &a, int32_t b) { a = ((int64_t)a + b) % MOD; }
inline void MUL(int32_t &a, int32_t b) { a = (int64_t)a * b % MOD; }
inline int32_t pdt(int32_t a, int32_t b) { return (int64_t)a * b % MOD; }

int n, col[N];
std::vector<int> e[N];

int32_t dp[N][2];

void dfs(int a) {
  //suppose it's a white point
  dp[a][0] = 1;
  dp[a][1] = 0;

  for (auto b : e[a]) {
    dfs(b);

    //keep this edge
    MUL(dp[a][1], dp[b][0]);
    INC(dp[a][1], pdt(dp[a][0], dp[b][1]));

    //cut this edge
    MUL(dp[a][0], dp[b][0]);
  }

  //now switch to its real color
  if (col[a]) dp[a][1] = dp[a][0]; else INC(dp[a][0], dp[a][1]);
}

int main() {
  scanf("%d", &n);
  for (int i = 2; i <= n; ++i) {
    int p;
    scanf("%d", &p);
    e[++p].push_back(i);
  }
  for (int i = 1; i <= n; ++i) scanf("%d", col + i);
  dfs(1);
  printf("%" PRId32 "\n", dp[1][1]);
  return 0;
}