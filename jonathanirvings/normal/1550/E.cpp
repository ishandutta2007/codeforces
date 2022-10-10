#include <bits/stdc++.h>
using namespace std;

constexpr char kWildCard = '?';

bool is_possible(int N, int K, const string& S, int M) {
  vector<vector<int>> ends_at(K, vector<int>(N, N));
  for (int k = 0; k < K; ++k) {
    int invalid_char = 0;
    for (int j = N - 1; j >= N - M; --j) {
      if (S[j] != kWildCard && S[j] - 'a' != k) {
        ++invalid_char;
      }
    }
    if (invalid_char == 0) {
      ends_at[k][N - M] = N - 1;
    }
    for (int j = N - M - 1; j >= 0; --j) {
      if (S[j] != kWildCard && S[j] - 'a' != k) {
        ++invalid_char;
      }
      if (S[j + M] != kWildCard && S[j + M] - 'a' != k) {
        --invalid_char;
      }
      ends_at[k][j] = (invalid_char == 0) ? (j + M - 1) : (ends_at[k][j + 1]);
    }
  }
  vector<int> dp(1 << K, N);
  dp[0] = -1;
  for (int bit = 1; bit < (1 << K); ++bit) {
    for (int i = 0; i < K; ++i) {
      if (bit & (1 << i)) {
        if (dp[bit ^ (1 << i)] + 1 < N) {
          dp[bit] = min(dp[bit], ends_at[i][dp[bit ^ (1 << i)] + 1]);
        }
      }
    }
  }
  return dp[(1 << K) - 1] < N;
}

int main() {
  int N, K;
  scanf("%d %d", &N, &K);
  char buffer[N + 1];
  scanf("%s", buffer);
  string S = buffer;

  int L = 1;
  int R = N;
  int answer = 0;
  while (L <= R) {
    int M = (L + R) >> 1;
    if (is_possible(N, K, S, M)) {
      answer = M;
      L = M + 1;
    } else {
      R = M - 1;
    }
  }
  printf("%d\n", answer);
}