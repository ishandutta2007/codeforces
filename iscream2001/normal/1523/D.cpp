/* Lucky_Glass */
#include <cstdio>
#include <cstring>
#include <algorithm>

#define CON(typ) const typ &

const int N = 2e5 + 10, M = 70, P = 15;

std::default_random_engine engine;
int n, m, np, ans_siz;
int dp[(1 << P) + 10], pcnt[(1 << P) + 10];
char like[N][M];
bool ans[M];

void doDP(CON(int) bas) {
  int now[20] = {}, now_cnt = 0;
  for (int i = 0; i < m; ++i)
    if (like[bas][i] == '1')
      now[now_cnt++] = i;
  const int LIMIT_S = 1 << now_cnt;
  for (int s = 0; s < LIMIT_S; ++s)
    dp[s] = 0;
  for (int i = 1; i <= n; ++i) {
    int si = 0;
    for (int j = 0; j < now_cnt; ++j)
      if (like[i][now[j]] == '1')
        si |= 1 << j;
    ++dp[si];
  }
  for (int i = 0; i < now_cnt; ++i)
    for (int s = 0; s < LIMIT_S; ++s)
      if (s >> i & 1)
        dp[s ^ (1 << i)] += dp[s];
  const int LEAST = (n + 1) >> 1;
  for (int s = 0; s < LIMIT_S; ++s)
    if (dp[s] >= LEAST && pcnt[s] > ans_siz) {
      ans_siz = pcnt[s];
      for (int i = 0; i < m; ++i) ans[i] = false;
      for (int i = 0; i < now_cnt; ++i)
        if (s >> i & 1)
          ans[now[i]] = true;
    }
}
void init() {
  for (int i = 1, lmt_i = 1 << P; i < lmt_i; ++i)
    pcnt[i] = pcnt[i ^ (i & -i)] + 1;
}
int main() {
  init();
  engine.seed(131619);
  scanf("%d%d%d", &n, &m, &np);
  for (int i = 1; i <= n; ++i) scanf("%s", like[i]);
  std::uniform_int_distribution<int> rd_index(1, n);
  for (int t = 1; t <= 50; ++t) doDP(rd_index(engine));
  for (int i = 0; i < m; ++i) putchar('0' ^ ans[i]);
  putchar('\n');
  return 0;
}