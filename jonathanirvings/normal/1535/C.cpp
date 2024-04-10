#include <bits/stdc++.h>
using namespace std;

constexpr int kMaxLen = 200000;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    char S[kMaxLen + 5];
    scanf("%s", S);

    int N = strlen(S);
    vector<vector<int>> last(2, vector<int>(2, N));
    int limit = N;
    long long answer = 0;
    for (int i = N - 1; i >= 0; --i) {
      if (S[i] != '?') {
        limit = min(limit, last[S[i] - '0'][i & 1 ^ 1]);
        limit = min(limit, last['1' - S[i]][i & 1]);
        last[S[i] - '0'][i & 1] = i;
      }
      answer += limit - i;
    }
    printf("%lld\n", answer);
  }
}