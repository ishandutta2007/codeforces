#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int N, A, B;
    scanf("%d %d %d", &N, &A, &B);
    char buffer[N + 1];
    scanf("%s", buffer);
    string S = buffer;
    int answer = 1;
    for (int i = 1; i < N; ++i) {
      if (S[i] != S[i - 1]) {
        ++answer;
      }
    }
    answer = max(((answer + 2) >> 1) * B, N * B);
    answer += N * A;
    printf("%d\n", answer);
  }
}