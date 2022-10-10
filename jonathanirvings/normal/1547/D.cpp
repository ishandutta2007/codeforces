#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int N;
    scanf("%d", &N);
    int lst = 0;
    for (int i = 0; i < N; ++i) {
      int X;
      scanf("%d", &X);
      printf("%d%c", lst & (~X), " \n"[i == N - 1]);
      lst = X | lst;
    }
  }
}