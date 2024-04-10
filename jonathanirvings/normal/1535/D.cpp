#include <bits/stdc++.h>
using namespace std;

void update(vector<int> &dp, const char *S, int u) {
  dp[u] = 0;
  if (S[u] != '0') {
    dp[u] += dp[(u << 1) + 1];
  }
  if (S[u] != '1') {
    dp[u] += dp[(u << 1) + 2];
  }
}

int main() {
  int K;
  scanf("%d", &K);

  char S[1 << K];
  scanf("%s", S);

  reverse(S, S + (1 << K) - 1);
  vector<int> dp(1 << (K + 1), 1);

  for (int i = (1 << K) - 2; i >= 0; --i) {
    update(dp, S, i);
  }

  int Q;
  scanf("%d", &Q);
  while (Q--) {
    int P;
    char C;
    scanf("%d %c", &P, &C);
    P = (1 << K) - 1 - P;
    S[P] = C;
    do {
      update(dp, S, P);
      P = (P - 1) >> 1;
    } while (P > 0);
    update(dp, S, 0);
    printf("%d\n", dp[0]);
  }
}