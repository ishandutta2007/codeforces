#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int N, M;
    scanf("%d %d", &N, &M);
    string answer(M, 0);
    for (int i = 0; i < 2 * N - 1; ++i) {
      char buffer[M + 1];
      scanf("%s", buffer);
      for (int j = 0; j < M; ++j) {
        answer[j] ^= buffer[j];
      }
    }
    printf("%s\n", answer.c_str());
  }
}