#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int N;
    scanf("%d", &N);
    long long sum = 0;
    for (int i = 0; i < N; ++i) {
      int A;
      scanf("%d", &A);
      sum += A;
    }
    sum %= N;
    printf("%lld\n", sum * (N - sum));
  }
}