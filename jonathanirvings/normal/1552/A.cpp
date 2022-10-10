#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int N;
    scanf("%d", &N);
    char buffer[N + 1];
    scanf("%s", buffer);
    string S = buffer;
    string T = S;
    sort(T.begin(), T.end());
    int answer = 0;
    for (int i = 0; i < N; ++i) {
      if (S[i] != T[i]) {
        ++answer;
      }
    }
    printf("%d\n", answer);
  }
}